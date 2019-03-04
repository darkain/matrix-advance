/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/gbaInlines.h>
#include <vArm/tools/gbaStringx.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/phishie/gbaPhishie.h>
#include <vArm/irq/gbaInterupt.h>
/*
#include <vArm/gbaTimer.h>
#include <vArm/gbaMultiboot.h>
#include <vArm/irq/gbaInterupt.h>
#include <vArm/sprites/gbaSprites.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/


//my current project
#include "entry.h"
#include "engine.h"

#include "pauseEndless.h"

#include "switchTile.h"
#include "flipTile.h"
#include "linker.h"
#include "cluster.h"
#include "streak.h"

#include "../screens/faces.h"
#include "../screens/scrFinishGame.h"
#include "../menu/mnuMain.h"

//resources
#include "../resources.h"


MatrixEngine *engine = NULL;
u8 *matrixTile;


u16 *tilesLeft[16][5];
u16 *tilesRight[16][5];
u16 extLeftCoordX[16][5];
u16 extLeftCoordY[16][5];
u16 extRightCoordX[16][5];
u16 extRightCoordY[16][5];


MatrixEngine::MatrixEngine(s8 playerProfile) : irqInput(true) {
	ASSERT(engine == NULL);
	engine = this;
	paused = true;

//  interupt.setMasterIRQ(false);
  seconds = 1;

  ASSERT(interupt.getMasterIRQ()==false);

	screen.setBgEnabled(background2, false);
	screen.setScreenMode(mode3);
	REG_BG2CNT |= 0x0003;  //should make functions for these in gbaDisplay

	dma3fill_32(0, (u32*)screen.getDisplay(), ((240*160)>>1));

//	if (REG_TM3D == 0) setSeed(1);
//	else setSeed(REG_TM3D);  //gotta add this to teh function

	for (int i2=0; i2<16; i2++) {
		for (int i1=0; i1<5; i1++) {
			map1[i2][i1] = 0;
			map2[i2][i1] = 0;
			locked[i2][i1] = 0;
		}
	}

	save = false;
	width = 5;
	height = 16;

	flipTile = NULL;
	switchTile = NULL;

	buildPointers();

  combo = 0;
	maxCombo = 0;
	totalCombo = 0;

	profile = playerProfile;
	streak = NULL;

	face = NULL;

	loadProfile();

	drawBackground();

	phishie = new gbaPhishie(37,2,76,13);
	cursor = new vCursor();

	screen.drawString("Active", 91, 143, RGB(25,25,25));
	screen.drawString("Passive", 168, 143, RGB(20,20,20));


	{
		const u8 *data = matrixhline;
		const u8 *end = matrixhline + sizeof(matrixhline);
		while (data < end) {
			screen.hLine(data[0], data[1], data[2]);
			data += 3;
		}
	}

	{
		const u8 *data = matrixvline;
		const u8 *end = matrixvline + sizeof(matrixvline);
		while (data < end) {
			screen.vLine(data[0], data[1], data[2]);
			data += 3;
		}
	}

	{
		const u8 *data = matrixpset;
		const u8 *end = matrixpset + sizeof(matrixpset);
		while (data < end) {
			screen.pSet(data[0], data[1]);
			data += 2;
		}
	}

	screen.setObjectPaletteEntry(34, RGB(0,31,0));
	lvSprite = new vSprite(Lv_gfx, 2, 2, 1, 0, false, 2);
//	dma3_16(Lv_gfx, lvSprite->getData(), sizeof(Lv_gfx)>>1);
	lvSprite->move(41, 53);
	lvSprite->show();

	screen.setObjectPaletteEntry(37, RGB(0,31,31));
	timerSprite = new vSprite(Timer_gfx, 4, 4, 1, 1, false, 2);
//	dma3_16(Timer_gfx, timerSprite->getData(), sizeof(Timer_gfx)>>1);
	timerSprite->move(41, 16);
	timerSprite->show();

	screen.setObjectPaletteEntry(38, RGB(31,31,0));
	onepSprite = new vSprite(oneP_gfx, 2, 2, 1, 0, false, 2);
//	dma3_16(oneP_gfx, onepSprite->getData(), sizeof(oneP_gfx)>>1);
	onepSprite->move(10, 38);
	onepSprite->show();

	screen.setObjectPaletteEntry(36, RGB(0,0,31));
	strSprite = new vSprite(Str_gfx, 4, 4, 1, 1, false, 2);
//	dma3_16(Str_gfx, strSprite->getData(), sizeof(Str_gfx)>>1);
	strSprite->move(35, 38);
	strSprite->show();

	eakSprite = new vSprite(eak_gfx, 4, 4, 1, 1, false, 2);
//	dma3_16(eak_gfx, eakSprite->getData(), sizeof(eak_gfx)>>1);
	eakSprite->move(56, 38);
	eakSprite->show();

	screen.setObjectPaletteEntry(33, RGB(31,0,0));
	scoSprite = new vSprite(Sco_gfx, 4, 4, 1, 1, false, 2);
//	dma3_16(Sco_gfx, scoSprite->getData(), sizeof(Sco_gfx)>>1);
	scoSprite->move(3, 53);
	scoSprite->show();

	reSprite = new vSprite(re_gfx, 2, 2, 1, 0, false, 2);
//	dma3_16(re_gfx, reSprite->getData(), sizeof(re_gfx)>>1);
	reSprite->move(24, 53);
	reSprite->show();

	scoreData = new vSpriteData(score_gfx, 20);
//	dma3_16(score_gfx, scoreData->getData(), sizeof(score_gfx)>>1);

	streakZero[0] = new vSprite(scoreData, 20, 10, 0, 0, false, 4);
	streakZero[0]->move(54, 45);
	streakZero[0]->show();
	
	streakZero[1] = new vSprite(scoreData, 20, 10, 0, 0, false, 4);
	streakZero[1]->move(63, 45);
	streakZero[1]->show();

	streakZero[2] = new vSprite(scoreData, 20, 10, 0, 0, false, 4);
	streakZero[2]->move(70, 45);
	streakZero[2]->show();

	streakSep = new vSprite(scoreData, 20, 10, 0, 0, false, 4);
	streakSep->move(61, 45);
	streakSep->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(16));
	streakSep->show();

	screen.setObjectPaletteEntry(65, RGB(0,0,31));

	levelDisplay[0] = new vSprite(scoreData, 20, 10, 0, 0, false, 5);
	levelDisplay[0]->move(60, 53);
	levelDisplay[0]->show();

	levelDisplay[1] = new vSprite(scoreData, 20, 10, 0, 0, false, 5);
	levelDisplay[1]->move(68, 53);
	levelDisplay[1]->show();
	
	screen.setObjectPaletteEntry(81, RGB(0,31,0));

	for (int i=4; i>=0; i--) {
		scoreDisplay[i] = new vSprite(scoreData, 20, 10, 0, 0, false, 2);
		scoreDisplay[i]->move((i*7)+3, 46);
	}
	scoreDisplay[4]->show();

//	vSprite *timerSeconds[2];
//	vSprite *timerMinutes[3];
	timerMinutes[0] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerMinutes[0]->move(38, 22);
	timerMinutes[0]->show();

	timerMinutes[1] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerMinutes[1]->move(47, 22);
	timerMinutes[1]->show();

	timerMinutes[2] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerMinutes[2]->move(54, 22);
	timerMinutes[2]->show();

	timerSeconds[0] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerSeconds[0]->move(63, 22);
	timerSeconds[0]->show();

	timerSeconds[1] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerSeconds[1]->move(70, 22);
	timerSeconds[1]->show();

	timerSep[0] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerSep[0]->move(45, 22);
	timerSep[0]->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(16));
	timerSep[0]->show();

	timerSep[1] = new vSprite(scoreData, 20, 10, 0, 0, false, 3);
	timerSep[1]->move(61, 22);
	timerSep[1]->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(16));
	timerSep[1]->show();

	screen.setObjectPaletteEntry(49, RGB(0,31,31));

	if (playerProfile >= 0) {
		screen.drawString(scores.name, 37, 29, RGB(31,0,31));
	} else {
#ifdef _MULTIBOOT_
		screen.drawString("Plr 2", 37, 29, RGB(31,0,31));
#else//_MULTIBOOT_
		screen.drawString("Plr 1", 37, 29, RGB(31,0,31));
#endif//_MULTIBOOT_
	}

  resetScore();

  screen.setBgEnabled(background2, true);
	paused = false;
}


MatrixEngine::~MatrixEngine() {
	deleteEverything();

	vdelnull(cursor);
	vdelnull(phishie);

	vdelnull(lvSprite);
	vdelnull(timerSprite);
	vdelnull(onepSprite);
	vdelnull(strSprite);
	vdelnull(eakSprite);	
	vdelnull(scoSprite);
	vdelnull(reSprite);

	vdelnull(scoreData);
  for (int i=0; i<5; i++) { vdelnull(scoreDisplay[i]); }

  for (int i=0; i<2; i++) { vdelnull(timerSeconds[i]); }
  for (int i=0; i<3; i++) { vdelnull(timerMinutes[i]); }
  for (int i=0; i<2; i++) { vdelnull(timerSep[i]);     }

  for (int i=0; i<3; i++) { vdelnull(streakZero[i]);   }
	vdelnull(streakSep);

	vdelnull(face);

  for (int i=0; i<2; i++) { vdelnull(levelDisplay[i]); }

	engine = NULL;
}


void MatrixEngine::deleteEverything() {
	vdelnull(switchTile);
	vdelnull(flipTile);

	vLinker *linker = linkers.getFirstItem();
	while (linker) {
		delete linker;
		linkers.removeItem(linker);
		linker = linkers.getFirstItem();
	}

	vCluster *cluster = clusters.getFirstItem();
	while (cluster) {
		delete cluster;
		clusters.removeItem(cluster);
		cluster = clusters.getFirstItem();
	}

	vdelnull(streak);
/*
	vStreakCounter *counter = counters.getFirst();
	while (counter) {
		delete counter;
		counters.delItem(counter);
		counter = counters.getFirst();
	}
*/
}


