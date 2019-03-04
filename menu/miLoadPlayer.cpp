/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "miLoadPlayer.h"
#include "../screens/scrLoadPlayer.h"


miLoadPlayer::miLoadPlayer(gbaMnuPart *partList, u16 listCount, gbaMenu *menu)
 : gbaMenuItem(partList, listCount, menu) {
	setDelete(1);
}


void miLoadPlayer::onAccept() {
  gbaMenuItem::onAccept();
	new scrLoadPlayer();
}

