/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _STREAK_H_
#define _STREAK_H_


#include <vArm/tools/gbaTimer.h>


class vSpriteData;
class vSprite;


class vStreak : public gbaTimeCounter {
	public:
		vStreak(vSpriteData *spritedata);
		virtual ~vStreak();

		virtual void onTenthSecond();
		virtual void onSecond();

		bool getTick() { return tick; }
		void setTick(bool t) { tick = t; }

		u16 getPoints();
		void update();

	private:
		vSpriteData *data;
		vSprite *counter[5];
		u8 tick;
};

#endif //_STREAK_H_