void MatrixEngine::resetEngine() {
	resetScore();
	deleteEverything();
	paused = false;
}


void MatrixEngine::onStart() {
	new vPauseEndless();
}


void MatrixEngine::pause() {
	if (switchTile) switchTile->paintTiles();
	paused = true;
  print("engine paused\n");
}


void MatrixEngine::unPause() {
	if (switchTile) {
		switchTile->eraseTiles();
		refreshMatrix();
		switchTile->eraseTiles2();
	}
	paused = false;
  print("engine unpaused\n");
}


void MatrixEngine::setLevel(u8 l) {
	char str[8];
	level = l;
	intToString(l, str);

	if (l < 10) {
		levelDisplay[0]->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(0));
		levelDisplay[1]->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(str[0] - '0'));
	} else {
		levelDisplay[0]->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(str[0] - '0'));
		levelDisplay[1]->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(str[1] - '0'));
	}
}


void MatrixEngine::loadProfile() {
	u8 *dst = (u8*) &scores;

	if (profile == -1) {
		memset(dst, 0, sizeof(vScore));
		memcpy(scores.name, "Plr 1", 6);
		face = new gbaFace(3, 3, dice(1, 8));
		return;
	}

	u8 *src = (u8*) gameScores->getPlayer(profile);
	for (u32 i=0; i<sizeof(vScore); i++) dst[i] = src[i];

	scores.points = 0;
	scores.totalClusters = 0;
	scores.totalCombos = 0;
	scores.totalLinkers = 0;

	face = new gbaFace(3, 3, scores.face);
}



