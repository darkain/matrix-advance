/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MNUPLAYERITEMS_H_
#define _MNUPLAYERITEMS_H_


static gbaMnuPart gmnuTimeAttack[] = {
	{ 84, 83, 1, 1, 1, 4, Time_gfx }, 
	{ 114, 83, 1, 1, 1, 4, Atta_gfx }, 
	{ 142, 83, 1, 0, 1, 2, ck_gfx }, 
};

static gbaMnuPart gmnuPuzzleMode[] = {
	{ 85, 92, 1, 1, 1, 4, Puzz_gfx }, 
	{ 113, 92, 1, 0, 1, 2, le2_gfx }, 
	{ 127, 92, 1, 1, 1, 4, Mode_gfx }, 
};

static gbaMnuPart gmnuNewPlayer2[] = {
	{ 89, 101, 1, 1, 1, 4, New_gfx }, 
	{ 115, 101, 1, 1, 1, 4, Play_gfx }, 
	{ 139, 102, 1, 0, 1, 2, er_gfx }, 
};

static gbaMnuPart gmnuLoadPlayer2[] = {
	{ 86, 110, 1, 1, 1, 4, Load_gfx }, 
	{ 118, 110, 1, 1, 1, 4, Play_gfx }, 
	{ 142, 111, 1, 0, 1, 2, er_gfx }, 
};

static gbaMnuPart gmnuErasePlayer2[] = {
	{ 82, 119, 1, 1, 1, 4, Era_gfx }, 
	{ 104, 120, 1, 0, 1, 2, se_gfx }, 
	{ 122, 119, 1, 1, 1, 4, Play_gfx }, 
	{ 146, 120, 1, 0, 1, 2, er_gfx }, 
};


static gbaMnuList mnuPlayerItems[] = {
	{ gmnuTimeAttack, 3 },
	{ gmnuPuzzleMode, 3 },
	{ gmnuNewPlayer2, 3 },
	{ gmnuLoadPlayer2, 3 },
	{ gmnuErasePlayer2, 4 },
	{ gmnuTopScores, 3 },
	{ gmnuOptions, 2 },
	{ gmnuCredits, 2 },
};

#endif //_MNUPLAYERITEMS_H_
