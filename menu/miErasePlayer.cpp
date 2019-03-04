/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "miErasePlayer.h"
#include "../screens/scrErasePlayer.h"


miErasePlayer::miErasePlayer(gbaMnuPart *partList, u16 listCount, gbaMenu *menu)
 : gbaMenuItem(partList, listCount, menu) {
	setDelete(1);
}


void miErasePlayer::onAccept() {
  gbaMenuItem::onAccept();
	new screenErasePlayer();
}