void MatrixEngine::onTimeout() {
#ifndef _MULTIBOOT_
//	vu32 score = points;
//	vs8 prof = profile;

	scores.maxCombo = maxCombo;
	scores.totalCombos = totalCombo;

	memcpy((void*)gameScores->getTempScore(), (void*)&scores, sizeof(vScore));


	delete this;

  {
  	gbaMenu *menu = new mnuMain();
    menu->buildList();
  }

//	new scrFinishGame(prof, gameScores->getTempScore());
/*
	if (prof == -1) {
		new gbaFinishGame(prof, gameScores->getTempScore());
	} else {
		new gbaFinishGame(prof, gameScores->getPlayer(prof));
	}
*/
#else//_MULTIBOOT_
	screen.lockScreen();
#endif//_MULTIBOOT_
 
}


void MatrixEngine::onMinute() {
	gbaSpriteEntry *entry = timerMinutes[0]->getSpriteEntry();
  ASSERT(entry!=NULL);
	entry->setDataId(scoreData->getDataIdOffset(minutes));
}


void MatrixEngine::onSecond() {
	gbaSpriteEntry *entry;

	int supSecond = (int)(seconds * 0.1);
	int subSecond = seconds - (supSecond * 10);
	
	entry = timerMinutes[2]->getSpriteEntry();
  ASSERT(entry!=NULL);
	entry->setDataId(scoreData->getDataIdOffset(subSecond));

	entry = timerMinutes[1]->getSpriteEntry();
  ASSERT(entry!=NULL);
	entry->setDataId(scoreData->getDataIdOffset(supSecond));
}


void MatrixEngine::onTenthSecond() {
	gbaSpriteEntry *entry = timerSeconds[0]->getSpriteEntry();
  ASSERT(entry!=NULL);
	entry->setDataId(scoreData->getDataIdOffset(tenthSecond));
}


void MatrixEngine::onVBlank() {
	if (paused) return;

	if (clearLinker()) increment();
	else decrement();

	int dataid;
	switch (hundrethSecond) {
		case 0: dataid = 0; break;
		case 1: dataid = 1; break;
		case 2: dataid = 3; break;
		case 3: dataid = 5; break;
		case 4: dataid = 6; break;
		case 5: dataid = 8; break;
	}

	gbaSpriteEntry *entry = timerSeconds[1]->getSpriteEntry();
  ASSERT(entry!=NULL);
	entry->setDataId(scoreData->getDataIdOffset(dataid));

	if (streak) streak->update();
}


