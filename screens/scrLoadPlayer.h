/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRLOADPLAYER_H_
#define _SCRLOADPLAYER_H_


#include "scrPlayer.h"


class scrLoadPlayer : public screenPlayer {
	public:
		scrLoadPlayer(u8 defaultSelect=0);
		virtual ~scrLoadPlayer() {}

		virtual void Cancel(u8 profile);
		virtual void Accept(u8 profile);
};

#endif //_SCRLOADPLAYER_H_
