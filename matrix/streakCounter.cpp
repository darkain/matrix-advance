/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#include <vArm/vGBA.h>
#include "streakCounter.h"
#include "engine.h"


vStreakCounter::vStreakCounter() {
  ASSERT(engine != NULL);
	engine->addCounter(this);
}


vStreakCounter::~vStreakCounter() {
  ASSERT(engine != NULL);
	engine->delCounter(this);
}
