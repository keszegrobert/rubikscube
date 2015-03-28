#include "instruction_parser.h"
#include <iostream>
bool InstructionParser::Parse(ITurnable* cube, int& state, char ch)
{
	switch (state){
	case stStart:
		if (ch == 'F')
		{
			mOperation = FRONT;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'L')
		{
			mOperation = LEFT;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'R')
		{
			mOperation = RIGHT;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'U')
		{
			mOperation = UP;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'D')
		{
			mOperation = DOWN;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'B')
		{
			mOperation = BACK;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'x')
		{
			mOperation = XAXIS;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'y')
		{
			mOperation = YAXIS;
			mCount = 1;
			state = stOperation;
		}
		else if (ch == 'z')
		{
			mOperation = ZAXIS;
			mCount = 1;
			state = stOperation;
		}
		else
			return false;
		break;
	case stOperation:
		if (ch == 'F')
		{
			cube->turn(mOperation,mCount);
			mOperation = FRONT;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'L')
		{
			cube->turn(mOperation,mCount);
			mOperation = LEFT;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'R')
		{
			cube->turn(mOperation,mCount);
			mOperation = RIGHT;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'U')
		{
			cube->turn(mOperation,mCount);
			mOperation = UP;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'D')
		{
			cube->turn(mOperation,mCount);
			mOperation = DOWN;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'B')
		{
			cube->turn(mOperation,mCount);
			mOperation = BACK;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'X')
		{
			cube->turn(mOperation,mCount);
			mOperation = XAXIS;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'Y')
		{
			cube->turn(mOperation,mCount);
			mOperation = YAXIS;
			state = stOperation;
			mCount = 1;
		}
		else if (ch == 'Z')
		{
			cube->turn(mOperation,mCount);
			mOperation = ZAXIS;
			state = stOperation;
			mCount = 1;
		}
		else if ('0'<=ch && ch<='9')
		{
			mCount = ch - '0';				
			cube->turn(mOperation,mCount);
			mOperation = COUNT;
			mCount = 0;
			state = stStart;
		}
		else if (ch == '\'')
		{
			mCount = -1;
			cube->turn(mOperation,mCount);
			mOperation = COUNT;
			mCount = 0;
			state = stStart;
		}
		else
		{
			return false;
		}
		break;
	}
	return true;
}


bool InstructionParser::Process(ITurnable* cube, std::string steps)
{
	int state = stStart;
	std::string::iterator it = steps.begin();
	while (it != steps.end())
	{
		char ch = *it;
//		std::cout << "state=="<<state<<",ch=="<<ch<<std::endl;
		if (!Parse(cube,state,ch))
			return false;
		++it;
	}

//	std::cout << "mOperation=="<<mOperation<<",mCount=="<<mCount<<std::endl;
	if (mOperation != COUNT && mCount != 0)
	{
		cube->turn(mOperation,mCount);
	}
	return true;
}
