/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "scrNewPlayer.h"
#include "scrNameEntry.h"
#include "../menu/mnuMain.h"
#include "../matrix/score.h"
#include "../resources.h"


screenNewPlayer::screenNewPlayer(u8 defaultSelect)
 : screenPlayer(NewPlayer_gfx, sizeof(NewPlayer_gfx), defaultSelect) {
}


void screenNewPlayer::Accept(u8 profile) {
	vScore *score = gameScores->getPlayer(profile);
	if (score->face != 0) return;
	delete this;
	new scrNameEntry(profile, score);
}


void screenNewPlayer::Cancel(u8 profile) {
	delete this;
	gbaMenu *menu = new mnuMain();
	menu->buildList();
//	menu->setActive(retVal);
}
