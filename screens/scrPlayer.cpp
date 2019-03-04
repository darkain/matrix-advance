/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include "../matrix/score.h"
#include "faces.h"
#include "scrPlayer.h"
#include "../resources.h"


screenPlayer::screenPlayer(const u16 *logo, u16 size, u8 defaultSelect) : irqInput(true) {
	cur = defaultSelect;

	size >>= 2;
	dma3_32(logo,  (void*)screen.getDisplay(), size);
	dma3fill_32(0, (u32*)screen.getDisplay()+size, ((240*160)>>1)-size);

	//this is where i insert nifty lil tiling background

	vScore *player;
	screen.setObjectPaletteEntry(1, RGB(31,31,31));
	for (int i=0; i<8; i++) {
		player = gameScores->getPlayer(i);
		faces[i] = NULL;
		if (i != cur) drawBox(i);
		if (player->face) { 
			drawBoxData(i, player);
		}
	}
	drawBox(cur, RGB(31,0,10));
}


screenPlayer::~screenPlayer() {
	for (u32 i=0; i<8; i++) delete faces[i];

	vSprite *sprite = static_cast<vSprite*>(sprites.getFirstItem());
	while (sprite) {
		delete sprite;
    sprites.removeItem(sprite);
		sprite = static_cast<vSprite*>(sprites.getFirstItem());
	}
}


void screenPlayer::drawBox(u8 box, u16 color) {
	u8 side = (box & 0x01) * 119;
	box = (box >> 1) * 35;
	screen.hLine(side+3,   box+18, 115,  color);
	screen.hLine(side+3,   box+53, 115,  color);
	screen.vLine(side+1,   box+20, 32,   color);
	screen.vLine(side+119, box+20, 32,   color);
	screen.pSet (side+2,   box+19,       color);
	screen.pSet (side+2,   box+52,       color);
	screen.pSet (side+118, box+19,       color);
	screen.pSet (side+118, box+52,       color);
}


void screenPlayer::drawBoxData(u8 box, vScore *player) {
	vSprite *sprite;

	u8 side = (box & 0x01) * 119;
	u8 row = (box >> 1) * 35;
	faces[box] = new gbaFace(side+3, row+20, player->face);

	sprite = new vSprite(Name_gfx, 4, 4, 1, 1, false, 0);
	sprites.appendItem(sprite);
	dma3_32(Name_gfx, sprite->getData(), 32);
	sprite->move(side+37, row+21);
	sprite->show();

	sprite = new vSprite(HiSco_gfx, 4, 4, 1, 1, false, 0);
	sprites.appendItem(sprite);
	dma3_32(HiSco_gfx, sprite->getData(), 32);
	sprite->move(side+37, row+28);
	sprite->show();

	sprite = new vSprite(re2_gfx, 4, 4, 1, 0, false, 0);
	sprites.appendItem(sprite);
	dma3_32(re2_gfx, sprite->getData(), 32);
	sprite->move(side+69, row+29);
	sprite->show();

	sprite = new vSprite(Puzz_gfx, 4, 4, 1, 1, false, 0);
	sprites.appendItem(sprite);
	dma3_32(Puzz_gfx, sprite->getData(), 32);
	sprite->move(side+37, row+35);
	sprite->show();

	sprite = new vSprite(le_gfx, 4, 4, 1, 0, false, 0);
	sprites.appendItem(sprite);
	dma3_32(le_gfx, sprite->getData(), 32);
	sprite->move(side+65, row+35);
	sprite->show();

	screen.drawString(player->name, side+70, row+20);
}


void screenPlayer::onInput(u16 prevState) {
	if (getKeyLeft()) if (prevState & KEYLIST::KEY_LEFT) LeftRight();
	if (getKeyRight()) if (prevState & KEYLIST::KEY_RIGHT) LeftRight();
	if (getKeyUp()) if (prevState & KEYLIST::KEY_UP) Up();
	if (getKeyDown()) if (prevState & KEYLIST::KEY_DOWN) Down();
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) Accept(cur);
	if (getKeyStart()) if (prevState & KEYLIST::KEY_START) Accept(cur);
	if (getKeyB()) if (prevState & KEYLIST::KEY_B) Cancel(cur);

	if (getKeySelect()) if (prevState & KEYLIST::KEY_SELECT) {
		drawBox(cur, RGB(31,31,31));
		if (cur < 7) cur++;
		else cur = 0;
		drawBox(cur, RGB(31,0,10));
	}
}


void screenPlayer::Up() {
	drawBox(cur, RGB(31,31,31));
	if (cur > 1) cur -= 2;
	else cur += 6;
	drawBox(cur, RGB(31,0,10));
}

void screenPlayer::Down() {
	drawBox(cur, RGB(31,31,31));
	if (cur < 6) cur += 2;
	else cur -= 6;
	drawBox(cur, RGB(31,0,10));
}

void screenPlayer::LeftRight() {
	drawBox(cur, RGB(31,31,31));
	cur ^= 0x01;
	drawBox(cur, RGB(31,0,10));
}

