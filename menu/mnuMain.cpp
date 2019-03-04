/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/sprites/gbaSpriteManager.h>
#include "mnuMain.h"
#include "miPlayNow.h"
#include "miNewPlayer.h"
#include "miLoadPlayer.h"
#include "miErasePlayer.h"
#include "miTopScores.h"
#include "miSunset.h"

#include "../resources.h"
#include "mnuMainItems.h"


u16 mnuMain::lastId = 0;


mnuMain::mnuMain() : mnuBase(mnuMainItems, 8) {
} 


void mnuMain::onChange(u16 selected) {
	lastId = selected;
	switch (selected) {
		case 0: {
			fishes[0]->move(75,80);
			fishes[1]->move(150,80);
		} break;
		case 1: {
			fishes[0]->move(69,89);
			fishes[1]->move(156,89);
		} break;
		case 2: {
			fishes[0]->move(66,98);
			fishes[1]->move(159,98);
		} break;
		case 3: {
			fishes[0]->move(62,107);
			fishes[1]->move(163,107);
		} break;
		case 4: {
			fishes[0]->move(66,116);
			fishes[1]->move(159,116);
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


void mnuMain::onListBuilt() {
	setActive(lastId);
	spriteManager.zeroGarbage();
}


gbaMenuItem *mnuMain::newMenuItem(gbaMnuPart *partList, u16 listCount) {
	switch (getItemCount()) {
		case 0: return new miPlayNow    (partList, listCount, this);
		case 1: return new miNewPlayer  (partList, listCount, this);
		case 2: return new miLoadPlayer (partList, listCount, this);
		case 3: return new miErasePlayer(partList, listCount, this);
		case 5: return new miTopScores  (partList, listCount, this);
		case 7: return new miSunset     (partList, listCount, this);
	}
	return gbaMenu::newMenuItem(partList, listCount);
}
