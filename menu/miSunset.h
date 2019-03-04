/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MI_SUNSET_H_
#define _MI_SUNSET_H_


#include <vArm/menu/gbaMenuItem.h>


class miSunset : public gbaMenuItem {
	public:
		miSunset(gbaMnuPart *partList, u16 listCount, gbaMenu *menu);
		virtual ~miSunset() {}
		virtual void onAccept();
};


#endif //_MI_SUNSET_H_
