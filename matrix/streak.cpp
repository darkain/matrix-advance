/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/sprites/gbaSprites.h>
#include "streak.h"
#include "engine.h"


vStreak::vStreak(vSpriteData *spritedata) {
  ASSERT(spritedata!=NULL);
  data = spritedata;

	tick = false;
	counter[0] = NULL;

	counter[1] = new vSprite(data, 20, 10, 0, 0, false, 4);
	counter[1]->move(47, 45);
//	counter[1]->show();

	counter[2] = new vSprite(data, 20, 10, 0, 0, false, 4);
	counter[2]->move(54, 45);
	counter[2]->show();

	counter[3] = new vSprite(data, 20, 10, 0, 0, false, 4);
	counter[3]->move(63, 45);
	counter[3]->show();

	counter[4] = new vSprite(data, 20, 10, 0, 0, false, 4);
	counter[4]->move(70, 45);
	counter[4]->show();
}


vStreak::~vStreak() {
	for (int i=0; i<5; i++) {
		delete counter[i];
	}
}


u16 vStreak::getPoints() {
	u16 points = seconds <<1;
	points += (minutes * 120);
	if (tenthSecond > 4) points++;
	return points;
}


void vStreak::onTenthSecond() {
	gbaSpriteEntry *entry = counter[3]->getSpriteEntry();
	entry->setDataId(data->getDataIdOffset(tenthSecond));
}


void vStreak::onSecond() {
  ASSERT(engine != NULL);

	gbaSpriteEntry *entry;
	int supSecond = (int)(seconds * 0.1);
	int subSecond = seconds - (supSecond * 10);
	
	entry = counter[2]->getSpriteEntry();
  ASSERT(entry != NULL);
  entry->setDataId(data->getDataIdOffset(subSecond));

	entry = counter[1]->getSpriteEntry();
  ASSERT(entry != NULL);
	entry->setDataId(data->getDataIdOffset(supSecond));

	if (supSecond) counter[1]->show();

	switch (seconds) {
		case 4: 	engine->setPoints(engine->getPoints() + 50);   break;
		case 7: 	engine->setPoints(engine->getPoints() + 100);  break;
		case 12:	engine->setPoints(engine->getPoints() + 200);  break;
		case 18:	engine->setPoints(engine->getPoints() + 400);  break;
		case 24:	engine->setPoints(engine->getPoints() + 800);  break;
		case 28:	engine->setPoints(engine->getPoints() + 1000); break;
		case 32:	engine->setPoints(engine->getPoints() + 1200); break;
		case 40:	engine->setPoints(engine->getPoints() + 1400); break;
		case 50:	engine->setPoints(engine->getPoints() + 2000); break;
	}
}


void vStreak::update() {
	tick ^= 0x1;
	if (tick) {
		increment();

		int dataid;
		switch (hundrethSecond) {
			case 0: dataid = 0; break;
			case 1: dataid = 1; break;
			case 2: dataid = 3; break;
			case 3: dataid = 5; break;
			case 4: dataid = 6; break;
			case 5: dataid = 8; break;
		}
		gbaSpriteEntry *entry = counter[4]->getSpriteEntry();
    ASSERT(entry != NULL);
		entry->setDataId(data->getDataIdOffset(dataid));
	}
}
