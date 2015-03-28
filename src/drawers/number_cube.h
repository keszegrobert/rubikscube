#include "i_cube_draw.h"

class NumberCube : public ICubeDraw
{
public:
	virtual void draw(std::ostream& out, IColoredCube* cube);
};
