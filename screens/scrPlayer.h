/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRPLAYER_H_
#define _SCRPLAYER_H_


#include <colorSpace.h>
#include <vArm/irq/irqInput.h>
#include <vArm/sprites/gbaSprites.h>


class vScore;
class gbaFace;


class screenPlayer : public irqInput {
	public:
		screenPlayer(const u16 *logo, u16 size, u8 defaultSelect=0);
		virtual ~screenPlayer();

		virtual void onInput(u16 prevState);

	protected:
		void Up();
		void Down();
		void LeftRight();
		virtual void Cancel(u8 profile) {}
		virtual void Accept(u8 profile) {}

		void drawBox(u8 box, u16 color=RGB(31,31,31));
		void drawBoxData(u8 box, vScore *player);

	private:
		gbaFace *faces[8];
//		vList<vSprite*> sprites;
    spriteList(sprites);
		u8 cur;
};

#endif //_SCRPLAYER_H_
