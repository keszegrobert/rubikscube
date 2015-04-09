#include <string>
#include <sstream>
#include <set>
#include "i_colored_cube.h"
#include "i_cube_draw.h"
#include "i_turnable.h"

namespace RC{

class RubiksCube: public IColoredCube, public ITurnable
{
protected:
	int mTiles[6][3][3];
public:
	RubiksCube();
	RubiksCube(int* tiles);
	int getColor(int k, int i, int j);
	bool compareTo(IColoredCube* cube);
	void rotate(eSides side, int times);
	void turn(eSides side, int times);
protected:
	void turn(int* arrFrom, int* arrTo, size_t count);	

};

}//end of RC