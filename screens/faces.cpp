/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/gbaInlines.h>
#include <vArm/display/gbaScreen.h>
#include "faces.h"
#include "../resources.h"


gbaFace::gbaFace(u8 newx, u8 newy, const void *rawdata) {
	x = newx;
	y = newy;
	data = rawdata;
	paintFace();
}


gbaFace::gbaFace(u8 newx, u8 newy, u8 newId) {
	x = newx;
	y = newy;
	
	switch (newId) {
		case 1: data = face1_gfx; break;
		case 2: data = face2_gfx; break;
		case 3: data = face3_gfx; break;
		case 4: data = face4_gfx; break;
		case 5: data = face5_gfx; break;
		case 6: data = face6_gfx; break;
		case 7: data = face7_gfx; break;
		case 8: data = face8_gfx; break;
		default: data = NULL;
	}
	paintFace();
}


void gbaFace::paintFace() {
	u16 *src = (u16*) data;
	u16 *dest = (u16*) screen.getDisplay() + (y*240) + x;
	for (int i=0; i<32; i++) {
		dma3_16(src, dest, 32);
		src += 32;
		dest += 240;
	}
}

