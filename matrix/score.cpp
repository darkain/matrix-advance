/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>

#include "score.h"
#include "string.h"

volatile sRam *saveRam = ((volatile sRam*)0x0E000000);
gbaScore *gameScores;


gbaScore::gbaScore() {
	loadScores();
}


gbaScore::~gbaScore() {
}


void gbaScore::loadScores() {
#ifdef _MULTIBOOT_
	memset((void*)scores, 0, sizeof(scores)>>2);
	memset((void*)players, 0, sizeof(players)>>2);

#else
	u8 sram1[16];
	u8 sram2[16] = "MATRIX ADVANCE_";
	u8 *sram = (u8*)saveRam;

	for (int i=0; i<16; i++) {
		sram1[i] = sram[i];
	}

	if (memcmp(sram2, sram1, 16) != 0) {
		for (int i=0; i<16; i++) sram[i] = sram2[i];
		memset((void*)scores, 0, sizeof(scores)>>2);
		memset((void*)players, 0, sizeof(players)>>2);
		saveScores();
	} else {
		
		u8 *src = (u8*)saveRam->topScores;
		u8 *dst = (u8*)scores;
		for (u32 i=0; i<sizeof(scores); i++) dst[i] = src[i];

		src = (u8*)saveRam->saves;
		dst = (u8*)players;
		for (u32 i=0; i<sizeof(players); i++) dst[i] = src[i];
	}
#endif//_MULTIBOOT_
}


void gbaScore::saveScores() {
#ifndef _MULTIBOOT_
	u8 *src = (u8*)scores;
	u8 *dst = (u8*)saveRam->topScores;
	for (u32 i=0; i<sizeof(scores); i++) dst[i] = src[i];

	src = (u8*)players;
	dst = (u8*)saveRam->saves;
	for (u32 i=0; i<sizeof(players); i++) dst[i] = src[i];
#endif//_MULTIBOOT_
}


u8 gbaScore::addScore(vScore *score, s8 profile) {
	u8 highScore = 0;

	if (profile >= 0) {
		if (players->points < score->points) {
			memcpy((void*)&players[profile], (void*)score, sizeof(vScore));
			highScore = 0x80;
		}
	}
/*
	for (int i=0; i<10; i++) {
		if (scores[i].face == 0) {
			memcpy((void*)&scores[i], (void*)score, sizeof(vScore));
			return i | highScore;
		}
	}
*/
	for (int i=0; i<10; i++) {
		if (scores[i].points <= score->points) {
			insertScore(i);
			memcpy((void*)&scores[i], (void*)score, sizeof(vScore));
			return i | highScore;
		}
	}

	return highScore;
}


void gbaScore::insertScore(u8 place) {
//	u8 *src = (u8*)&scores[place];
//	u8 *dst = src + 32;
	
	for (int i=8; i>=place; i--) {
		copyScore(i, i+1);
	}

}


void gbaScore::copyScore(u8 source, u8 dest) {
	u8 *src = (u8*)&scores[source];
	u8 *dst = (u8*)&scores[dest];
	for (u32 i=0; i<sizeof(vScore); i++) dst[i] = src[i];
}
