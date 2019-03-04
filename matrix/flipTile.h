/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _FLIPTILE_H_
#define _FLIPTILE_H_


#include <vArm/irq/irqVBlank.h>
#include "streakCounter.h"


class vFlipTile : public vStreakCounter, public irqVBlank {
	public:
		vFlipTile(u8 newx, u8 newy);
		virtual ~vFlipTile();
		virtual void onVBlank();

	private:
		u8 x, y;
		u8 color1;
		u8 color2;
		u16 flipcount;
};

#endif //_FLIPTILE_H_
