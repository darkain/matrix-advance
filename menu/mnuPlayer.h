/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MNU_PLAYER_H_
#define _MNU_PLAYER_H_


#include "mnuBase.h"


class vScore;
class mnuPlayer;


class mnuPlayer : public mnuBase {
	public:
		mnuPlayer(vScore *plr, s8 plrProfile);
		virtual ~mnuPlayer();

		virtual void Cancel();

	protected:
		virtual void onChange(u16 selected);
		virtual void onListBuilt();
		virtual gbaMenuItem *newMenuItem(gbaMnuPart *partList, u16 listCount);

	private:
		static u16 lastId;
		s8 profile;
		vScore *player;
};


#endif //_MNU_PLAYER_H_
