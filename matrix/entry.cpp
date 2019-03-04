/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/irq/gbaInterupt.h>

#include <vArm/phishie/gbaPhishie.h>

#ifndef _MULTIBOOT_
 #include "../menu/mnuMain.h"
#else
 #include "endless.h"
#endif

#include "engine.h"
#include "score.h"


//these lines are required for vList<T>
unsigned int volatile vlistcount = 0;
unsigned int getvListCount() { return vlistcount; }


int main() {
  print("\n\nmain() starting:\n");

  gameScores = new gbaScore();

	screen.setBgEnabled(background2, true);
	screen.setScreenMode(mode3);
	screen.setObjectMap1D();
	screen.setSpritesEnabled(true);

	interupt.setVBlankIRQ(true);
	interupt.setSerialIRQ(true);
//	interupt.setMasterIRQ(true);

#ifndef _MULTIBOOT_
	gbaMenu *menu = new mnuMain();
	menu->buildList();
#else
	engine = new EndlessMatrix;
#endif

  interupt.setMasterIRQ(true);

  screen.lockScreen();
	return 0;
}
