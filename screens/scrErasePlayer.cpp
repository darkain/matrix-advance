/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "scrErasePlayer.h"
#include "../matrix/score.h"
#include "../menu/mnuMain.h"
#include "../resources.h"


screenErasePlayer::screenErasePlayer(u8 defaultSelect)
 : screenPlayer(ErasePlayer_gfx, sizeof(ErasePlayer_gfx), defaultSelect) {
}


void screenErasePlayer::Accept(u8 profile) {
	vScore *score = gameScores->getPlayer(profile);
	if (score->face == 0) return;

	memset((void*)score, 0, sizeof(vScore));

	Cancel(profile);
}


void screenErasePlayer::Cancel(u8 profile) {
	delete this;
	gbaMenu *menu = new mnuMain();
	menu->buildList();
//	menu->setActive(retVal);
}
