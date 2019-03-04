/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include "switchTile.h"
#include "linker.h"
#include "engine.h"
#include "../resources.h"


vSwitchTile::vSwitchTile(u8 newx1, u8 newy1, u8 newx2, u8 newy2) : irqVBlank(3) {
  ASSERT(engine != NULL);

  count = 0;

	x1 = newx1;
	y1 = newy1;
	x2 = newx2;
	y2 = newy2;

	ex[0] = engine->getExtendedX(x1, y1, false);
	ey[0] = engine->getExtendedY(x1, y1, false);
	ex[1] = engine->getExtendedX(x2, y2, false);
	ey[1] = engine->getExtendedY(x2, y2, false);

	ex[2] = engine->getExtendedX(x1, y1, true);
	ey[2] = engine->getExtendedY(x1, y1, true);
	ex[3] = engine->getExtendedX(x2, y2, true);
	ey[3] = engine->getExtendedY(x2, y2, true);

	colors[0] = engine->getTile(x1, y1);
	colors[1] = engine->getTile(x2, y2);
	colors[2] = engine->getTile2(x1, y1);
	colors[3] = engine->getTile2(x2, y2);

	engine->setTile(x1, y1, 0);
	engine->setTile(x2, y2, 0);
	engine->setTile2(x1, y1, 0);
	engine->setTile2(x2, y2, 0);

	eraseTiles2();

	linker[0] = engine->getLinker(x1, y1);
	linker[1] = engine->getLinker(x2, y2);
	
	if (linker[0]) {
		linker[0]->setSwitchTile(this);
		linker[0]->setPalettes(128, 160);
	}
	if (linker[1]) {
		linker[1]->setSwitchTile(this);
		linker[1]->setPalettes(144, 176);
	}

	if (ex[0] < ex[1]) xChange = 1;
	else if (ex[0] > ex[1]) xChange = -1;
	else xChange = 0;
	
	if (ey[0] < ey[1]) yChange = 1;
	else if (ey[0] > ey[1]) yChange = -1;
	else yChange = 0;

	if (ey[0] != ey[1]) {
		maxCount = 7;
	} else {
		maxCount = 11;
		setVBlankCount(2);
	}

	data = new vSpriteData(Hex_gfx, 4);

	for (int i2=0; i2<4; i2++) {
		const u16 *colorSet = matrixPalette + (colors[i2]*6);
		for (int i=1; i<7; i++) {
			screen.setObjectPaletteEntry(128+i+(i2*16), colorSet[i]);
		}
	}

	for (int i=0; i<4; i++) {
		sprites[i] = new vSprite(data, 4, 2, 0, 1, false, 8+i);
		sprites[i]->getSpriteEntry()->setPriority(2);
		sprites[i]->show();
	}

	updateLocations();
}


vSwitchTile::~vSwitchTile() {
  ASSERT(engine != NULL);

  engine->setTile(x1, y1, colors[1]);
	engine->setTile(x2, y2, colors[0]);
	engine->setTile2(x1, y1, colors[3]);
	engine->setTile2(x2, y2, colors[2]);

	engine->drawTile(x1, y1, colors[1], false);
	engine->drawTile(x2, y2, colors[0], false);
	engine->drawTile(x1, y1, colors[3], true);
	engine->drawTile(x2, y2, colors[2], true);

	if (linker[0]) linker[0]->setSwitchTile(NULL);
	if (linker[1]) linker[1]->setSwitchTile(NULL);

	for (int i=0; i<4; i++) delete sprites[i];
	delete data;

	if ( (x1 == engine->getX()) & (y1 == engine->getY()) ) {
		engine->moveCursor(x2, y2);
	} else {
		engine->moveCursor(x1, y1);
	}

	engine->setSwitchTile(NULL);
	engine->buildTempMap(x1, y1, 1);
	engine->buildTempMap(x2, y2, 1);
}


void vSwitchTile::removeLinker(vLinker *link) {
	if (linker[0] = link) linker[0] = NULL;
	if (linker[1] = link) linker[1] = NULL;
}


void vSwitchTile::paintTiles() {
  ASSERT(engine != NULL);

  for (int i=0; i<4; i++) sprites[i]->hide();

	int x, y;
	u16 *dest;

	dest = engine->getTilePointer(x1, y1, false);
	x = ex[1] - engine->getExtendedX(x1, y1, false);
	y = ey[1] - engine->getExtendedY(x1, y1, false);
	dest += x;
	dest += (y * 240);
	paintTile(dest, colors[1]);

	dest = engine->getTilePointer(x2, y2, false);
	x = ex[0] - engine->getExtendedX(x2, y2, false);
	y = ey[0] - engine->getExtendedY(x2, y2, false);
	dest += x;
	dest += (y * 240);
	paintTile(dest, colors[0]);

	dest = engine->getTilePointer(x1, y1, true);
	x = ex[3] - engine->getExtendedX(x1, y1, true);
	y = ey[3] - engine->getExtendedY(x1, y1, true);
	dest += x;
	dest += (y * 240);
	paintTile(dest, colors[3]);

	dest = engine->getTilePointer(x2, y2, true);
	x = ex[2] - engine->getExtendedX(x2, y2, true);
	y = ey[2] - engine->getExtendedY(x2, y2, true);
	dest += x;
	dest += (y * 240);
	paintTile(dest, colors[2]);
}


void vSwitchTile::eraseTiles() {
  ASSERT(engine != NULL);

  for (int i=0; i<4; i++) sprites[i]->show();

	int x, y;
	u16 *dest;

	dest = engine->getTilePointer(x1, y1, false);
	x = ex[1] - engine->getExtendedX(x1, y1, false);
	y = ey[1] - engine->getExtendedY(x1, y1, false);
	dest += x;
	dest += (y * 240);
	paintBlackTile(dest);

	dest = engine->getTilePointer(x2, y2, false);
	x = ex[0] - engine->getExtendedX(x2, y2, false);
	y = ey[0] - engine->getExtendedY(x2, y2, false);
	dest += x;
	dest += (y * 240);
	paintBlackTile(dest);

	dest = engine->getTilePointer(x1, y1, true);
	x = ex[3] - engine->getExtendedX(x1, y1, true);
	y = ey[3] - engine->getExtendedY(x1, y1, true);
	dest += x;
	dest += (y * 240);
	paintBlackTile(dest);

	dest = engine->getTilePointer(x2, y2, true);
	x = ex[2] - engine->getExtendedX(x2, y2, true);
	y = ey[2] - engine->getExtendedY(x2, y2, true);
	dest += x;
	dest += (y * 240);
	paintBlackTile(dest);
}


void vSwitchTile::eraseTiles2() {
  ASSERT(engine != NULL);
	engine->eraseTile(x1, y1, false);
	engine->eraseTile(x2, y2, false);
	engine->eraseTile(x1, y1, true);
	engine->eraseTile(x2, y2, true);
}


void vSwitchTile::updateLocations() {
	for (int i=0; i<4; i++) sprites[i]->move(ex[i], ey[i]);
}


void vSwitchTile::onVBlank() {
  ASSERT(engine != NULL);
	if (engine->isPaused()) return;

	count++;
	if (count == maxCount) {
		delete this;
		return;
	}

	ex[0] += xChange;
	ey[0] += yChange;
	
	ex[1] -= xChange;
	ey[1] -= yChange;
	
	ex[2] += xChange;
	ey[2] += yChange;

	ex[3] -= xChange;
	ey[3] -= yChange;

	updateLocations();
}
