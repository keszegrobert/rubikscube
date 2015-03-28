#include "i_colored_cube.h"
#include "i_cube_draw.h"

class ColoredCube : public ICubeDraw
{
public:
	virtual void draw(std::ostream& out, IColoredCube* cube);
};
