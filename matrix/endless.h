/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef __ENDLESS_H__
#define __ENDLESS_H__


#include "engine.h"


class EndlessMatrix : public MatrixEngine {
	public:
		EndlessMatrix(s8 profile=-1);
		virtual ~EndlessMatrix();

		virtual u8 randomTile() { return dice(1,6); }
//		virtual void onStart();
		virtual void resetEngine();
};


#endif //__ENDLESS_H__