void MatrixEngine::setPoints(u32 p) {
	points = p;
	if (p > 99999) p = 99999;

	if (points > scores.points) scores.points = points;

	char str[16];
	intToString(p, str);
	
	if (p > 9999) {
		for (int i=0; i<5; i++) {
			gbaSpriteEntry *entry = scoreDisplay[i+0]->getSpriteEntry();
			entry->setDataId(scoreData->getDataIdOffset(str[i] - '0'));
			entry->setDoublesize(false);
		}
	}

	else if (p > 999) {
		for (int i=0; i<4; i++) {
			gbaSpriteEntry *entry = scoreDisplay[i+1]->getSpriteEntry();
			entry->setDataId(scoreData->getDataIdOffset(str[i] - '0'));
			entry->setDoublesize(false);
		}
	}

	else if (p > 99) {
		for (int i=0; i<3; i++) {
			gbaSpriteEntry *entry = scoreDisplay[i+2]->getSpriteEntry();
			entry->setDataId(scoreData->getDataIdOffset(str[i] - '0'));
			entry->setDoublesize(false);
		}
	}

	else if (p > 9) {
		for (int i=0; i<2; i++) {
			gbaSpriteEntry *entry = scoreDisplay[i+3]->getSpriteEntry();
			entry->setDataId(scoreData->getDataIdOffset(str[i] - '0'));
			entry->setDoublesize(false);
		}
	}

	else {
		gbaSpriteEntry *entry = scoreDisplay[4]->getSpriteEntry();
		entry->setDataId(scoreData->getDataIdOffset(str[0] - '0'));
		entry->setDoublesize(false);
	}
}


void MatrixEngine::resetScore() {
	for (int i=0; i<5; i++) {
		gbaSpriteEntry *entry = scoreDisplay[i]->getSpriteEntry();
    ASSERTINT0(entry!=NULL, i);
		entry->setDoublesize(true);
		entry->setDataId(scoreData->getDataIdOffset(0));
	}
	setPoints(0);
}


void MatrixEngine::refreshMatrix() {
	for (int i2=0; i2<height; i2++) {
		for (int i1=0; i1<width; i1++) {
			drawTile1(i1, i2, map1[i2][i1]);
			drawTile2(i1, i2, map2[i2][i1]);
		}
	}
}



void MatrixEngine::buildPointers() {
	u16 top = (7 * ((16-height)>>1) );
	u16 *ptop = (u16*) screen.getDisplay() + (top * 240);
//	top += ( (16-height) * 240);

	for (int y=0; y<height; y++) {
		for (int x=0; x<width; x++) {
			u16* dest = (u16*) ptop + ((x*12)+79) + (((y*7)+26)*240) + (6 * (y & 0x0001));
			tilesLeft[y][x] = dest;
			tilesRight[y][x] = dest+81;

			extLeftCoordX[y][x] = (x * 12) + 79 + (6 * (y & 0x0001));
			extLeftCoordY[y][x] = (y * 7) + 26 + top;

			extRightCoordX[y][x] = extLeftCoordX[y][x] + 81;
			extRightCoordY[y][x] = extLeftCoordY[y][x];
		}
	}

	if (cursor) cursor->update();
}


//screen.getDisplay() + ((x*12)+79) + (((y*7)+26)*240) + (6 * (y & 0x0001));
u8 MatrixEngine::getExtendedX(u8 x, u8 y, bool side) {
//	u8 retval = (x * 12) + 79;
//	if (y & 0x0001) retval += 6;
	if (side) return extRightCoordX[y][x];
	return extLeftCoordX[y][x];
}


u8 MatrixEngine::getExtendedY(u8 x, u8 y, bool side) {
	if (side) return extRightCoordY[y][x];
	return extLeftCoordY[y][x];
}


u16 *MatrixEngine::getTilePointer1(u16 x, u16 y) {
	return tilesLeft[y][x];
}

u16 *MatrixEngine::getTilePointer2(u16 x, u16 y) {
	return tilesRight[y][x];
}




void MatrixEngine::drawTile(u16 x, u16 y, u8 basecolor, bool side) {
	paintTile(getTilePointer(x, y, side), basecolor);
}


