/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MNU_BASE_H_
#define _MNU_BASE_H_


#include <vArm/menu/gbaMenu.h>
#include <vArm/palette/gbaFade.h>


class gbaPhishie;
class vSprite;


class mnuBase : public gbaMenu, public gbaPaletteFade {
	public:
		mnuBase(gbaMnuList *list, u16 listCount);
		virtual ~mnuBase();

		virtual void Select();
		virtual void onVBlank();
		virtual void onFadeComplete() { reverseFade(); count=0; }

	protected:
		gbaPhishie *phishies[2];
		vSprite *fishes[2];
		u16 count;
};


#endif //_MNU_BASE_H_
