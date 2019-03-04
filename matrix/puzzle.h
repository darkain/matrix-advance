/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef __PUZZLE_H__
#define __PUZZLE_H__


#include "engine.h"
#include "pauseEngine.h"


struct vPuzzle {
	u8  width;
	u8  height;
	u8  moves;
	u8  flags;  //1st line indented and things like that
	u8  reserved[4];
	pu8 title;
	pu8 data;
};



class PuzzleMatrix : public MatrixEngine {
	public:
		PuzzleMatrix(u16 newlevel=1, s8 profile=-1);
		virtual ~PuzzleMatrix();
		
		virtual u8 randomTile() { return 0; }
		virtual bool clearLinker() { return true; }

		virtual void onClusterClear(vCluster *clstr);

		u16 getLevel() { return puzzleId; }

		void loadLevel(u16 newlevel);
		void nextLevel() { loadLevel(getLevel()+1); }

		virtual void onSelect() { loadLevel(getLevel()); }
		virtual void resetEngine();

		virtual void onMove();

		virtual void onStreakTimeout();

	protected:
		void loadLevel(vPuzzle *pzle);

	private:
		vPuzzle *puzzle;
		u16 puzzleId;
		u16 moves;
		vPauseEngine *pauseEngine;
		vSprite *moveDisplay;
};


class vPuzzleWin : public vPauseEngine {
	public:
		vPuzzleWin(PuzzleMatrix *matrix);
		virtual ~vPuzzleWin();

		virtual void onInput(u16 prevState);
		void up();
		void down();
		void update();

	private:
		vSprite *sprites[20];
		u8 selected;
		PuzzleMatrix *puzzle;
};


class vPuzzleLose : public vPauseEngine {
	public:
		vPuzzleLose();
		virtual ~vPuzzleLose();

		virtual void onInput(u16 prevState);
		void up();
		void down();
		void update();

	private:
		vSprite *sprites[20];
		u8 selected;
		u8 total;
};

#endif //__PUZZLE_H__
