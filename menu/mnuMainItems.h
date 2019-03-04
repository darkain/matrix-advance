/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MNUMAINITEMS_H_
#define _MNUMAINITEMS_H_


static gbaMnuPart gmnuPlayNow[] = {
	{ 95, 83, 1, 1, 1, 4, Play_gfx }, 
	{ 124, 83, 1, 1, 1, 4, Now_gfx }, 
};

static gbaMnuPart gmnuNewPlayer[] = {
	{ 89, 92, 1, 1, 1, 4, New_gfx }, 
	{ 115, 92, 1, 1, 1, 4, Play_gfx }, 
	{ 139, 93, 1, 0, 1, 2, er_gfx }, 
};

static gbaMnuPart gmnuLoadPlayer[] = {
	{ 86, 101, 1, 1, 1, 4, Load_gfx }, 
	{ 118, 101, 1, 1, 1, 4, Play_gfx }, 
	{ 142, 102, 1, 0, 1, 2, er_gfx }, 
};

static gbaMnuPart gmnuErasePlayer[] = {
	{ 82, 110, 1, 1, 1, 4, Era_gfx }, 
	{ 104, 111, 1, 0, 1, 2, se_gfx }, 
	{ 122, 110, 1, 1, 1, 4, Play_gfx }, 
	{ 146, 111, 1, 0, 1, 2, er_gfx }, 
};

static gbaMnuPart gmnuMultiPlayer[] = {
	{ 86, 119, 1, 1, 1, 4, Multi_gfx }, 
	{ 119, 119, 1, 1, 1, 4, Play_gfx }, 
	{ 143, 120, 1, 0, 1, 2, er_gfx }, 
};

static gbaMnuPart gmnuTopScores[] = {
	{ 87, 128, 1, 1, 1, 4, Top_gfx }, 
	{ 112, 128, 1, 1, 1, 4, Sco2_gfx }, 
	{ 133, 129, 1, 1, 1, 4, res_gfx }, 
};

static gbaMnuPart gmnuOptions[] = {
	{ 98, 137, 1, 1, 1, 4, Optio_gfx }, 
	{ 129, 138, 1, 0, 1, 2, ns_gfx }, 
};

static gbaMnuPart gmnuCredits[] = {
	{ 98, 146, 1, 1, 1, 4, Cre_gfx }, 
	{ 119, 146, 1, 1, 1, 4, dits_gfx }, 
};


static gbaMnuList mnuMainItems[] = {
	{ gmnuPlayNow, 2 },
	{ gmnuNewPlayer, 3 },
	{ gmnuLoadPlayer, 3 },
	{ gmnuErasePlayer, 4 },
	{ gmnuMultiPlayer, 3 },
	{ gmnuTopScores, 3 },
	{ gmnuOptions, 2 },
	{ gmnuCredits, 2 },
};

#endif //_MNUMAINITEMS_H_
