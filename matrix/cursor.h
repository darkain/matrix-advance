/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _CURSOR_H_
#define _CURSOR_H_


#include <vArm/Sprites/gbaSprites.h>


class MatrixEngine;


class vCursor : public vSprite/*, public FadePalette*/ {
	public:
		vCursor();
		virtual ~vCursor();

		u16 getCursorX() { return x; }
		u16 getCursorY() { return y; }

		void showCursor() { update();  show(); }
		void hideCursor();

		void moveCursor(u16 newx, u16 newy);
		void update() { moveCursor(x,   y);   }
		void up()     { moveCursor(x,   y-1); }
		void down()   { moveCursor(x,   y+1); }
		void left()   { moveCursor(x-1, y);   }
		void right()  { moveCursor(x+1, y);   }

	protected:
		u16 x;
		u16 y;
		vSprite *marks[5];
};


#endif //_CURSOR_H_
