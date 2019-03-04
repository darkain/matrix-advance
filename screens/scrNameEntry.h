/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRNAMEENTRY_H_
#define _SCRNAMEENTRY_H_


#include <vArm/irq/irqInput.h>


class vScore;
class gbaFace;
class vSprite;


class scrNameEntry : public irqInput {
	public:
		scrNameEntry(u8 profileId, vScore *ptrProfile);
		virtual ~scrNameEntry();

		virtual void onInput(u16 prevState);

		void Accept();
		void Cancel();
		void Left();
		void Right();
		void Up();
		void Down();
		void R();
		void L();

		void updateCursor();
		void updateFace();
		void updateName();

		void Exit();
		void Enter();

	private:
		u8 profile;
		u8 row;
		u8 col;
		u8 section;
		u8 faceId;
		u8 len;
		gbaFace *face;
		vScore *player;
		vSprite *cursor;
};

#endif //_SCRNAMEENTRY_H_
