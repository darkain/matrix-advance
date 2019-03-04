/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRTOPSCORES_H_
#define _SCRTOPSCORES_H_



#include <vArm/irq/irqInput.h>


class screenTopScores : public irqInput {
	public:
		screenTopScores();
		virtual ~screenTopScores();
		virtual void onInput(u16 prevState);
		void del();
};

#endif //_SCRTOPSCORES_H_
