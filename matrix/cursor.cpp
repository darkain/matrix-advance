/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/display/gbaScreen.h>
#include "../resources.h"
#include "cursor.h"
#include "engine.h"


vCursor::vCursor() : vSprite((u16*)matrixa, 8, 2, 0, 1, true) { 
  
  ASSERT(engine != NULL);
	x = 0;
  y = 0;
//	dma3_32((u32*)matrixa, (u32*)getData(), sizeof(matrixa)>>2);

	marks[4] = new vSprite((u16*)matrixb, 1, 1, 0, 0, false, 0);
	for (int i=0; i<4; i++) marks[i] = new vSprite(marks[4]->getSpriteId());
//	dma3_32((u32*)matrixb, (u32*)marks[4]->getData(), sizeof(matrixb)>>2);
	
	screen.setObjectPaletteEntry(7, RGB(31,31,31));

	update();
	show();
	marks[4]->show();
}


vCursor::~vCursor() {
	for (int i=0; i<5; i++) {
		delete marks[i];
		marks[i] = NULL;
	}
}


void vCursor::moveCursor(u16 newx, u16 newy) {
  ASSERT(engine != NULL);

	x = newx;
	y = newy;

	int offset2 = 6;
	if (newy & 0x01) offset2 = -6;

	int offx = engine->getExtendedX(x, y, false);
	int offy = engine->getExtendedY(x, y, false);

	move(offx, offy);
	marks[4]->move(offx + 85, offy + 4);
	marks[4]->show();

	if (x > 0) {
		marks[0]->move(offx - 8, offy + 4);
		marks[0]->show();
	} else marks[0]->hide();

	if (x < engine->getWidth()-1) {
		marks[1]->move(offx + 16, offy + 4);
		marks[1]->show();
	} else marks[1]->hide();

	if (y > 0) {
		marks[2]->move(offx + 4 + offset2, offy-3);
		marks[2]->show();
	} else marks[2]->hide();

	if (y < engine->getHeight()-1) {
		marks[3]->move(offx + 4 + offset2, offy+11);
		marks[3]->show();
	} else marks[3]->hide();
}


void vCursor::hideCursor() {
	hide();
	for (int i=0; i<5; i++) marks[i]->hide();
}
