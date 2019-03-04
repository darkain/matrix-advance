/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MI_ERASEPLAYER_H_
#define _MI_ERASEPLAYER_H_


#include <vArm/menu/gbaMenuItem.h>


class miErasePlayer : public gbaMenuItem {
	public:
		miErasePlayer(gbaMnuPart *partList, u16 listCount, gbaMenu *menu);
		virtual ~miErasePlayer() {}
		virtual void onAccept();
};


#endif //_MI_ERASEPLAYER_H_
