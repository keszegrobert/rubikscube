#include "tile_color_validator.h"

bool TileColorValidator::check(IColoredCube* cube)
{
	bool bValid = true;		
	for (int k = 0; k < IColoredCube::COUNT; ++k)
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				int color = cube->getColor(k,i,j);

				//1-9,11-19,...,51-59
				bValid  = bValid && (0 < color);
				bValid  = bValid && (color < 60);
				bValid  = bValid && (color % 10 != 0);
			}
	return bValid;
}