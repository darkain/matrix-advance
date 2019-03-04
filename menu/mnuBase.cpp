/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/phishie/gbaPhishie.h>
#include <colorSpace.h>
#include "mnuBase.h"
#include "../resources.h"


u16 menuColor = RGB(10,10,31);


mnuBase::mnuBase(gbaMnuList *list, u16 listCount)
 : gbaMenu(list, listCount), gbaPaletteFade(toWhite, &menuColor, 289, 289, 2) {
	dma3_32(TitleScreen_gfx, (void*)screen.getDisplay(), ((240*160)>>1));
	dma3fill_32(0, (void*)OAMdata512, 4096);
	dma3fill_32(0, (void*)OAMmem, 128);

	for (int i=0; i<16; i++) {
		screen.setObjectPaletteEntry(i+64, Fish_pal[i]);
	}

	phishies[0] = new gbaPhishie(0, 0, 41, 39);
	phishies[1] = new gbaPhishie(178, 0, 239, 22);
	fishes[0] = new vSprite(Fish_gfx, 4, 2, 0, 1, false, 4);
	fishes[1] = new vSprite(Fish_gfx, 4, 2, 0, 1, false, 4);
	fishes[0]->show();
	fishes[1]->show();
	fishes[1]->getSpriteEntry()->setHFlip(true);
//64
	screen.setObjectPaletteEntry(18, RGB(0,0,0));
	count = 0;
}


mnuBase::~mnuBase() {
	vdelnull(phishies[0]);
	vdelnull(phishies[1]);
	vdelnull(fishes[0]);
	vdelnull(fishes[1]);
}


void mnuBase::Select() {
	blueScreen();
}


void mnuBase::onVBlank() {
	count++;
	gbaPaletteFade::onVBlank();
	if (count == 15) {
		reverseFade();
		count = 0;
	}
}

