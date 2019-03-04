/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include "scrSunset.h"
#include "../menu/mnuMain.h"
#include "../resources.h"


vSunset::vSunset() {
	dma3_32(sunset_gfx, (void*)screen.getDisplay(), sizeof(sunset_gfx)>>2);
	setInputEnabled(true);
}


void vSunset::onInput(u16 prevState) {
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) { del(); return; }
	if (getKeyB()) if (prevState & KEYLIST::KEY_B) { del(); return; }
	if (getKeyStart()) if (prevState & KEYLIST::KEY_START) { del(); return; }
}


void vSunset::del() {
  delete this;
  gbaMenu *menu = new mnuMain();
  menu->buildList();
}
