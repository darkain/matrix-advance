/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "cluster.h"
#include "engine.h"


vCluster::vCluster(u8 *map, u16 mapcolor) : irqVBlank(6) { //4 seconds
  ASSERT(map != NULL);
  ASSERT(engine != NULL);

	color = mapcolor;
	flipcount = 0;

	u8 *cmap = (u8*) clustermap;
	for (int i=0; i <5*16; i++) {
		cmap[i] = map[i];
	}

//	setSeed(REG_TM3D);  //gotta add this to teh function (REG_TM3D)
	for (int i2=0; i2<engine->getHeight(); i2++) {
		for (int i1=0; i1<engine->getWidth(); i1++) {
			if (clustermap[i2][i1]) newmap[i2][i1] = engine->randomTile();
			else newmap[i2][i1] = 0;
		}
	}
}


vCluster::~vCluster() {
  ASSERT(engine != NULL);
	engine->onClusterClear(this);
}


void vCluster::onVBlank() {
  ASSERT(engine != NULL);
	if (engine->isPaused()) return;

	flipcount++;

	if (flipcount == 32) {
		for (int i2=0; i2<engine->getHeight(); i2++) {
			for (int i1=0; i1<engine->getWidth(); i1++) {
				if (clustermap[i2][i1]) {
					u16 tile1 = newmap[i2][i1];
					u16 tile2 = engine->getTile2(i1,i2);
					if (tile2 > 7) tile2 -= 8;
					engine->setTile(i1, i2, tile2);
					engine->setTile2(i1, i2, tile1);
					engine->drawTile1(i1, i2, tile2);
					engine->drawTile2(i1, i2, tile1);
					engine->setLocked(i1, i2, false);
				}
			}
		}
		
		for (int i2=0; i2<engine->getHeight(); i2++) {
			for (int i1=0; i1<engine->getWidth(); i1++) {
				if (clustermap[i2][i1]) {
					engine->buildTempMap(i1, i2);
				}
			}
		}

		engine->updateCursor();
		delete this;
		return;
	}

	if (color > 7) color -= 8;
	else color += 8;

	for (int i2=0; i2<engine->getHeight(); i2++) {
		for (int i1=0; i1<engine->getWidth(); i1++) {
			if (clustermap[i2][i1]) {
				u16 color2 = engine->getTile2(i1, i2);
				engine->drawFlipTile1(i1, i2, color, color2, flipcount);
				if (color > 7) color2 += 8;
				engine->drawFlipTile2(i1, i2, color2, newmap[i2][i1], flipcount);
			}
		}
	}
}
