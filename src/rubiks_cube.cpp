#include <string.h>
#include <stdlib.h>	
#include "rubiks_cube.h"

int permutations[6][4][20] = {
	//front
	{
	 {29,28,27,37,34,31,41,42,43,13,16,19, 1,2,3,4,6,7,8,9},
	 {37,34,31,41,42,43,13,16,19,29,28,27, 3,6,9,2,8,1,4,7},
	 {41,42,43,13,16,19,29,28,27,37,34,31, 9,8,7,6,4,3,2,1},
	 {13,16,19,29,28,27,37,34,31,41,42,43, 7,4,1,8,2,9,6,3}
	},
	//left
	{
	 {21,24,27, 1, 4, 7,41,44,47,53,56,59, 13,16,19,12,18,11,14,17},
	 { 1, 4, 7,41,44,47,59,56,53,27,24,21, 19,18,17,16,14,13,12,11},
	 {41,44,47,59,56,53,21,24,27, 7, 4, 1, 17,14,11,18,12,19,16,13},
	 {59,56,53,21,24,27, 1, 4, 7,47,44,41, 11,12,13,14,16,17,18,19}
	},
	//up
	{
	 {11,12,13, 1, 2, 3,31,32,33,51,52,53, 21,22,23,24,26,27,28,29},
	 { 51,52,53,11,12,13,1, 2, 3,31,32,33, 23,26,29,22,28,21,24,27},
	 { 31,32,33,51,52,53,11,12,13,1, 2, 3, 29,28,27,26,24,23,22,21},
	 { 1, 2, 3,31,32,33,51,52,53,11,12,13, 27,24,21,28,22,29,26,23},
	},
	//right
	{
	 { 3, 6, 9,43,46,49,57,54,51,23,26,29, 31,32,33,34,36,37,38,39},
	 {23,26,29, 3, 6, 9,43,46,49,57,54,51, 33,36,39,32,38,31,34,37},
	 {57,54,51,23,26,29, 3, 6, 9,43,46,49, 39,38,37,36,34,33,32,31},
	 {43,46,49,57,54,51,23,26,29, 3, 6, 9, 37,34,31,38,32,39,36,33},
	},
	//down
	{
	 {17,18,19, 7, 8, 9,37,38,39,57,58,59, 41,42,43,44,46,47,48,49},
	 { 7, 8, 9,37,38,39,57,58,59,17,18,19, 43,46,49,42,48,41,44,47},
	 {37,38,39,57,58,59,17,18,19, 7, 8, 9, 49,48,47,46,44,43,42,41},
	 {57,58,59,17,18,19, 7, 8, 9,37,38,39, 47,44,41,48,42,49,46,43},
	},
	//back
	{
	 {33,36,39,49,48,47,17,14,11,21,22,23, 51,52,53,54,56,57,58,59},
	 {21,22,23,33,36,39,49,48,47,17,14,11, 53,56,59,52,58,51,54,57},
	 {17,14,11,21,22,23,33,36,39,49,48,47, 59,58,57,56,54,53,52,51},
	 {49,48,47,17,14,11,21,22,23,33,36,39, 57,54,51,58,52,59,56,53},
	}
};

namespace RC
	{
	RubiksCube::RubiksCube()
	{
		int current = 0;
		for (int k = 0; k < 6; ++k)
		{
			current = k*10;
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
					mTiles[k][i][j] = ++current;
		}
	}

	RubiksCube::RubiksCube(int* tiles)
	{
		for (int k = 0; k < 6; ++k)
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
					mTiles[k][i][j] = tiles[k*6*3+i*3+j];
	}

	int RubiksCube::getColor(int k, int i, int j)
	{
		return mTiles[k][i][j];		
	}

	bool RubiksCube::compareTo(IColoredCube* cube)
	{
		//TODO: forgasd a kozepeket a helyere
		bool isEqual = true;
		for (int k = 0; k < 6; ++k)
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
					isEqual = isEqual && (mTiles[k][i][j] == cube->getColor(k,i,j));
		return isEqual;
	}

	void RubiksCube::turn(eSides side, int times)
	{
		int count = times % 4;
		if (count<0)
			count += 4;
//		std::cout << "turn:" << count <<std::endl;
		if (count == 0)
			return;
		turn(permutations[side][0],permutations[side][count],20);			
	}

	void RubiksCube::turn(int* arrFrom, int* arrTo, size_t count)
	{
		size_t size = sizeof(mTiles);
		int prev[6][3][3];
		memcpy(&prev,&mTiles,size);
		for (size_t i = 0; i < count; ++i)
		{
			int from = arrFrom[i];
			int fromSide = from /10;
			int fromx = (from%10-1)/3;
			int fromy = (from%10-1)%3;
			int to = arrTo[i];
			int toSide = to/10;
			int toy = (to%10-1)/3;
			int tox = (to%10-1)%3;
			mTiles[toSide][toy][tox] = prev[fromSide][fromx][fromy];
		}
	}
}