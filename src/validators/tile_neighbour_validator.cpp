#include "tile_neighbour_validator.h"

bool TileNeighbourValidator::check(IColoredCube* cube)
{
	static int consistency[60] = {
	0,13,28,29,16, 5,34,41,42,37,
	0,53,24,27,56,15, 4,47,44, 7,
	0,11,52,51,12,25,32, 1, 2,31,
	0, 3,26,23, 6,35,54,43,46,57,
	0,19, 8, 9,18,45,38,59,58,39,
	0,33,22,21,36,55,14,49,48,17
	};

	for (int k = 0; k < 6; ++k)
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				int color = cube->getColor(k,i,j);
				int nextColor = consistency[color];
				
				int place = k*10+i*3+j;
				int nextplace = consistency[place+1];

				int kk = nextplace / 10;
				int xy = nextplace % 10 -1;
				int yy = xy / 3;
				int xx = xy % 3;
				int shouldbe = cube->getColor(kk,yy,xx);

				if (nextColor != shouldbe)
					return false;
			}
	return true;
}
