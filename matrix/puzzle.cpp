/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/gbaInlines.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/irq/gbaInterupt.h>

#include "puzzle.h"
#include "puzzleData.h"
#include "../menu/mnuMain.h"
#include "../resources.h"


#ifndef _MULTIBOOT_



PuzzleMatrix::PuzzleMatrix(u16 newlevel, s8 profile) : MatrixEngine(profile) {
	puzzleId = 0;
	puzzle = NULL;
	moves = 0;
	pauseEngine = NULL;
	setSave(true);

	screen.setObjectPaletteEntry(1, RGB(31,31,31));
	moveDisplay = new vSprite(scoreData, 20, 10, 0, 0, false, 0);
	moveDisplay->move(148, 27);
	moveDisplay->getSpriteEntry()->setPriority(3);
	moveDisplay->show();

	minutes = 0;
  seconds = 0;

  loadLevel(1);

//  interupt.setMasterIRQ(true);
}


PuzzleMatrix::~PuzzleMatrix() {
	delete moveDisplay;
	moveDisplay = NULL;
}


void PuzzleMatrix::loadLevel(vPuzzle *pzle) {
	ASSERT(pzle != NULL);
	puzzle = pzle;

	moves = puzzle->moves;
	moveDisplay->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(moves));
	pauseEngine = NULL;

	if (puzzle) {
		resetScore();
		deleteEverything();
		eraseAll();
	}

	width = puzzle->width;
	height = puzzle->height;
	buildPointers();
	cursor->moveCursor(2, height>>1);
	
	u8 *src = puzzle->data;
	
	for (int y=0; y<height; y++) {
		for (int x=0; x<width; x++) {
			locked[y][x] = 0;
			map1[y][x] = *src;
			src++;
		}
	}

	for (int y=0; y<height; y++) {
		for (int x=0; x<width; x++) {
			map2[y][x] = *src;
			src++;
		}
	}


	screen.vSyncLoop();
	refreshMatrix();
}


void PuzzleMatrix::loadLevel(u16 newlevel) {
	if (newlevel >= (sizeof(puzzleList)/sizeof(puzzleList[0]))) blueScreen();
	loadLevel(puzzleList[newlevel]);
	puzzleId = newlevel;
	setLevel(puzzleId);
}


void PuzzleMatrix::onClusterClear(vCluster *clstr) {
	MatrixEngine::onClusterClear(clstr);

	for (int i2=0; i2<16; i2++) {
		for (int i1=0; i1<5; i1++) {
			if (map1[i2][i1]) return;
			if (map2[i2][i1]) return;
		}
	}
	pauseEngine = new vPuzzleWin(this);
//	nextLevel();
}


void PuzzleMatrix::resetEngine() {
	MatrixEngine::resetEngine();
	loadLevel(puzzle);
}


void PuzzleMatrix::onStreakTimeout() {
	if (moves == 0) {
		if (!pauseEngine) {
			new vPuzzleLose();
		}
	}
}


void PuzzleMatrix::onMove() {
	moves--;
	if (moves == 0) {
		for (int y=0; y<height; y++) {
			for (int x=0; x<width; x++) {
				locked[y][x] = 1;
			}
		}
	}
	moveDisplay->getSpriteEntry()->setDataId(scoreData->getDataIdOffset(moves));
}


//-----------------------------------------------------------------------------


vPuzzleWin::vPuzzleWin(PuzzleMatrix *matrix) {
  ASSERT(matrix != NULL);
	puzzle = matrix;

	selected = 0;
	for (int i=0; i<20; i++) sprites[i] = NULL;

	int x=87;
	int y=35;

	u8 count = 0;
	sprites[count] = new vSprite(WIN_gfx, 4, 4, 1, 1, false, 14);
	sprites[count]->move(x+74, y+10);

	count++;
	sprites[count] = new vSprite(LE_gfx, 2, 2, 1, 0, false, 14);
	sprites[count]->move(x+50, y+10);

	count++;
	sprites[count] = new vSprite(PUZZ_gfx, 4, 4, 1, 1, false, 14);
	sprites[count]->move(x+22, y+10);

	count++;
	sprites[count] = new vSprite(le2_gfx, 2, 2, 1, 0, false, 13);
	sprites[count]->move(x+88, y+35);

	count++;
	sprites[count] = new vSprite(Puzz_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+60, y+35);

	count++;
	sprites[count] = new vSprite(Next_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+24, y+35);

	count++;
	sprites[count] = new vSprite(Again_gfx, 4, 2, 1, 1, false, 13);
	sprites[count]->move(x+63, y+55);

	count++;
	sprites[count] = new vSprite(Play_gfx, 4, 2, 1, 1, false, 13);
	sprites[count]->move(x+33, y+55);

	count++;
	sprites[count] = new vSprite(Menu_gfx, 4, 2, 1, 1, false, 13);
	sprites[count]->move(x+75, y+75);

	count++;
	sprites[count] = new vSprite(To_gfx, 2, 2, 1, 0, false, 13);
	sprites[count]->move(x+55, y+75);

	count++;
	sprites[count] = new vSprite(Exit_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+25, y+75);

	for (int i=0; i<=count; i++) {
		sprites[i]->getSpriteEntry()->setPriority(0);
		sprites[i]->show();
	}

	build();
	update();
}


