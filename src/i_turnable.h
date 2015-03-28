#pragma once

enum eSides{	
	FRONT = 0,
	LEFT,
	UP,
	RIGHT,
	DOWN,
	BACK,
	XAXIS,
	YAXIS,
	ZAXIS,
	COUNT
};

class ITurnable{
public:
	virtual void turn(eSides side, int times) = 0;
};