void MatrixEngine::drawFlipTile(u16 x, u16 y, u8 basecolor1, u8 basecolor2, u8 frame, bool side) {
	if (frame > 28) {
		if (basecolor1 > 7) basecolor1 -=8;
		if (basecolor2 > 7) basecolor2 -=8;
	}

	u16 *dest = getTilePointer(x, y, side);

	if (frame > 30) {
		paintFlip3(dest, basecolor2);
	}
	else if (frame > 29) {
		paintFlip2(dest, basecolor1, basecolor2);
	}
	else if (frame > 28) {
		paintFlip1(dest, basecolor1);
	} else {
		paintTile(dest, basecolor1);
	}
}


void MatrixEngine::eraseTile(u16 x, u16 y, bool side) {
	paintBlackTile( getTilePointer(x, y, side) );
}


void MatrixEngine::eraseAll() {
	for (int y=0; y<height; y++) {
		for (int x=0; x<width; x++) {
			paintBlackTile( getTilePointer(x, y, false) );
			paintBlackTile( getTilePointer(x, y, true) );
		}
	}
}


void MatrixEngine::onInput(u16 prevState) {
  if (paused) return;
	if (getKeyLeft()) if (prevState & KEYLIST::KEY_LEFT) left();
	if (getKeyRight()) if (prevState & KEYLIST::KEY_RIGHT) right();
	if (getKeyUp()) if (prevState & KEYLIST::KEY_UP) up();
	if (getKeyDown()) if (prevState & KEYLIST::KEY_DOWN) down();
	if (getKeyB()) if (prevState & KEYLIST::KEY_B) flip();
	if (getKeyR()) if (prevState & KEYLIST::KEY_R) flip();
	if (getKeySelect()) if (prevState & KEYLIST::KEY_SELECT) onSelect();
	if (getKeyStart()) if (prevState & KEYLIST::KEY_START) onStart();
}


void MatrixEngine::flip() {
	if (flipTile) return;
	if (switchTile) return;

	int x = getX();
	int y = getY();
	if (locked[y][x] == 0) {
		vLinker *linker = getLinker(x, y);
		if (linker) return;

		new vFlipTile(x, y);

		u8 *m1a = &map1[y][x];
		u8 *m2a = &map2[y][x];
		*m1a = 0;
		*m2a = 0;
		updateCursor();
		onMove();
	}
}


void MatrixEngine::left() {
	if (flipTile) return;
	if (switchTile) return;

	int x = getX();
	int y = getY();
	if (x > 0) {
		if (getKeyA() | getKeyL()) {
			if ( (locked[y][x-1] == 0) & (locked[y][x] == 0) ) {
				
				switchTile = new vSwitchTile(x-1, y, x, y);

				vLinker *linker1 = getLinker(x, y);
				vLinker *linker2 = getLinker(x-1, y);
				if (linker1) linker1->move(x-1, y);
				if (linker2) linker2->move(x, y);
				onMove();
			}
		}
		else {
			cursor->left();
//			onMove();
		}
	}
}


void MatrixEngine::right() {
	if (flipTile) return;
	if (switchTile) return;

	int x = getX();
	int y = getY();
	if (x < 4) {
		if (getKeyA() | getKeyL()) {
			if ( (locked[y][x+1] == 0) & (locked[y][x] == 0) ) {

				switchTile = new vSwitchTile(x, y, x+1, y);

				vLinker *linker1 = getLinker(x, y);
				vLinker *linker2 = getLinker(x+1, y);
				if (linker1) linker1->move(x+1, y);
				if (linker2) linker2->move(x, y);
				onMove();
			}
		}
		else {
			cursor->right();
//			onMove();
		}
	}
}


void MatrixEngine::up() {
	if (flipTile) return;
	if (switchTile) return;

	int x = getX();
	int y = getY();
	if (y > 0) {
		if (getKeyA() | getKeyL()) {
			if ( (locked[y-1][x] == 0) & (locked[y][x] == 0) ) {

				switchTile = new vSwitchTile(x, y-1, x, y);

				vLinker *linker1 = getLinker(x, y);
				vLinker *linker2 = getLinker(x, y-1);
				if (linker1) linker1->move(x, y-1);
				if (linker2) linker2->move(x, y);
				onMove();
			}
		}
		else {
			cursor->up();
//			onMove();
		}
	}
}


void MatrixEngine::down() {
	if (flipTile) return;
	if (switchTile) return;

	int x = getX();
	int y = getY();
	if (y < height-1) {
		if (getKeyA() | getKeyL()) {
			if ( (locked[y+1][x] == 0) & (locked[y][x] == 0) ) {

				switchTile = new vSwitchTile(x, y, x, y+1);

				vLinker *linker1 = getLinker(x, y);
				vLinker *linker2 = getLinker(x, y+1);
				if (linker1) linker1->move(x, y+1);
				if (linker2) linker2->move(x, y);
				onMove();
			}
		}
		else {
			cursor->down();
//			onMove();
		}
	}
}


