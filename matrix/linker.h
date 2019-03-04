/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _LINKER_H_
#define _LINKER_H_


#include <vArm/irq/irqVBlank.h>


class MatrixEngine;
class vSwitchTile;


class vLinker : public irqVBlank {
	public:
		vLinker(u8 newx, u8 newy, u8 basecolor, u8 sidecolor);
		virtual ~vLinker();
		virtual void onVBlank();

		void resetTime();

		u8 getX() { return x; }
		u8 getY() { return y; }
		void setX(u8 newx) { x = newx; }
		void setY(u8 newy) { y = newy; }
		void move(u8 newx, u8 newy) { setX(newx); setY(newy); }

		void setPalettes(u8 pal0, u8 pal1) { pals[0] = pal0; pals[1] = pal1; }
		void setSwitchTile(vSwitchTile *sTile) { tile = sTile; }
		void updateDisplay();

	private:
		vSwitchTile *tile;
		u16 links;
		u8 x;
		u8 y;
		u8 color;
		u8 color2;
		u8 count;
		u8 flash;
		u8 pals[2];
};

#endif //_LINKER_H_
