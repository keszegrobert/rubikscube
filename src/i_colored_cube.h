#pragma once
class IColoredCube{
public:
	static const int COUNT = 6;	
	static const int ROWS = 3;	
	static const int COLS = 3;

	virtual int getColor(int k,int i, int j) = 0;	
};