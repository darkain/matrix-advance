/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRERASEPLAYER_H_
#define _SCRERASEPLAYER_H_


#include "scrPlayer.h"


class screenErasePlayer : public screenPlayer {
	public:
		screenErasePlayer(u8 defaultSelect=0);
		virtual ~screenErasePlayer() {}

		virtual void Cancel(u8 profile);
		virtual void Accept(u8 profile);
};

#endif //_SCRERASEPLAYER_H_
