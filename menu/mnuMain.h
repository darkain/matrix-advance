/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _MNU_MAIN_H_
#define _MNU_MAIN_H_


#include "mnuBase.h"


class mnuMain : public mnuBase {
	public:
		mnuMain();
		virtual ~mnuMain() {}

	protected:
		virtual void onChange(u16 selected);
		virtual void onListBuilt();
		virtual gbaMenuItem *newMenuItem(gbaMnuPart *partList, u16 listCount);

	private:
		static u16 lastId;
};


#endif //_MNU_MAIN_H_
