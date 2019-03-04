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
#include <colorSpace.h>
#include "scrFinishGame.h"
#include "../menu/mnuMain.h"


scrFinishGame::scrFinishGame(s8 plrProfile, vScore *plrScore) {
	second = false;
	profile = plrProfile;
	score = plrScore;
	dma3fill_32(RGB(31,31,31) | (RGB(31,31,31)<<16), (void*)screen.getDisplay(), ((240*160)>>1));

  spriteManager.deallocateAll();
  spriteManager,onVBlank();
}


scrFinishGame::scrFinishGame() {
	profile = 0;
}


scrFinishGame::~scrFinishGame() {
//	if (profile == -1) free(score);
}


void scrFinishGame::onVBlank() {
//	blueScreen();
/*	if (!second) {
		second = true;
		return;
	}*/

#ifndef _MULTIBOOT_
	delete this;
	gbaMenu *menu = new mnuMain();
//	menu->buildList();
#endif//_MULTIBOOT_
}
