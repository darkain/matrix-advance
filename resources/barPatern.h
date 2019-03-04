//256 Color Tile Graphics, Tile Size: 1x20, Tiles Used: 20
                     
const u16 barPatern_gfx[640] = {
0x3E3E,0x3E3E,0x3E3E,0x003E,0x3E3D,0x3E3D,0x3E3D,0x003D,
0x3D3E,0x3D3E,0x3D3E,0x003E,0x3D3C,0x3D3D,0x3D3C,0x003C,
0x3C3D,0x3C3C,0x3C3D,0x003D,0x3C3B,0x3C3B,0x3C3B,0x003B,
0x3B3C,0x3B3B,0x3B3B,0x003C,0x3B3A,0x3B3B,0x3B3A,0x003B,
0x3A3B,0x3A3B,0x3A3B,0x003B,0x3A3A,0x3A3A,0x3A3A,0x003A,
0x3A3A,0x3A3A,0x393A,0x003A,0x3939,0x3A39,0x3939,0x0039,
0x3939,0x3939,0x393A,0x0039,0x3938,0x3938,0x3938,0x0038,
0x3839,0x3839,0x3839,0x0039,0x3838,0x3838,0x3838,0x0038,
0x3838,0x3738,0x3838,0x0038,0x3737,0x3737,0x3837,0x0037,
0x3737,0x3737,0x3737,0x0037,0x3736,0x3736,0x3736,0x0036,
0x3637,0x3637,0x3637,0x0037,0x3636,0x3635,0x3636,0x0036,
0x3536,0x3536,0x3536,0x0036,0x3535,0x3535,0x3535,0x0035,
0x3535,0x3535,0x3535,0x0035,0x3434,0x3434,0x3434,0x0034,
0x3434,0x3434,0x3434,0x0034,0x3333,0x3433,0x3333,0x0033,
0x3334,0x3333,0x3334,0x0033,0x3332,0x3332,0x3332,0x0032,
0x3233,0x3233,0x3233,0x0033,0x3231,0x3232,0x3231,0x0032,
0x3132,0x3132,0x3132,0x0032,0x3131,0x3130,0x3131,0x0031,
0x3031,0x3031,0x3031,0x0031,0x3030,0x3030,0x3030,0x0030,
0x3030,0x3030,0x3030,0x0030,0x2F2F,0x2F2F,0x2F2F,0x002F,
0x2F2F,0x2F2F,0x2F2F,0x002F,0x2E2E,0x2E2E,0x2E2E,0x002E,
0x2E2E,0x2E2E,0x2E2E,0x002E,0x2D2D,0x2D2D,0x2D2D,0x002D,
0x2D2D,0x2D2D,0x2D2D,0x002D,0x2C2C,0x2C2C,0x2C2C,0x002C,
0x2C2C,0x2C2C,0x2C2C,0x002C,0x2C2B,0x2B2B,0x2C2B,0x002B,
0x2B2B,0x2B2B,0x2B2B,0x002B,0x2B2A,0x2B2A,0x2B2A,0x002A,
0x2A2B,0x2A2B,0x2A2B,0x002B,0x2A2A,0x2A2A,0x2A2A,0x002A,
0x2A2A,0x2A2A,0x2A2A,0x002A,0x2929,0x2A29,0x2A29,0x0029,
0x292A,0x292A,0x292A,0x002A,0x2929,0x2929,0x2929,0x0029,
0x2829,0x2829,0x2829,0x0029,0x2828,0x2828,0x2828,0x0028,
0x2828,0x2828,0x2828,0x0028,0x2827,0x2727,0x2827,0x0027,
0x2727,0x2727,0x2727,0x0027,0x2726,0x2726,0x2726,0x0026,
0x2626,0x2626,0x2626,0x0026,0x2625,0x2625,0x2625,0x0025,
0x2525,0x2525,0x2525,0x0025,0x2524,0x2524,0x2524,0x0024,
0x2425,0x2425,0x2425,0x0025,0x2424,0x2424,0x2424,0x0024,
0x2324,0x2424,0x2324,0x0024,0x2323,0x2323,0x2323,0x0023,
0x2323,0x2323,0x2323,0x0023,0x2322,0x2322,0x2322,0x0022,
0x2222,0x2222,0x2222,0x0022,0x2221,0x2221,0x2221,0x0021,
0x2122,0x2122,0x2122,0x0022,0x2121,0x2121,0x2121,0x0020,
0x2121,0x2121,0x2121,0x0021,0x2020,0x2120,0x2020,0x0020,
0x2021,0x2020,0x2021,0x0020,0x201F,0x201F,0x201F,0x001F,
0x1F20,0x1F20,0x1F20,0x0020,0x1F1F,0x1F1F,0x1F1F,0x001F,
0x1F1F,0x1F1F,0x1F1F,0x001F,0x1F1E,0x1F1E,0x1F1E,0x001E,
0x1E1F,0x1E1F,0x1E1E,0x001F,0x1E1E,0x1E1E,0x1E1E,0x001E,
0x1E1E,0x1D1E,0x1E1E,0x001E,0x1D1D,0x1D1D,0x1D1D,0x001D,
0x1D1D,0x1D1D,0x1D1D,0x001D,0x1D1D,0x1D1D,0x1D1D,0x001D,
0x1D1C,0x1D1C,0x1D1C,0x001C,0x1C1C,0x1C1D,0x1C1C,0x001D,
0x1C1C,0x1C1B,0x1C1C,0x001C,0x1C1C,0x1B1C,0x1C1C,0x001C,
0x1B1B,0x1B1B,0x1B1B,0x001B,0x1B1B,0x1B1C,0x1B1B,0x001C,
0x1B1B,0x1B1A,0x1B1B,0x001A,0x1A1B,0x1A1B,0x1A1B,0x001B,
0x1A1A,0x1A1A,0x1A1A,0x001A,0x1A1A,0x1A1A,0x1A1A,0x001A,
0x1A19,0x1A19,0x1A19,0x0019,0x191A,0x191A,0x191A,0x001A,
0x1919,0x1919,0x1919,0x0019,0x1919,0x1919,0x1919,0x0019,
0x1918,0x1818,0x1918,0x0018,0x1818,0x1818,0x1818,0x0018,
0x1817,0x1817,0x1817,0x0017,0x1718,0x1718,0x1718,0x0018,
0x1717,0x1717,0x1717,0x0016,0x1717,0x1617,0x1617,0x0017,
0x1616,0x1616,0x1616,0x0016,0x1616,0x1616,0x1516,0x0016,
0x1515,0x1515,0x1515,0x0015,0x1515,0x1515,0x1515,0x0015,
0x1414,0x1514,0x1514,0x0014,0x1414,0x1414,0x1414,0x0014,
0x1413,0x1413,0x1413,0x0013,0x1314,0x1314,0x1314,0x0014,
0x1312,0x1312,0x1312,0x0013,0x1213,0x1213,0x1213,0x0013,
0x1212,0x1212,0x1212,0x0012,0x1212,0x1112,0x1212,0x0012,
0x1111,0x1111,0x1111,0x0011,0x1111,0x1111,0x1111,0x0011,
0x1110,0x1110,0x1110,0x0010,0x1011,0x1011,0x1011,0x0011,
0x100F,0x1010,0x100F,0x0010,0x0F10,0x0F10,0x0F10,0x0010,
0x0F0F,0x0F0F,0x0F0F,0x000F,0x0F0F,0x0F0F,0x0F0F,0x000F,
0x0E0E,0x0F0E,0x0F0E,0x000E,0x0E0E,0x0E0E,0x0E0E,0x000E,
0x0E0D,0x0E0D,0x0E0D,0x000D,0x0D0E,0x0D0E,0x0D0E,0x000E,
0x0D0C,0x0D0C,0x0D0C,0x000C,0x0C0D,0x0C0D,0x0C0D,0x000D,
0x0C0B,0x0C0B,0x0C0B,0x000B,0x0B0C,0x0B0C,0x0B0C,0x000C,
0x0B0A,0x0B0B,0x0B0A,0x000A,0x0A0B,0x0A0B,0x0A0B,0x000B,
0x0A0A,0x0A0A,0x0A0A,0x000A,0x0A0A,0x090A,0x0A0A,0x000A,
0x0909,0x0909,0x0909,0x0009,0x0909,0x0909,0x0909,0x0009,
0x0808,0x0808,0x0808,0x0008,0x0808,0x0708,0x0808,0x0008,
0x0707,0x0707,0x0707,0x0007,0x0707,0x0707,0x0707,0x0007,
0x0706,0x0706,0x0706,0x0006,0x0607,0x0606,0x0607,0x0006,
0x0605,0x0605,0x0605,0x0005,0x0506,0x0506,0x0506,0x0006,
0x0505,0x0504,0x0505,0x0004,0x0405,0x0405,0x0505,0x0005,
0x0404,0x0404,0x0404,0x0004,0x0404,0x0404,0x0404,0x0004,
0x0403,0x0303,0x0403,0x0003,0x0303,0x0303,0x0303,0x0003,
0x0302,0x0302,0x0302,0x0002,0x0202,0x0203,0x0202,0x0003,
0x0201,0x0201,0x0201,0x0001,0x0101,0x0101,0x0101,0x0001,
};
//Palette, Colors Used: 64
const u16 barPatern_pal[64] = {
0x0000,0x03E4,0x03E4,0x03E5,0x03E6,0x03E7,0x03E8,0x03E9,
0x03EA,0x03EB,0x03EC,0x03ED,0x03EE,0x03EF,0x03F0,0x03F1,
0x03F3,0x03F4,0x03F5,0x03F6,0x03F7,0x03F8,0x03F9,0x03FA,
0x03FB,0x03FC,0x03FD,0x03FE,0x03FF,0x03FF,0x03FF,0x03DF,
0x03BF,0x039F,0x037F,0x035F,0x033F,0x031F,0x02FF,0x02DF,
0x02BF,0x029F,0x027F,0x023F,0x021F,0x01FF,0x01DF,0x01BF,
0x019F,0x017F,0x015F,0x013F,0x011F,0x00FF,0x00DF,0x00BF,
0x009F,0x007F,0x005F,0x003F,0x003F,0x001F,0x001F,0x7FFF,
};
