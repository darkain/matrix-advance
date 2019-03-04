/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/irq/gbaInterupt.h>
#include "miPlayNow.h"
#include "../matrix/endless.h"


miPlayNow::miPlayNow(gbaMnuPart *partList, u16 listCount, gbaMenu *menu, s8 plrProfile)
 : gbaMenuItem(partList, listCount, menu) {
	profile = plrProfile;
	setDelete(1);
}


miPlayNow::~miPlayNow() {
}


void miPlayNow::onAccept() {
  gbaMenuItem::onAccept();

  interupt.setMasterIRQ(false);
	new EndlessMatrix(profile);
  interupt.setMasterIRQ(true);
}

