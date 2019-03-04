/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MI_NEWPLAYER_H_
#define _MI_NEWPLAYER_H_


#include <vArm/menu/gbaMenuItem.h>


class miNewPlayer : public gbaMenuItem {
	public:
		miNewPlayer(gbaMnuPart *partList, u16 listCount, gbaMenu *menu);
		virtual ~miNewPlayer() {}
		virtual void onAccept();
};


#endif //_MI_NEWPLAYER_H_
