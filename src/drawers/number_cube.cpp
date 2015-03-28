#include "number_cube.h"

void NumberCube::draw(std::ostream& out, IColoredCube* cube)
{
	int posxs[6] = {1,0,1,2,1,3};
	int posys[6] = {1,1,0,1,2,1};

	const int ROWS = 9;	
	const int COLS = 12;
	int mTiles[ROWS][COLS];

	//clear the colors
	for (int i = 0; i < ROWS; ++i)
		for (int j = 0; j < COLS; ++j)
			mTiles[i][j] = 0;

	for (int k = 0; k < 6; ++k)
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				int posx = posxs[k]*3+j;
				int posy = posys[k]*3+i;
				mTiles[posy][posx] = cube->getColor(k,i,j);
			}

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			int ch = mTiles[i][j];
			if (ch==0)
				out << "  ";
			else
				out << ch/10 << ch%10;
		}
		out << std::endl;
	}
}
