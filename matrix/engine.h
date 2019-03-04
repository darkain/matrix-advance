/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _ENGINE_H_
#define _ENGINE_H_


#include <vArm/tools/gbaTimer.h>
#include <vArm/irq/irqInput.h>
#include <vArm/irq/irqVBlank.h>
//#include <vArm/display/gbaScreen.h>
//#include <vArm/sprites/gbaSprites.h>
//#include <vArm/palette/gbaFade.h>
//#include "../entry.h"
#include "score.h"
#include "cursor.h"

extern void IWRAM_CODE paintTile(u16 *ptr, u8 baseColor);
extern void IWRAM_CODE paintBlackTile(u16 *ptr);
extern void IWRAM_CODE paintFlip1(u16 *ptr, u8 baseColor);
extern void IWRAM_CODE paintFlip2(u16 *ptr, u8 baseColor1, u8 baseColor2);
extern void IWRAM_CODE paintFlip3(u16 *ptr, u8 baseColor);


class MatrixEngine;
class vSwitchTile;
class vStreakCounter;
class gbaFace;
class vCluster;
class vLinker;
class vFlipTile;
class vSwitchTile;
class vStreak;


class MatrixEngine : public gbaTimeCounter, public irqInput, public irqVBlank {
	public:
		MatrixEngine(s8 playerProfile=-1);
		virtual ~MatrixEngine();

		//stuff for timers
		virtual void onVBlank();
		virtual void onTenthSecond();
		virtual void onSecond();
		virtual void onMinute();
		virtual void onTimeout();
		//end stuff for timers

		virtual void onCluster(vCluster *clstr);
		virtual void onClusterClear(vCluster *clstr);
		virtual u8 randomTile() { return 0; }

		virtual bool clearLinker() { return false; }

		virtual void resetEngine();

		void flip();
		void left();
		void right();
		void up();
		void down();
		virtual void onMove() {}

		void refreshMatrix();

		void drawTile(u16 x, u16 y, u8 basecolor, bool side);
		void drawTile1(u16 x, u16 y, u8 basecolor) { drawTile(x, y, basecolor, false); }
		void drawTile2(u16 x, u16 y, u8 basecolor) { drawTile(x, y, basecolor, true); }

		void drawFlipTile(u16 x, u16 y, u8 basecolor1, u8 basecolor2, u8 frame, bool side);
		void drawFlipTile1(u16 x, u16 y, u8 basecolor1, u8 basecolor2, u8 frame) {drawFlipTile(x, y, basecolor1, basecolor2, frame, false); }
		void drawFlipTile2(u16 x, u16 y, u8 basecolor1, u8 basecolor2, u8 frame) {drawFlipTile(x, y, basecolor1, basecolor2, frame, true); }

		void eraseTile(u16 x, u16 y, bool side);
		void eraseTile1(u16 x, u16 y) { eraseTile(x, y, false); }
		void eraseTile2(u16 x, u16 y) { eraseTile(x, y, true); }

		void eraseAll();

		u16 *getTilePointer(u16 x, u16 y, bool side) { if (side) return getTilePointer2(x,y); return getTilePointer1(x,y); }
		u16 *getTilePointer1(u16 x, u16 y);
		u16 *getTilePointer2(u16 x, u16 y);

		virtual void onInput(u16 prevState);
		virtual void onSelect() {}
		virtual void onStart();

		u8 getTile(u16 x, u16 y) { return map1[y][x]; }
		void setTile(u16 x, u16 y, u8 tile) { map1[y][x] = tile; }
		u8 getTile2(u16 x, u16 y) { return map2[y][x]; }
		void setTile2(u16 x, u16 y, u8 tile) { map2[y][x] = tile; }

		void setLocked(u16 x, u16 y, bool lock) { locked[y][x] = lock; }
		bool getLocked(u16 x, u16 y) { return locked[y][x]; }

		u8 getWidth() { return width; }
		u8 getHeight() { return height; }
		u16 getX() { return cursor->getCursorX(); }
		u16 getY() { return cursor->getCursorY(); }
		void moveCursor(u8 x, u8 y) { cursor->moveCursor(x, y); }


		bool buildTempMap(u16 x, u16 y, u8 linker=0);

		void updateCursor();
		void hideCursor();
		void showCursor();

		void drawBackground();

		void addLinker(vLinker *linker) { linkers.appendItem(linker); }
		void delLinker(vLinker *linker) { linkers.removeItem(linker); }
		vLinker *getLinker(u16 x, u16 y);
		//vLinker *getFirstLinker() { return linkers.getFirst(); }
		//vLinker *getNextLinker(

		void addPoints(u32 p) { setPoints(points + p); }
		u32 getPoints() { return points; }
		void setPoints(u32 p);
		void resetScore();

		void loadProfile();

		void setFlipTile(vFlipTile *tile) { flipTile = tile; }
		void setSwitchTile(vSwitchTile *tile) { switchTile = tile; }

		u8 getExtendedX(u8 x, u8 y, bool side);
		u8 getExtendedY(u8 x, u8 y, bool side);

		void addCounter(vStreakCounter *c);
		void delCounter(vStreakCounter *c);
		virtual void onStreakTimeout() {}

		void deleteEverything();

		void pause();
		void unPause();
		u8 isPaused() { return paused; }

		void setSave(bool s) { save = s; }

		void setLevel(u8 l);
		u8 getLevel() { return level; }

	protected:
		void searchTmpMap(u16 x, u16 y, u8 color, u8 *map);

		void buildPointers();

	protected:
		u8 width, height;
		u8 paused;
		bool save;

		u8 level;

		s8 profile;
		u32 points;

		u16 combo;
		u16 maxCombo;
		u16 totalCombo;

		vFlipTile *flipTile;
		vSwitchTile *switchTile;

		vCursor *cursor;
		vSprite *phishie;
		vList<vLinker*> linkers;
		vList<vCluster*> clusters;
		vList<vStreakCounter*> counters;


		vSprite *lvSprite;
		vSprite *timerSprite;
		vSprite *onepSprite;
		vSprite *strSprite;
		vSprite *eakSprite;
		vSprite *scoSprite;
		vSprite *reSprite;

		vSpriteData *scoreData;
		vSprite *scoreDisplay[5];

		vSprite *timerSeconds[2];
		vSprite *timerMinutes[3];
		vSprite *timerSep[2];

		vStreak *streak;
		vSprite *streakZero[3];
		vSprite *streakSep;

		vSprite *levelDisplay[2];

		gbaFace *face;
		
		u8 map1[16][5];
		u8 map2[16][5];
		u8 locked[16][5];

		vScore scores;
//		vu16 display[240*160];
};


extern MatrixEngine *engine;



#endif //_ENGINE_H
