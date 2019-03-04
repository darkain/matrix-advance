/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "scrLoadPlayer.h"
#include "../matrix/score.h"
#include "../menu/mnuMain.h"
#include "../menu/mnuPlayer.h"
#include "../resources.h"


scrLoadPlayer::scrLoadPlayer(u8 defaultSelect)
 : screenPlayer(LoadPlayer_gfx, sizeof(LoadPlayer_gfx), defaultSelect) {
}


void scrLoadPlayer::Accept(u8 profile) {
	vScore *score = gameScores->getPlayer(profile);
	if (score->face == 0) return;
	delete this;
	gbaMenu *menu = new mnuPlayer(gameScores->getPlayer(profile), profile);
	menu->buildList();
}


void scrLoadPlayer::Cancel(u8 profile) {
	delete this;
	gbaMenu *menu = new mnuMain();
	menu->buildList();
//	menu->setActive(retVal);
}
