#pragma once
#include "i_colored_cube.h"
class ICubeValidator
{
public:
	virtual bool check(IColoredCube* cube)=0;
};