#include "ascii_cube.h"

void AsciiCube::draw(std::ostream& out, IColoredCube* cube)
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

	char palette[6] = {'F','L','U','R','D','B'};

	const int WROWS = ROWS*2+1;
	const int WCOLS = COLS*4+1;
	int wire[WROWS][WCOLS];
	

	for (int i = 0; i < WROWS; ++i)
	{
		for (int j = 0; j < WCOLS; ++j)
		{
			wire[i][j] = ' ';
		}
	}

	for (int i = 0; i < ROWS; ++i)
		for (int j = 0; j < COLS; ++j)
		{
			int color = mTiles[i][j];
			if (color == 0)
				continue;

			char wcolor = '*';
			if (color < 60)
				wcolor = palette[color/10];

			int wposx = j*4;
			int wposy = i*2;

			wire[wposy][wposx] = '+';
			wire[wposy][wposx+1] = '-';
			wire[wposy][wposx+2] = '-';
			wire[wposy][wposx+3] = '-';
			wire[wposy][wposx+4] = '+';

			wire[wposy+1][wposx] = '|';
			wire[wposy+1][wposx+1] = ' ';
			wire[wposy+1][wposx+2] = wcolor;
			wire[wposy+1][wposx+3] = ' ';
			wire[wposy+1][wposx+4] = '|';

			wire[wposy+2][wposx] = '+';
			wire[wposy+2][wposx+1] = '-';
			wire[wposy+2][wposx+2] = '-';
			wire[wposy+2][wposx+3] = '-';
			wire[wposy+2][wposx+4] = '+';
		}
	for (int i = 0; i < WROWS; ++i)
	{
		for (int j = 0; j < WCOLS; ++j)
		{
			char ch = wire[i][j];
			out << ch;
		}
		out << std::endl;
	}
}
