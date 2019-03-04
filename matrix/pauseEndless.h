/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _PAUSEENDLESS_H_
#define _PAUSEENDLESS_H_


#include "pauseEngine.h"


class vPauseEndless : public vPauseEngine {
	public:
		vPauseEndless();
		virtual ~vPauseEndless();

		virtual void onInput(u16 prevState);
		void up();
		void down();
		void update();

	private:
		vSprite *sprites[20];
		u8 selected;
};

#endif //_PAUSEENDLESS_H_
