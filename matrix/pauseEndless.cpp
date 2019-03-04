/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include <vArm/sprites/gbaSprites.h>
#include "pauseEndless.h"
#include "engine.h"
#include "../resources.h"

#ifndef _MULTIBOOT_
 #include "../menu/mnuMain.h"
#endif


vPauseEndless::vPauseEndless() {
  selected = 0;
	for (int i=0; i<20; i++) sprites[i] = NULL;

	int x=87;
	int y=35;

	u8 count = 0;
	sprites[count] = new vSprite(ED_gfx, 2, 2, 1, 0, false, 14);
	sprites[count]->move(x+83, y+10);

	count++;
	sprites[count] = new vSprite(PAUS_gfx, 4, 4, 1, 1, false, 14);
	sprites[count]->move(x+55, y+10);

	count++;
	sprites[count] = new vSprite(GAME2_gfx, 4, 4, 1, 1, false, 14);
	sprites[count]->move(x+17, y+10);

	count++;
	sprites[count] = new vSprite(Game_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+83, y+35);

	count++;
	sprites[count] = new vSprite(To_gfx, 2, 2, 1, 0, false, 13);
	sprites[count]->move(x+63, y+35);

	count++;
	sprites[count] = new vSprite(rn_gfx, 2, 2, 1, 0, false, 13);
	sprites[count]->move(x+43, y+36);

	count++;
	sprites[count] = new vSprite(Retu_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+15, y+35);

	count++;
	sprites[count] = new vSprite(Again_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+63, y+55);

	count++;
	sprites[count] = new vSprite(Play_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+33, y+55);

	count++;
	sprites[count] = new vSprite(Menu_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+75, y+75);

	count++;
	sprites[count] = new vSprite(To_gfx, 2, 2, 1, 0, false, 13);
	sprites[count]->move(x+55, y+75);

	count++;
	sprites[count] = new vSprite(Exit_gfx, 4, 4, 1, 1, false, 13);
	sprites[count]->move(x+25, y+75);

	for (int i=0; i<=count; i++) {
		sprites[i]->getSpriteEntry()->setPriority(0);
		sprites[i]->show();
	}

	build();
	update();
}


vPauseEndless::~vPauseEndless() {
	for (int i=0; i<20; i++) {
		delete sprites[i];
		sprites[i] = NULL;
	}
}


void vPauseEndless::onInput(u16 prevState) {
  ASSERT(engine != NULL);

  if (getKeyB()) if (prevState & KEYLIST::KEY_B) {
		delete this;
		return;
	}
	if (getKeyA()) if (prevState & KEYLIST::KEY_A) {
		switch (selected) {
		case 0: engine->unPause();	break;
		case 1: engine->resetEngine();	break;
		case 2:
#ifndef _MULTIBOOT_
			engine->setSave(false);
			delete engine;
			engine = NULL;
			delete this;
			gbaMenu *menu = new mnuMain();
			menu->buildList();
			return;
#else
			return;
#endif
		}
		delete this;
		return;
	}
	if (getKeyUp()) if (prevState & KEYLIST::KEY_UP) up();
	if (getKeyDown()) if (prevState & KEYLIST::KEY_DOWN) down();
}


void vPauseEndless::up() {
	if (selected == 0) selected = 2;
	else selected--;
	update();
}

void vPauseEndless::down() {
	if (selected == 2) selected = 0;
	else selected++;
	update();
}


void vPauseEndless::update() {
	for (int i=3; i<20; i++) {
		if (sprites[i]) {
			sprites[i]->getSpriteEntry()->setPaletteNumber(13);
		}
	}

	switch (selected) {
		case 0: {
			sprites[3]->getSpriteEntry()->setPaletteNumber(12);
			sprites[4]->getSpriteEntry()->setPaletteNumber(12);
			sprites[5]->getSpriteEntry()->setPaletteNumber(12);
			sprites[6]->getSpriteEntry()->setPaletteNumber(12);
		} break;

		case 1: {
			sprites[7]->getSpriteEntry()->setPaletteNumber(12);
			sprites[8]->getSpriteEntry()->setPaletteNumber(12);
		} break;

		case 2: {
			sprites[9]->getSpriteEntry()->setPaletteNumber(12);
			sprites[10]->getSpriteEntry()->setPaletteNumber(12);
			sprites[11]->getSpriteEntry()->setPaletteNumber(12);
		} break;
	}
}
