const u8 matrixDrawC[20] = {
	1,
	1,
	2,
	2,
	3,
	4,
	5,
	6,
	7,
	9,
	11,
	10,
	9,
	9,
	9,
	9,
	9,
	10,
	11,
};


const u8 matrixa[] = {
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const u8 matrixb[32] = {
	0x77, 0x00, 0x00, 0x00,
	0x77, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};


const u8 matrixhline[78] = {
	3, 1, 32,
	38, 1, 38,
	38, 14, 38,
	38, 28, 38,
	38, 36, 38,
	3, 36, 27,
	3, 44, 27,
	3, 59, 34,
	33, 36, 2,
	33, 44, 4,
	//10
	40, 51, 36, 
	40, 59, 36,
	79, 24, 55,
	134, 25, 2,
	136, 26, 2,
	84, 140, 2,
	86, 141, 2,
	88, 142, 54,
	88, 150, 54,
	161, 24, 54,
	//20
	215, 25, 2,
	217, 26, 2,
	165, 140, 2,
	167, 141, 2,
	169, 142, 54,
	169, 150, 54
};


const u8 matrixvline[90] = {
	1, 3, 32,
	1, 38, 5,
	1, 46, 12,
	31, 38, 5,
	36, 3, 10,
	36, 16, 11,
	36, 30, 5,
	38, 46, 4,
	38, 53, 5,
	77, 3, 10,
	//10
	77, 16, 7,
	77, 30, 5,
	77, 38, 12,
	77, 53, 5,
	77, 61, 71,
	78, 132, 2,
	79, 134, 2,
	86, 144, 5,
	143, 144, 5,
	142, 31, 2,
	//20
	143, 33, 2,
	144, 35, 105,
	158, 27, 105,
	225, 35, 105,
	223, 31, 2,
	224, 33, 2,
	159, 132, 2,
	160, 134, 2,
	167, 144, 5,
	224, 144, 5,
	//30
};


const u8 matrixpset[142] = {
	2, 2,
	2, 35,
	2, 37,
	2, 43, 
	2, 45,
	2, 58,
	30, 37,
	32, 37,
	35, 2,
	35, 35,
	//10
	37, 2,
	37, 13,
	37, 15,
	37, 27,
	37, 29,
	30, 43,
	32, 43,
	37, 45,
	37, 58,
	39, 58,
	//20
	39, 50,
	39, 52, 
	37, 35,
	76, 2,
	76, 13,
	78, 23,
	78, 25,
	77, 26,
	76, 27,
	76, 35,
	//30
	76, 37,
	76, 50,
	76, 52,
	76, 58,
	76, 60,
	80, 136,
	81, 137,
	82, 138,
	83, 139,
	87, 143,
	//40
	87, 149,
	142, 149,
	142, 143,
	142, 141,
	143, 140,
	138, 27,
	139, 28,
	140, 29,
	141, 30,
	76, 29,
	//50
	76, 15,
	160, 25,
	159, 26,
	168, 143,
	168, 149,
	223, 149,
	223, 143,
	223, 141,
	224, 140,
	161, 136,
	//60
	162, 137,
	163, 138,
	164, 139,
	219, 27,
	220, 28,
	221, 29,
	222, 30,

	//extra krap
	38, 58,
	37, 59,
	38, 59,
	39, 59,
};



const u16 matrixPalette[] = {
	RGB(0,0,0),
	//grey
	RGB(15,15,15),
	RGB(14,14,14),
	RGB(10,10,10),
	RGB(7,7,7),
	RGB(10,10,10),
	RGB(12,12,12),
	//red
	RGB(31,0,0),
	RGB(28,0,0),
	RGB(21,0,0),
	RGB(15,0,0),
	RGB(20,0,0),
	RGB(25,0,0),
	//green
	RGB(0,31,0),
	RGB(0,28,0),
	RGB(0,21,0),
	RGB(0,15,0),
	RGB(0,20,0),
	RGB(0,25,0),
	//blue
	RGB(0,0,31),
	RGB(0,0,28),
	RGB(0,0,21),
	RGB(0,0,15),
	RGB(0,0,20),
	RGB(0,0,25),
	//pink
	RGB(31,0,31),
	RGB(28,0,28),
	RGB(21,0,21),
	RGB(15,0,15),
	RGB(20,0,20),
	RGB(25,0,25),
	//cyan
	RGB(0,31,31),
	RGB(0,28,28),
	RGB(0,21,21),
	RGB(0,15,15),
	RGB(0,20,20),
	RGB(0,25,25),
	//yellow
	RGB(31,31,0),
	RGB(28,28,0),
	RGB(21,21,0),
	RGB(15,15,0),
	RGB(20,20,0),
	RGB(25,25,0),
	//white
	RGB(31,31,31),
	RGB(28,28,28),
	RGB(21,21,21),
	RGB(15,15,15),
	RGB(20,20,20),
	RGB(25,25,25),

	//highlight grey
	RGB(20,20,20),
	RGB(19,19,19),
	RGB(17,17,17),
	RGB(15,15,15),
	RGB(17,17,17),
	RGB(18,18,18),
	//highlight red
	RGB(31,10,10),
	RGB(29,10,10),
	RGB(25,10,10),
	RGB(20,10,10),
	RGB(24,10,10),
	RGB(27,10,10),
	//highlight green
	RGB(10,31,10),
	RGB(10,29,10),
	RGB(10,25,10),
	RGB(10,20,10),
	RGB(10,24,10),
	RGB(10,27,10),
	//highlight blue
	RGB(10,10,31),
	RGB(10,10,29),
	RGB(10,10,25),
	RGB(10,10,20),
	RGB(10,10,24),
	RGB(10,10,27),
	//highlight pink
	RGB(31,10,31),
	RGB(29,10,29),
	RGB(25,10,25),
	RGB(20,10,20),
	RGB(24,10,24),
	RGB(27,10,27),
	//highlight cyan
	RGB(10,31,31),
	RGB(10,29,29),
	RGB(10,25,25),
	RGB(10,20,20),
	RGB(10,24,24),
	RGB(10,27,27),
	//highlight yellow
	RGB(31,31,10),
	RGB(29,29,10),
	RGB(25,25,10),
	RGB(20,20,10),
	RGB(24,24,10),
	RGB(27,27,10),
	//highlight white
	RGB(31,31,31),
	RGB(29,29,29),
	RGB(25,25,25),
	RGB(20,20,20),
	RGB(24,24,24),
	RGB(27,27,27),
};


