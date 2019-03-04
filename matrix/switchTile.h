/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SWITCHTILE_H_
#define _SWITCHTILE_H_


#include <vArm/irq/irqVBlank.h>
#include <vArm/sprites/gbaSprites.h>
#include "streakCounter.h"


class vLinker;


class vSwitchTile : public vStreakCounter, public irqVBlank {
	public:
		vSwitchTile(u8 newx1, u8 newy1, u8 newx2, u8 newy2);
		virtual ~vSwitchTile();

		virtual void onVBlank();
		void updateLocations();

		void removeLinker(vLinker *link);

		void paintTiles();
		void eraseTiles();
		void eraseTiles2();

		u8 getColor(u8 entry) { return colors[entry]; }

	private:
		u8  x1,  y1,  x2,  y2;
		s16 ex[4];
		s16 ey[4];
//		u8 ex1, ey1, ex2, ey2;
//		u8 ex3, ey3, ex4, ey4;
		u8 colors[4];
		s16 xChange;
		s16 yChange;

		u16 count;
		u16 maxCount;

		vSpriteData *data;
		vSprite *sprites[4];
		vLinker *linker[2];
};

#endif //_SWITCHTILE_H_
