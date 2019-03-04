/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _CLUSTER_H_
#define _CLUSTER_H_


#include <vArm/irq/irqVBlank.h>
#include "streakCounter.h"


class vCluster : public vStreakCounter, public irqVBlank {
	public:
		vCluster(u8 *map, u16 mapcolor);
		virtual ~vCluster();
		virtual void onVBlank();

	private:
		u8 clustermap[16][5];
		u8 newmap[16][5];
		u16 color;
		u16 flipcount;
};


#endif //_CLUSTER_H_