vPuzzleWin::~vPuzzleWin() {
	for (int i=0; i<20; i++) {
		delete sprites[i];
		sprites[i] = NULL;
	}
}

void vPuzzleWin::onInput(u16 prevState) {
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) {
		switch (selected) {
		case 0: {
			puzzle->unPause();
			puzzle->nextLevel();
		} break;
		case 1: engine->resetEngine();	break;
		case 2:
			delete engine;
			engine = NULL;
			delete this;
			gbaMenu *menu = new mnuMain();
			menu->buildList();
			return;
		}
		delete this;
		return;
	}
	if (getKeyUp()) if (prevState & KEYLIST::KEY_UP) up();
	if (getKeyDown()) if (prevState & KEYLIST::KEY_DOWN) down();
}

void vPuzzleWin::up() {
	if (selected == 0) selected = 2;
	else selected--;
	update();
}

void vPuzzleWin::down() {
	if (selected == 2) selected = 0;
	else selected++;
	update();
}

void vPuzzleWin::update() {
	for (int i=3; i<20; i++) {
		if (sprites[i]) {
			sprites[i]->getSpriteEntry()->setPaletteNumber(13);
		}
	}

	switch (selected) {
		case 0: {
			sprites[3]->getSpriteEntry()->setPaletteNumber(12);
			sprites[4]->getSpriteEntry()->setPaletteNumber(12);
			sprites[5]->getSpriteEntry()->setPaletteNumber(12);
		} break;

		case 1: {
			sprites[6]->getSpriteEntry()->setPaletteNumber(12);
			sprites[7]->getSpriteEntry()->setPaletteNumber(12);
		} break;

		case 2: {
			sprites[8]->getSpriteEntry()->setPaletteNumber(12);
			sprites[9]->getSpriteEntry()->setPaletteNumber(12);
			sprites[10]->getSpriteEntry()->setPaletteNumber(12);
		} break;
	}
}


//-----------------------------------------------------------------------------


vPuzzleLose::vPuzzleLose() {
  ASSERT(engine != NULL);

	selected = 0;
	for (int i=0; i<20; i++) sprites[i] = NULL;

	int x=87;
	int y=35;

	u8 count = 0;
	sprites[count] = new vSprite(LOSE_gfx, 4, 4, 1, 1, false, 14);
	sprites[count]->move(x+74, y+10);

	count++;
	sprites[count] = new vSprite(LE_gfx, 2, 2, 1, 0, false, 14);
	sprites[count]->move(x+50, y+10);

	count++;
	sprites[count] = new vSprite(PUZZ_gfx, 4, 4, 1, 1, false, 14);
	sprites[count]->move(x+22, y+10);

	count++;
	sprites[count] = new vSprite(Again_gfx, 4, 2, 1, 1, false, 13);
	sprites[count]->move(x+63, y+55);

	count++;
	sprites[count] = new vSprite(Play_gfx, 4, 2, 1, 1, false, 13);
	sprites[count]->move(x+33, y+55);

	count++;
	sprites[count] = new vSprite(Menu_gfx, 4, 2, 1, 1, false, 13);
	sprites[count]->move(x+75, y+75);

	count++;
	sprites[count] = new vSprite(To_gfx, 2, 2, 1, 0, false, 13);
	sprites[count]->move(x+55, y+75);

	count++;
	sprites[count] = new vSprite(Exit_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+25, y+75);

	total = count+1;
	for (int i=0; i<total; i++) {
		sprites[i]->getSpriteEntry()->setPriority(0);
		sprites[i]->show();
	}

	build();
	update();
}


vPuzzleLose::~vPuzzleLose() {
	for (int i=0; i<total; i++) {
		delete sprites[i];
		sprites[i] = NULL;
	}
}


void vPuzzleLose::onInput(u16 prevState) {
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) {
		switch (selected) {
		case 0: engine->resetEngine();	break;
		case 1:
			delete engine;
			engine = NULL;
			delete this;
			gbaMenu *menu = new mnuMain();
			menu->buildList();
			return;
		}
		delete this;
		return;
	}
	if (getKeyUp()) if (prevState & KEYLIST::KEY_UP) up();
	if (getKeyDown()) if (prevState & KEYLIST::KEY_DOWN) down();
}

void vPuzzleLose::up() {
	if (selected) selected = 0;
	else selected = 1;
	update();
}

void vPuzzleLose::down() {
	if (selected) selected = 0;
	else selected = 1;
	update();
}


void vPuzzleLose::update() {
	for (int i=3; i<total; i++) {
		if (sprites[i]) {
			sprites[i]->getSpriteEntry()->setPaletteNumber(13);
		}
	}

	if (selected) {
		sprites[5]->getSpriteEntry()->setPaletteNumber(12);
		sprites[6]->getSpriteEntry()->setPaletteNumber(12);
		sprites[7]->getSpriteEntry()->setPaletteNumber(12);
	} else {
		sprites[3]->getSpriteEntry()->setPaletteNumber(12);
		sprites[4]->getSpriteEntry()->setPaletteNumber(12);
	}
}


#endif//_MULTIBOOT_