bool MatrixEngine::buildTempMap(u16 x, u16 y, u8 linker) {
	if (map1[y][x] == 0) return false;
	if (map1[y][x] > 7) return false;

	u8 map[16*5];
	for (u32 i=0; i<sizeof(map); i++) map[i] = 0;

	u16 color = map1[y][x];
	map[y*5+x] = color;
	searchTmpMap(x, y, color, map);

	int count=0;
	for (u32 i=0; i<sizeof(map); i++) {
		if (map[i]) count++;
	}

	if (count > 4) {

		if (linker == 1) {
			vLinker *link = getLinker(x, y);
			if (link) {
				link->resetTime();
			} else {
				link = new vLinker(x, y, color, map2[y][x]);
			}
			map[(y*5)+x] = 0;
		}
		
		else if (linker == 0) {
			if (clusters.hasItems()) {
				combo++;
				totalCombo++;
				if (maxCombo < combo) maxCombo = combo;
				addPoints(combo * 50);
			}
		}

		for (int i2=0; i2<height; i2++) {
			for (int i1=0; i1<width; i1++) {
				if (map[(i2*5)+i1]) {
					map1[i2][i1] += 8;
					locked[i2][i1] = true;
				}
			}
		}
		
		int streakPoints = 0;
		if (streak) streakPoints = streak->getPoints();
		if (count <= 5) addPoints((10 * count) + streakPoints);
		else if (count == 6) addPoints((20 * count) + streakPoints);
		else if (count == 7) addPoints((40 * count) + streakPoints);
		else if (count == 8) addPoints((50 * count) + streakPoints);
		else if (count == 9) addPoints((60 * count) + streakPoints);
		else addPoints((70 * count) + streakPoints);
		onCluster(new vCluster(map, color));
		return true;
	}
	return false;
}


void MatrixEngine::searchTmpMap(u16 x, u16 y, u8 color, u8 *map) {
	//left
	if (x > 0) {
		if (map[y*5+x-1] == 0) {
			if (map1[y][x-1] == color) {
				map[y*5+x-1] = color;
				searchTmpMap(x-1, y, color, map);
			}
		}
	}

	//right
	if (x < width-1) {
		if (map[y*5+x+1] == 0) {
			if (map1[y][x+1] == color) {
				map[y*5+x+1] = color;
				searchTmpMap(x+1, y, color, map);
			}
		}
	}

	//up
	if (y > 0) {
		if (map[(y-1)*5+x] == 0) {
			if (map1[y-1][x] == color) {
				map[(y-1)*5+x] = color;
				searchTmpMap(x, y-1, color, map);
			}
		}
	}

	//down
	if (y < height-1) {
		if (map[(y+1)*5+x] == 0) {
			if (map1[y+1][x] == color) {
				map[(y+1)*5+x] = color;
				searchTmpMap(x, y+1, color, map);
			}
		}
	}

	//alt up
	if (y > 0) {
		if (!(y & 0x01)) {
			if (x > 0) {
				if (map[((y-1)*5)+x-1] == 0) {
					if (map1[y-1][x-1] == color) {
						map[((y-1)*5)+x-1] = color;
						searchTmpMap(x-1, y-1, color, map);
					}
				}
			}
		} else {
			if (x < width-1) {
				if (map[((y-1)*5)+x+1] == 0) {
					if (map1[y-1][x+1] == color) {
						map[((y-1)*5)+x+1] = color;
						searchTmpMap(x+1, y-1, color, map);
					}
				}
			}
		}
	}

	//alt down
	if (y < height-1) {
		if (!(y & 0x01)) {
			if (x > 0) {
				if (map[((y+1)*5)+x-1] == 0) {
					if (map1[y+1][x-1] == color) {
						map[((y+1)*5)+x-1] = color;
						searchTmpMap(x-1, y+1, color, map);
					}
				}
			}
		} else {
			if (x < width-1) {
				if (map[((y+1)*5)+x+1] == 0) {
					if (map1[y+1][x+1] == color) {
						map[((y+1)*5)+x+1] = color;
						searchTmpMap(x+1, y+1, color, map);
					}
				}
			}
		}
	}
}



