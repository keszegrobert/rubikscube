#include "cube_compare.h"

CubeCompare::CubeCompare(IColoredCube* cube1, IColoredCube* cube2)
{
	for (int k = 0; k < 6; ++k)
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (cube1->getColor(k,i,j) == cube2->getColor(k,i,j))
					mDifference.push_back(k*10+i*3+j+1);
}

int CubeCompare::getDifferentTileCount()
{
	return mDifference.size();
}

std::vector<int>& CubeCompare::getDifferentTiles()
{
	return mDifference;
}
