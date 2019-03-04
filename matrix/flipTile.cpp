/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "flipTile.h"
#include "engine.h"


vFlipTile::vFlipTile(u8 newx, u8 newy) : irqVBlank(6) {
  ASSERT(engine != NULL);

  engine->setFlipTile(this);
	x = newx;
	y = newy;
	color1 = engine->getTile(x, y);
	color2 = engine->getTile2(x, y);
	flipcount = 0;
}


vFlipTile::~vFlipTile() {
  ASSERT(engine != NULL);

  engine->setTile(x, y, color2);
	engine->setTile2(x, y, color1);
	engine->drawTile(x, y, color2, false);
	engine->drawTile(x, y, color1, true);
	engine->buildTempMap(x, y, 2);
	engine->setFlipTile(NULL);
}


void vFlipTile::onVBlank() {
  ASSERT(engine != NULL);
	if (engine->isPaused()) return;

	flipcount++;
	if (flipcount == 4) {
		delete this;
		return;
	}
	engine->drawFlipTile(x, y, color1, color2, flipcount+28, false);
	engine->drawFlipTile(x, y, color2, color1, flipcount+28, true);
}
