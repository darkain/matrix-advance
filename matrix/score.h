/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCORE_H_
#define _SCORE_H_


struct vScore {
	u32 points;
	char name[8];
	u16 maxStreakLo;
	u16 maxStreakHi;
	u16 totalLinkers;
	u16 maxLinker;
	u16 totalCombos;
	u16 maxCombo;
	u16 totalClusters;
	u16 maxCluster;
	u8 face;
	u8 reserved0[3];
};


struct sRam {
	u8 reserved0[32];
	vScore topScores[10];
	vScore saves[8];
	vScore reserved1[13];
};


extern volatile sRam *saveRam;


class gbaScore {
	public:
		gbaScore();
		virtual ~gbaScore();

		u8 addScore(vScore *score, s8 profile=-1);

		vScore *getScore(int id) { return &scores[id]; }
		vScore *getPlayer(int id) { return &players[id]; }
		vScore *getTempScore() { return &temp; }

		void loadScores();
		void saveScores();

	private:
		void insertScore(u8 place);
		void copyScore(u8 source, u8 dest);

	private:
		vScore scores[10];
		vScore players[8];
		vScore temp;
};


extern gbaScore *gameScores;


#endif //_SCORE_H_
