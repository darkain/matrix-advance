/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/sprites/gbaSprites.h>
#include "scrNameEntry.h"
#include "scrNewPlayer.h"
#include "faces.h"
#include "../menu/mnuPlayer.h"
#include "../matrix/score.h"
#include "../resources.h"


scrNameEntry::scrNameEntry(u8 profileId, vScore *ptrProfile) : irqInput(true) {
	profile = profileId;
	player = ptrProfile;
	memset(player, 0, sizeof(vScore));

	//NameEntry_gfx
	u32 size = sizeof(NameEntry_gfx)>>2;
	dma3_32(NameEntry_gfx, (void*)screen.getDisplay(), size);
	dma3fill_32( 0, (u32*)screen.getDisplay()+size, ((240*160)>>1)-size );

	len = 0;
	row = 0;
	col = 0;
	section = 0;
	faceId = 1;

	face = NULL;
	updateFace();


	screen.drawString("A B C D E F G H I J K L M",  19, 62);
	screen.drawString("N O P Q R S T U V W X Y Z",  19, 78);
	screen.drawString("a b c d e f g h i j k l m",  19, 94);
	screen.drawString("n o p q r s t u v w x y z",  19, 110);
	screen.drawString(". / 0 1 2 3 4 5 6 7 8 9 :",  19, 126);
	screen.drawString("! \" # $ % & ' ( ) * + , -", 19, 142);

	screen.hLine(20,  58,  72);
	screen.hLine(97,  58,  56);
	screen.hLine(158, 58,  60);
	screen.hLine(20,  153, 198);
	screen.vLine(15,  63,  86);
	screen.vLine(222, 63,  86);

	//top left
	screen.pSet(19, 59);
	screen.pSet(18, 59);
	screen.pSet(17, 60);
	screen.pSet(16, 61);
	screen.pSet(16, 62);

	//top right
	screen.pSet(221, 62);
	screen.pSet(221, 61);
	screen.pSet(220, 60);
	screen.pSet(219, 59);
	screen.pSet(218, 59);

	//bottom left
	screen.pSet(19, 152);
	screen.pSet(18, 152);
	screen.pSet(17, 151);
	screen.pSet(16, 150);
	screen.pSet(16, 149);

	//bottom right
	screen.pSet(218, 152);
	screen.pSet(219, 152);
	screen.pSet(220, 151);
	screen.pSet(221, 150);
	screen.pSet(221, 149);

	//face pic
	screen.drawString("L<", 21, 48);
	screen.drawString(">R", 74, 48);
	screen.hLine(20,  21, 72);
	screen.vLine(17,  24, 32);
	screen.vLine(94,  24, 32);

	//face pic
	screen.pSet(19, 22);
	screen.pSet(18, 23);
	screen.pSet(18, 56);
	screen.pSet(19, 57);
	screen.pSet(92, 22);
	screen.pSet(93, 23);
	screen.pSet(92, 57);
	screen.pSet(93, 56);
	screen.pSet(96, 57);
	screen.pSet(95, 56);

	//name entry
	screen.hLine(105,  50, 40);
	screen.pSet(112, 50, RGB(0,0,0));
	screen.pSet(113, 50, RGB(0,0,0));
	screen.pSet(120, 50, RGB(0,0,0));
	screen.pSet(121, 50, RGB(0,0,0));
	screen.pSet(128, 50, RGB(0,0,0));
	screen.pSet(129, 50, RGB(0,0,0));
	screen.pSet(136, 50, RGB(0,0,0));
	screen.pSet(137, 50, RGB(0,0,0));

	//name entry
	screen.hLine(97, 21, 56);
	screen.vLine(155, 24, 32);
	screen.pSet(96, 22);
	screen.pSet(95, 23);
	screen.pSet(153, 22);
	screen.pSet(154, 23);
	screen.pSet(153, 57);
	screen.pSet(154, 56);

	//yes/no
	screen.hLine(158, 21, 60);
	screen.vLine(220, 24, 32);
	screen.pSet(156, 56);
	screen.pSet(157, 57);
	screen.pSet(156, 23);
	screen.pSet(157, 22);
	screen.pSet(218, 22);
	screen.pSet(219, 23);
	screen.pSet(219, 56);
	screen.pSet(218, 57);

	cursor = new vSprite(TextCursor_gfx, 4, 2, 0, 1, false, 0);
	dma3_32(TextCursor_gfx, cursor->getData(), sizeof(TextCursor_gfx)>>2);
	updateCursor();
	cursor->show();

	screen.setObjectPaletteEntry(1, RGB(0,0,31));
	screen.setObjectPaletteEntry(2, RGB(0,31,0));
	screen.setObjectPaletteEntry(3, RGB(31,0,0));

	updateName();
}


