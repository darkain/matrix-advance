/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include "linker.h"
#include "switchTile.h"
#include "engine.h"
#include "../resources.h"


vLinker::vLinker(u8 newx, u8 newy, u8 basecolor, u8 sidecolor) : irqVBlank(2) {
  ASSERT(engine != NULL);

	tile = NULL;
	links = 0;
	count = 0;
	pals[0] = 0;
	pals[1] = 0;
	x = newx;
	y = newy;
	color = basecolor;
	color2 = sidecolor;
	flash = 0;
	engine->addLinker(this);
}


vLinker::~vLinker() {
  ASSERT(engine != NULL);

	flash = 4;
	updateDisplay();
	if (tile) tile->removeLinker(this);
	if (engine->clearLinker()) {
		engine->setTile(x, y, 0);
		engine->drawTile(x, y, 0, false);
	}
	engine->delLinker(this);
}


void vLinker::resetTime() {
	count = 0;
	links++;
	engine->addPoints(250 * links);
}


void vLinker::updateDisplay() {
  ASSERT(engine != NULL);

  if (tile) {
		if (flash == 2) {
			const u16 *colorSet = matrixPalette + (7*6);
			for (int i=1; i<7; i++) {
				screen.setObjectPaletteEntry(pals[0]+i, colorSet[i]);
			}
			
			colorSet = matrixPalette + (7*6);
			for (int i=1; i<7; i++) {
				screen.setObjectPaletteEntry(pals[1]+i, colorSet[i]);
			}

		} else if (flash == 4) {
			const u16 *colorSet = matrixPalette + (color*6);
			for (int i=1; i<7; i++) {
				screen.setObjectPaletteEntry(pals[0]+i, colorSet[i]);
			}
			
			colorSet = matrixPalette + (color2*6);
			for (int i=1; i<7; i++) {
				screen.setObjectPaletteEntry(pals[1]+i, colorSet[i]);
			}

		} else {
			const u16 *colorSet = matrixPalette + ((color+8)*6);
			for (int i=1; i<7; i++) {
				screen.setObjectPaletteEntry(pals[0]+i, colorSet[i]);
			}
			
			colorSet = matrixPalette + ((color2+8)*6);
			for (int i=1; i<7; i++) {
				screen.setObjectPaletteEntry(pals[1]+i, colorSet[i]);
			}
		}
	}

	else {
		if (flash == 2) {
			engine->drawTile(x, y, 7, false);
			engine->drawTile(x, y, 7, true);
		} else if (flash == 4) {
			engine->drawTile(x, y, color, false);
			engine->drawTile(x, y, color2, true);
		} else {
			engine->drawTile(x, y, color+8, false);
			engine->drawTile(x, y, color2+8, true);
		}
	}
}


void vLinker::onVBlank() {
  ASSERT(engine != NULL);
	if (engine->isPaused()) return;

	count++;
	if (count == 94) {
		delete this;
		return;
	}

	flash++;
	updateDisplay();	
	if (flash == 4) flash = 0;
}

