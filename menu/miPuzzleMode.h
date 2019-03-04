/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MI_PUZZLEMODE_H_
#define _MI_PUZZLEMODE_H_


#include <vArm/menu/gbaMenuItem.h>


class miPuzzleMode : public gbaMenuItem {
	public:
		miPuzzleMode(gbaMnuPart *partList, u16 listCount, gbaMenu *menu, s8 plrProfile);
		virtual ~miPuzzleMode() {}
		virtual void onAccept();

	private:
		s8 profile;
};


#endif //_MI_PUZZLEMODE_H_