void MatrixEngine::drawBackground() {
	u16* dest = (u16*) screen.getDisplay() + ( (240*60) + (0) );
	const u16* src = bg_a_gfx;
	for (int i=0; i<100; i++) {
		dma3_16(src, dest, 77);
		src += 88;
		dest += 240;
	}

	dest = (u16*) screen.getDisplay() + ( (240*151) + (77) );
	src = bg_b_gfx;
	for (int i=0; i<9; i++) {
		dma3_16(src, dest, 16);
		src += 16;
		dest += 240;
	}

	dest = (u16*) screen.getDisplay() + ( (240*132) + (77) );
	src = bg_c_gfx;
	for (int i1=0; i1<19; i1++) {
		u16 *dest2 = dest;
		const u16 *src2 = src;
		for (int i2=0; i2<matrixDrawC[i1]; i2++) {
			*dest2 = *src2;
			src2++;
			dest2++;
		}
		src += 16;
		dest += 240;
	}

	dest = (u16*) screen.getDisplay() + ( (240*151) + (91) );
	src = web_gfx;
	for (int i=0; i<9; i++) {
		dma3_16(src, dest, 149);
		src += 160;
		dest += 240;
	}

	
	{
		u16 color = RGB(20,20,20);
		for (int i=33; i<132; i++) screen.hLine(145, i, 13, color);
		screen.hLine(145, 132, 14, color);
		screen.hLine(145, 133, 14, color);
		screen.hLine(145, 134, 15, color);
		screen.hLine(145, 135, 15, color);
		screen.hLine(145, 136, 16, color);
		screen.hLine(145, 137, 17, color);
		screen.hLine(145, 138, 18, color);

		screen.hLine(145, 139, 19, color+RGB(1,0,1));
		screen.hLine(144, 140, 22, color+RGB(1,1,1));
		screen.hLine(143, 141, 25, color+RGB(2,1,2));
		screen.hLine(142, 142, 27, color+RGB(2,2,2));
		screen.hLine(143, 143, 25, color+RGB(3,2,3));
		screen.hLine(144, 144, 23, color+RGB(3,3,3));
		screen.hLine(144, 145, 23, color+RGB(4,3,4));
		screen.hLine(144, 146, 23, color+RGB(4,4,4));
		screen.hLine(144, 147, 23, color+RGB(5,4,5));
		screen.hLine(144, 148, 23, color+RGB(5,5,5));
		screen.hLine(143, 149, 25, color+RGB(6,5,6));
		screen.hLine(142, 150, 27, color+RGB(6,6,6));

		for (int i=35; i<139; i++) screen.hLine(226, i, 14, color);
		screen.hLine(226, 139, 14, color+RGB(1,0,1));
		screen.hLine(225, 140, 15, color+RGB(1,1,1));
		screen.hLine(224, 141, 16, color+RGB(2,1,2));
		screen.hLine(223, 142, 17, color+RGB(2,2,2));
		screen.hLine(224, 143, 16, color+RGB(3,2,3));
		screen.hLine(224, 144, 16, color+RGB(3,3,3));
		screen.hLine(224, 145, 16, color+RGB(4,3,4));
		screen.hLine(224, 146, 16, color+RGB(4,4,4));
		screen.hLine(224, 147, 16, color+RGB(5,4,5));
		screen.hLine(224, 148, 16, color+RGB(5,5,5));
		screen.hLine(224, 149, 16, color+RGB(6,5,6));
		screen.hLine(223, 150, 17, color+RGB(6,6,6));

		screen.hLine(145, 35, 13, color-RGB(1,0,1));
		screen.hLine(144, 34, 15, color-RGB(1,1,1));
		screen.hLine(144, 33, 15, color-RGB(2,1,2));
		screen.hLine(143, 32, 16, color-RGB(2,2,2));
		screen.hLine(143, 31, 16, color-RGB(3,2,3));
		screen.hLine(142, 30, 17, color-RGB(3,3,3));
		screen.hLine(141, 29, 18, color-RGB(4,3,4));
		screen.hLine(140, 28, 19, color-RGB(4,4,4));
		screen.hLine(139, 27, 20, color-RGB(5,4,5));
		screen.hLine(137, 26, 23, color-RGB(5,5,5));
		screen.hLine(135, 25, 26, color-RGB(6,5,6));
		screen.hLine(133, 24, 29, color-RGB(6,6,6));

		screen.hLine(225, 35, 15, color-RGB(1,0,1));
		screen.hLine(225, 34, 15, color-RGB(1,1,1));
		screen.hLine(224, 33, 16, color-RGB(2,1,2));
		screen.hLine(224, 32, 16, color-RGB(2,2,2));
		screen.hLine(223, 31, 17, color-RGB(3,2,3));
		screen.hLine(222, 30, 18, color-RGB(3,3,3));
		screen.hLine(221, 29, 19, color-RGB(4,3,4));
		screen.hLine(220, 28, 20, color-RGB(4,4,4));
		screen.hLine(219, 27, 21, color-RGB(5,4,5));
		screen.hLine(218, 26, 22, color-RGB(5,5,5));
		screen.hLine(216, 25, 24, color-RGB(6,5,6));
		screen.hLine(214, 24, 26, color-RGB(6,6,6));

		screen.hLine(79, 23, 161, RGB(14,14,14));
		for (int i=16; i<23; i++) screen.hLine(78, i, 162, RGB(14,14,14));
		screen.hLine(77, 15, 163, RGB(14,14,14));
		screen.hLine(76, 14, 164, RGB(14,14,14));
		screen.hLine(77, 13, 163, RGB(14,14,14));
		for (int i=3; i<13; i++) screen.hLine(78, i, 162, RGB(14,14,14));
		screen.hLine(77, 2, 163, RGB(12,12,12));
		screen.hLine(76, 1, 164, RGB(10,10,10));
		screen.hLine(0 , 0, 240, RGB(8,8,8));

		screen.hLine(0 , 59, 3, RGB(27,27,27));
		screen.hLine(0 , 58, 2, RGB(27,26,27));
		screen.pSet(0, 57, RGB(26,26,26));
		screen.pSet(0, 56, RGB(26,25,26));
		screen.pSet(0, 55, RGB(25,25,25));
		screen.pSet(0, 54, RGB(25,24,25));
		screen.pSet(0, 53, RGB(24,24,24));
		screen.pSet(0, 52, RGB(24,23,24));
		screen.pSet(0, 51, RGB(23,23,23));
		screen.pSet(0, 50, RGB(23,22,23));
		screen.pSet(0, 49, RGB(22,22,22));
		screen.pSet(0, 48, RGB(22,21,22));
		screen.pSet(0, 47, RGB(21,21,21));
		screen.pSet(0, 46, RGB(21,20,21));
		screen.hLine(0 , 45, 2, color);
		screen.hLine(0 , 44, 3, color);
		screen.hLine(0 , 43, 2, color);
		for (int i=38; i<43; i++) screen.pSet(0, i, color);
		screen.hLine(0 , 37, 2, color);
		screen.hLine(0 , 36, 3, color);
		screen.hLine(0 , 35, 2, color-RGB(1,0,1));

		screen.pSet(0, 34, color-RGB(1,1,1));
		screen.pSet(0, 33, color-RGB(2,1,2));
		screen.pSet(0, 32, color-RGB(2,2,2));
		screen.pSet(0, 31, color-RGB(3,2,3));
		screen.pSet(0, 30, color-RGB(3,3,3));
		screen.pSet(0, 29, color-RGB(4,3,4));
		screen.pSet(0, 28, color-RGB(4,4,4));
		screen.pSet(0, 27, color-RGB(5,4,5));
		screen.pSet(0, 26, color-RGB(5,5,5));
		screen.pSet(0, 25, color-RGB(6,5,6));
		screen.pSet(0, 24, color-RGB(6,6,6));
		for (int i=3; i<24; i++) screen.pSet(0, i, RGB(14,14,14));

		screen.hLine(0, 2, 2, RGB(12,12,12));
		screen.hLine(0, 1, 3, RGB(10,10,10));
		screen.hLine(35, 1, 3, RGB(10,10,10));
		screen.pSet(36, 2, RGB(12,12,12));
	}
}


