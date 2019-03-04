/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MI_PLAYNOW_H_
#define _MI_PLAYNOW_H_


#include <vArm/menu/gbaMenuItem.h>


class miPlayNow : public gbaMenuItem {
	public:
		miPlayNow(gbaMnuPart *partList, u16 listCount, gbaMenu *menu, s8 plrProfile=-1);
		virtual ~miPlayNow();

		virtual void onAccept();

	private:
		s8 profile;
};


#endif //_MI_PLAYNOW_H_
