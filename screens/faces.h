/*************************  MATRIX ADVANCE  ****************************\
*  Copyright (c) 2005 Vincent E. Milum Jr., All rights reserved.        *
*                                                                       *
*  See License.txt for more information                                 *
*                                                                       *
*  Latest Source versions can be found at:  HTTP://WWW.DARKAIN.COM/     *
\***********************************************************************/


#ifndef _FACES_H_
#define _FACES_H_


class gbaFace {
	public:
		gbaFace(u8 newx, u8 newy, const void *rawdata);
		gbaFace(u8 newx, u8 newy, u8 newId);
		virtual ~gbaFace() {}

		void paintFace();

	private:
		u8 x, y, id;
		const void *data;
};

#endif //_FACES_H_
