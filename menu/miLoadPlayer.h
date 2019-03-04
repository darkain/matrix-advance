/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MI_LOADPLAYER_H_
#define _MI_LOADPLAYER_H_


#include <vArm/menu/gbaMenuItem.h>


class miLoadPlayer : public gbaMenuItem {
	public:
		miLoadPlayer(gbaMnuPart *partList, u16 listCount, gbaMenu *menu);
		virtual ~miLoadPlayer() {}
		virtual void onAccept();
};


#endif //_MI_LOADPLAYER_H_
