/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRNEWPLAYER_H_
#define _SCRNEWPLAYER_H_


#include "scrPlayer.h"


class screenNewPlayer : public screenPlayer {
	public:
		screenNewPlayer(u8 defaultSelect=0);
		virtual ~screenNewPlayer() {}

		virtual void Cancel(u8 profile);
		virtual void Accept(u8 profile);
};

#endif //_SCRNEWPLAYER_H_
