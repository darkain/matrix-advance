/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include <colorSpace.h>
#include "pauseEngine.h"
#include "engine.h"
#include "../resources.h"


u16 pauseColor = RGB(31,0,0);


vPauseEngine::vPauseEngine() : gbaPaletteFade(toBlack, &pauseColor, 449, 449, 2) {
  ASSERT(engine != NULL);

	engine->pause();
	engine->setInputEnabled(false);
	engine->hideCursor();

	//needsta make functions for these
	REG_BLDMOD = 0x0F00;
	REG_COLEV = 0x021F;
	REG_COLEY = 0x0000;

	count = 0;

	screen.setObjectPaletteEntry(241, 0x2108);
	screen.setObjectPaletteEntry(242, 0x4210);
	screen.setObjectPaletteEntry(243, 0x5294);
	screen.setObjectPaletteEntry(244, 0x6739);
	screen.setObjectPaletteEntry(245, 0x7FFF);

//	screen.setObjectPaletteEntry(224, 0x5294);
	screen.setObjectPaletteEntry(225, RGB(31,31,31));
//	screen.setObjectPaletteEntry(193, RGB(10,31,10));
}


vPauseEngine::~vPauseEngine() {
  ASSERT(engine != NULL);

	for (int i=0; i<4; i++) {
		delete bg[i];
		bg[i] = NULL;
	}

	engine->unPause();
	engine->setInputEnabled(true);
	engine->showCursor();
}


void vPauseEngine::build() {
	int x=87;
	int y=35;

	bg[0] = new vSprite(box1_gfx, 64, 8, 0, 3, false, 15);
	bg[0]->move(x,y);

	bg[1] = new vSprite(box2_gfx, 64, 8, 0, 3, false, 15);
	bg[1]->move(x+64,y);

	bg[2] = new vSprite(box3_gfx, 32, 8, 1, 3, false, 15);
	bg[2]->move(x,y+64);

	bg[3] = new vSprite(box4_gfx, 32, 8, 1, 3, false, 15);
	bg[3]->move(x+64,y+64);

	for (int i=0; i<4; i++) {
		gbaSpriteEntry *entry = bg[i]->getSpriteEntry();
		entry->setAlpha(1);
		entry->setPriority(1);
		bg[i]->show();
	}
}


void vPauseEngine::onVBlank() {
	setInputEnabled(true);
	count++;
	gbaPaletteFade::onVBlank();
	if (count == 8) {
		reverseFade();
		count = 0;
	}
}
