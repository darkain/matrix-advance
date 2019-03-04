/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _PAUSEENGINE_H_
#define _PAUSEENGINE_H_


#include <vArm/irq/irqInput.h>
#include <vArm/palette/gbaFade.h>


class MatrixEngine;
class vSprite;


class vPauseEngine : public irqInput, public gbaPaletteFade {
	public:
		vPauseEngine();
		virtual ~vPauseEngine();
		virtual void onVBlank();
		void build();

	protected:
		u16 count;
		vSprite *bg[4];
};

#endif //_PAUSEENGINE_H_
