/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _SCRSUNSET_H_
#define _SCRSUNSET_H_


#include <vArm/irq/irqInput.h>
#include <vArm/irq/irqVBlank.h>


class vSunset : public irqInput, public irqVBlank {
	public:
		vSunset();
		virtual ~vSunset() {}
		virtual void onInput(u16 prevState);
		virtual void onVBlank() { setInputEnabled(true); }
		void del();
};

#endif //_SCRSUNSET_H_
