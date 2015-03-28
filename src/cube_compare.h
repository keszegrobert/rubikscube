#include "i_colored_cube.h"
#include <vector>

class CubeCompare
{
	std::vector<int> mDifference;
public:
	CubeCompare(IColoredCube* cube1, IColoredCube* cube2);
	int getDifferentTileCount();
	std::vector<int>& getDifferentTiles();
};		