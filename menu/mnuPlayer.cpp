/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/sprites/gbaSpriteManager.h>

#include "mnuPlayer.h"
#include "mnuMain.h"
#include "miPlayNow.h"
#include "miPuzzleMode.h"
#include "miNewPlayer.h"
#include "miLoadPlayer.h"
#include "miErasePlayer.h"
#include "miTopScores.h"
#include "miSunset.h"

#include "../matrix/score.h"
#include "../resources.h"
#include "mnuMainItems.h"
#include "mnuPlayerItems.h"


u16 mnuPlayer::lastId = 0;


mnuPlayer::mnuPlayer(vScore *plr, s8 plrProfile) : mnuBase(mnuPlayerItems, 8) {
	player = plr;
	profile = plrProfile;
	screen.drawString(player->name, 98, 3, RGB(0,0,0));
} 


mnuPlayer::~mnuPlayer() {
}


void mnuPlayer::Cancel() {
	mnuBase::Cancel();

	delete this;
	gbaMenu *menu = new mnuMain();
	menu->buildList();
}


void mnuPlayer::onChange(u16 selected) {
	lastId = selected;
	switch (selected) {
		case 0: {
			fishes[0]->move(65,80);
			fishes[1]->move(160,80);
		} break;
		case 1: {
			fishes[0]->move(65,89);
			fishes[1]->move(160,89);
		} break;
		case 2: {
			fishes[0]->move(69,98);
			fishes[1]->move(156,98);
		} break;
		case 3: {
			fishes[0]->move(66,107);
			fishes[1]->move(159,107);
		} break;
		case 4: {
			fishes[0]->move(62,116);
			fishes[1]->move(163,116);
		} break;
		case 5: {
			fishes[0]->move(68,125);
			fishes[1]->move(157,125);
		} break;
		case 6: {
			fishes[0]->move(78,134);
			fishes[1]->move(147,134);
		} break;
		case 7: {
			fishes[0]->move(78,143);
			fishes[1]->move(147,143);
		} break;
	}
}


void mnuPlayer::onListBuilt() {
	setActive(lastId);
	spriteManager.zeroGarbage();
}


gbaMenuItem *mnuPlayer::newMenuItem(gbaMnuPart *partList, u16 listCount) {
	switch (getItemCount()) {
		case 0: return new miPlayNow    (partList, listCount, this, profile);
		case 1: return new miPuzzleMode (partList, listCount, this, profile);
		case 2: return new miNewPlayer  (partList, listCount, this);
		case 3: return new miLoadPlayer (partList, listCount, this);
		case 4: return new miErasePlayer(partList, listCount, this);
		case 5: return new miTopScores  (partList, listCount, this);
		case 7: return new miSunset     (partList, listCount, this);
	}
	return gbaMenu::newMenuItem(partList, listCount);
}
