#include "colored_cube.h"
#include <vector>


enum eSides{
	FRONT = 0,
	LEFT,
	UP,
	RIGHT,
	DOWN,
	BACK,
	COUNT
};

void ColoredCube::draw(std::ostream& out, IColoredCube* cube)
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
			
	char colors[6] = {FRONT,LEFT,UP,RIGHT,DOWN,BACK};
	
	const std::string BLACK = "\033[0m  ";
	const std::string RED = "\033[1;31;41m  ";
	const std::string GREEN = "\033[1;31;42m  ";
	const std::string YELLOW = "\033[1;31;43m  ";
	const std::string BLUE = "\033[1;31;44m  ";
	const std::string MAGENTA = "\033[1;31;45m  ";
	const std::string CYAN = "\033[1;31;46m  ";
	const std::string WHITE = "\033[1;31;47m  ";

	std::vector<std::string> ttycolors(7);
	ttycolors[FRONT] = RED;
	ttycolors[BACK] = MAGENTA;
	ttycolors[LEFT] = GREEN;
	ttycolors[RIGHT] = BLUE;
	ttycolors[UP] = WHITE;
	ttycolors[DOWN] = YELLOW;
	
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			int ch = mTiles[i][j];
			if (ch == 0)
				out << BLACK;
			else
			{
				int color = colors[ch / 10];
				out << ttycolors[color];
			}
		}
		out << BLACK << std::endl;
	}
}
