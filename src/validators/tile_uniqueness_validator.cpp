#include <set>
#include "tile_uniqueness_validator.h"

bool TileUniquenessValidator::check(IColoredCube* cube)
{
	std::set<int> used;
	bool bValid = true;		
	for (int k = 0; k < IColoredCube::COUNT; ++k)
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				int color = cube->getColor(k,i,j);

				// this color was used before
				if (used.find(color) != used.end())
					bValid = false;
				used.insert(color);
			}
	return bValid;
}