scrNameEntry::~scrNameEntry() {
	delete cursor;
	delete face;
}


void scrNameEntry::updateName() {
	for (int i=0; i<8; i++) {
		screen.hLine(105, 42+i, 40, RGB(0,0,0));
	}
	screen.drawString(player->name, 105, 42, RGB(31,0,31));
}


void scrNameEntry::updateFace() {
	delete face;
	face = new gbaFace(39, 24, faceId);
}


void scrNameEntry::updateCursor() {
	if (section == 0) {
		cursor->move(17+(16*col), 60+(16*row));
	}
}


void scrNameEntry::Exit() {
	memset(player, 0, sizeof(vScore));
	u8 p = profile;
	delete this;
	new screenNewPlayer(p);
}


void scrNameEntry::Enter() {
	vScore *plr = player;
	u8 prof = profile;

	if (len<1) return;
	player->face = faceId;
	gameScores->saveScores();
	delete this;
	
	gbaMenu *menu = new mnuPlayer(plr, prof);
	menu->buildList();
}


void scrNameEntry::onInput(u16 prevState) {
	if (getKeyLeft()) if (prevState & KEYLIST::KEY_LEFT) Left();
	if (getKeyRight()) if (prevState & KEYLIST::KEY_RIGHT) Right();
	if (getKeyUp()) if (prevState & KEYLIST::KEY_UP) Up();
	if (getKeyDown()) if (prevState & KEYLIST::KEY_DOWN) Down();
	if (getKeyR()) if (prevState & KEYLIST::KEY_R) R();
	if (getKeyL()) if (prevState & KEYLIST::KEY_L) L();
	if (getKeyB()) if (prevState & KEYLIST::KEY_B) Cancel();
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) Accept();
	if (getKeyStart()) if (prevState & KEYLIST::KEY_START) Enter();
}


void scrNameEntry::Accept() {
	if (section == 0) {
		if (len < 5) {
			char *str = player->name;
			if (row == 0) str[len] = col + 0x41;
			else if (row == 1) str[len] = col + 0x4E;
			else if (row == 2) str[len] = col + 0x61;
			else if (row == 3) str[len] = col + 0x6E;
			else if (row == 4) str[len] = col + 0x2E;
			else if (row == 5) str[len] = col + 0x21;
			updateName();
			len++;
		}
	}
}


void scrNameEntry::Cancel() {
	if (section == 0) {
		if (len > 0) {
			char *str = player->name;
			str[--len] = 0;
			updateName();
		}
	}
}


void scrNameEntry::R() {
	if (section == 0) {
		faceId++;
		if (faceId == 9) faceId = 1;
		updateFace();
	}
}


void scrNameEntry::L() {
	if (section == 0) {
		faceId--;
		if (faceId == 0) faceId = 8;
		updateFace();
	}
}

void scrNameEntry::Left() {
	if (section == 0) {
		if (col > 0) col--;
		else col = 12;
		updateCursor();
	}
}

void scrNameEntry::Right() {
	if (section == 0) {
		if (col < 12) col++;
		else col = 0;
		updateCursor();
	}
}

void scrNameEntry::Up() {
	if (section == 0) {
		if (row > 0) row--;
		else row = 5;
		updateCursor();
	}
}

void scrNameEntry::Down() {
	if (section == 0) {
		if (row < 5) row++;
		else row = 0;
		updateCursor();
	}
}
