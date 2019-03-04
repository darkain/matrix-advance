/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/tools/gbaStringx.h>
#include <vArm/display/gbaScreen.h>
#include "scrTopScores.h"
#include "../matrix/score.h"
#include "../menu/mnuMain.h"
#include "../resources.h"


screenTopScores::screenTopScores() : irqInput(true) {
	dma3_32(topscores_gfx, (void*)screen.getDisplay(), sizeof(topscores_gfx)>>2);

	for (int i=0; i<10; i++) {
		vScore *score = gameScores->getScore(i);
		if (score->points) {
			char str[8];
			int y = 44 + (i*11);
			screen.drawString(score->name, 2, y, RGB(31,31,31));
			
			for (int i=0; i<5; i++) str[i] = '0';
			if (score->points < 10) intToString(score->points, str+4);
			else if (score->points < 100) intToString(score->points, str+3);
			else if (score->points < 1000) intToString(score->points, str+2);
			else if (score->points < 10000) intToString(score->points, str+1);
			else intToString(score->points, str);

			for (int x=0; x<5; x++) {
				screen.drawCharacter3(str[x], (x*7)+45, y, RGB(31,31,31));
			}

			str[0] = '0';
			if (score->totalCombos < 10) intToString(score->totalCombos, str+1);
			else intToString(score->totalCombos, str);

			for (int x=0; x<2; x++) {
				screen.drawCharacter3(str[x], (x*7)+102, y, RGB(31,31,31));
			}

			str[0] = '0';
			if (score->maxCombo < 10) intToString(score->maxCombo, str+1);
			else intToString(score->maxCombo, str);

			for (int x=0; x<2; x++) {
				screen.drawCharacter3(str[x], (x*7)+84, y, RGB(31,31,31));
			}


			//verify this section... str+3 seems too damn big
			str[0] = '0';
			str[1] = '0';
			if (score->totalClusters < 10) intToString(score->totalClusters, str+3);
			if (score->totalClusters < 100) intToString(score->totalClusters, str+2);
			else intToString(score->totalClusters, str);

			for (int x=0; x<3; x++) {
				screen.drawCharacter3(str[x], (x*7)+138, y, RGB(31,31,31));
			}

			str[0] = '0';
			if (score->maxCluster < 10) intToString(score->maxCluster, str+1);
			else intToString(score->maxCluster, str);

			for (int x=0; x<2; x++) {
				screen.drawCharacter3(str[x], (x*7)+120, y, RGB(31,31,31));
			}

			str[0] = '0';
			if (score->totalLinkers < 10) intToString(score->totalLinkers, str+1);
			else intToString(score->totalLinkers, str);

			for (int x=0; x<2; x++) {
				screen.drawCharacter3(str[x], (x*7)+181, y, RGB(31,31,31));
			}

			str[0] = '0';
			if (score->maxLinker < 10) intToString(score->maxLinker, str+1);
			else intToString(score->maxLinker, str);

			for (int x=0; x<2; x++) {
				screen.drawCharacter3(str[x], (x*7)+163, y, RGB(31,31,31));
			}

			//add streak stuffz

		}
	}
}


screenTopScores::~screenTopScores() {
}


void screenTopScores::onInput(u16 prevState) {
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) { del(); return; }
	if (getKeyB()) if (prevState & KEYLIST::KEY_B) { del(); return; }
	if (getKeyStart()) if (prevState & KEYLIST::KEY_START) { del(); return; }
}


void screenTopScores::del() {
		delete this;
		gbaMenu *menu = new mnuMain();
		menu->buildList();
}
