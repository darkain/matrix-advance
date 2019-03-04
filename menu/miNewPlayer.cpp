/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "miNewPlayer.h"
#include "../screens/scrNewPlayer.h"


miNewPlayer::miNewPlayer(gbaMnuPart *partList, u16 listCount, gbaMenu *menu)
 : gbaMenuItem(partList, listCount, menu) {
	setDelete(1);
}


void miNewPlayer::onAccept() {
  gbaMenuItem::onAccept();
	new screenNewPlayer();
}
