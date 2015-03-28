#include "i_turnable.h"
#include <string>

const int stStart = 0;
const int stOperation = 1;

class InstructionParser{
public:	
	eSides mOperation;
	int mCount;
	InstructionParser():mOperation(COUNT),mCount(1){}
	bool Parse(ITurnable* cube, int& state, char ch);
	bool Process(ITurnable* cube, std::string steps);
};