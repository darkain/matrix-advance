/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRFINISHGAME_H_
#define _SCRFINISHGAME_H_


#include <vArm/irq/irqVBlank.h>


class vScore;


class scrFinishGame : public irqVBlank {
	public:
		scrFinishGame(s8 plrProfile, vScore *plrScore);
		scrFinishGame();
		virtual ~scrFinishGame();

		virtual void onVBlank();

	private:
		bool second;
		s8 profile;
		vScore *score;
};

#endif //_SCRFINISHGAME_H_