void MatrixEngine::updateCursor() {
  ASSERT(cursor!=NULL);
	cursor->update();
}

void MatrixEngine::hideCursor() {
  ASSERT(cursor!=NULL);
	cursor->hideCursor();
}

void MatrixEngine::showCursor() {
  ASSERT(cursor!=NULL);
	cursor->showCursor();
}


vLinker *MatrixEngine::getLinker(u16 x, u16 y) {
	vLinker *linker = linkers.getFirstItem();
	while (linker) {
		if ( (linker->getX() == x) && (linker->getY() == y) ) return linker;
		linker = linkers.getNextItem(linker);
	}
	return NULL;
}



void MatrixEngine::onCluster(vCluster *clstr) {
	clusters.appendItem(clstr);
}

		
void MatrixEngine::onClusterClear(vCluster *clstr) {
	clusters.removeItem(clstr);
	if (!clusters.hasItems()) combo = 0;
}


void MatrixEngine::addCounter(vStreakCounter *counter) {
	counters.appendItem(counter);

	if (!streak) {
		streak = new vStreak(scoreData);
		for (int i=0; i<3; i++) streakZero[i]->hide();
	}
}


void MatrixEngine::delCounter(vStreakCounter *counter) {
	counters.removeItem(counter);

	if (!clusters.hasItems()) {
		for (int i=0; i<3; i++) streakZero[i]->show();
		vdelnull(streak);
		onStreakTimeout();
	}
}
