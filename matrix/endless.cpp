/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include <vArm/irq/gbaInterupt.h>

#include "endless.h"
//#include "../entry.h"


EndlessMatrix::EndlessMatrix(s8 profile) : MatrixEngine(profile) {
//	u16 timer3 = REG_TM3D;
//	if (timer3 == 0) setSeed(1);
//	else setSeed(timer3);

	for (int i2=0; i2<16; i2++) {
		for (int i1=0; i1<5; i1++) {
			map1[i2][i1] = dice(1,6);
			map2[i2][i1] = dice(1,6);
		}
	}
	buildPointers();

	setSave(true);
	minutes = 2;
  seconds = 0;

	setLevel(1);
	screen.vSyncLoop();
	refreshMatrix();

//  interupt.setMasterIRQ(true);
}


EndlessMatrix::~EndlessMatrix() {
	if (save) {
		gameScores->addScore(&scores, profile);
		gameScores->saveScores();
	}
}


void EndlessMatrix::resetEngine() {
	MatrixEngine::resetEngine();
	minutes = 2;
	seconds = 0;
	tenthSecond = 0;
	hundrethSecond = 0;

	for (int y=0; y<height; y++) {
		for (int x=0; x<width; x++) {
			map1[y][x] = dice(1,6);
			map2[y][x] = dice(1,6);
			locked[y][x] = 0;
		}
	}
	refreshMatrix();
}
