#include "i_colored_cube.h"
#include "i_cube_validator.h"

class TileUniquenessValidator : public ICubeValidator
{
public:
	virtual bool check(IColoredCube* cube);
};
