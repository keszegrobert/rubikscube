#include "i_cube_draw.h"

class AsciiCube : public ICubeDraw
{
public:
	virtual void draw(std::ostream& out, IColoredCube* cube);
};
