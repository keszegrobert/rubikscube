#include "i_colored_cube.h"
#include "i_cube_validator.h"

class TileNeighbourValidator: public ICubeValidator
{
public:
	virtual bool check(IColoredCube* cube);
};
