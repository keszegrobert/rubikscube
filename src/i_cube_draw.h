#pragma once
#include "i_colored_cube.h"
#include <iostream>

class ICubeDraw{
public:
	virtual void draw(std::ostream& out, IColoredCube* cube)=0;
};