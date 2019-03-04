/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "miPuzzleMode.h"
#include "../matrix/puzzle.h"


miPuzzleMode::miPuzzleMode(gbaMnuPart *partList, u16 listCount, gbaMenu *menu, s8 plrProfile)
 : gbaMenuItem(partList, listCount, menu) {
	profile = plrProfile;
	setDelete(1);
}


void miPuzzleMode::onAccept() {
  gbaMenuItem::onAccept();
	new PuzzleMatrix(1, profile);
}
