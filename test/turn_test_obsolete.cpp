
/*
using ::testing::TestWithParam;
using ::testing::Values;

class OneTurnData{
public:
	int cube1turn;
	int cube2turn;
	eSides cubeside;
	bool equal;
	OneTurnData(int turn1, int turn2, eSides side, bool eq){
		cube1turn = turn1;
		cube2turn = turn2;
		cubeside = side;
		equal = eq;
	}
};


class TurnTest : public TestWithParam<OneTurnData*>{
public:
	virtual ~TurnTest(){
	}
	virtual void SetUp(){
		data = GetParam();
	}
	virtual void TearDown(){
	}
	OneTurnData* data;
};

::std::vector<OneTurnData*> GetTurnCombinations()
{
	::std::vector<OneTurnData*> result;

	for (int side = 0; side < COUNT; ++side)
	{
		int counter = 0;
		for (int cube1 = -4; cube1 <= 4; ++cube1)
		{
			for (int cube2 = -4; cube2 <= 4; ++cube2)
			{
				result.push_back(new OneTurnData(cube1,cube2,eSides(side),counter == 0));			
				counter %= ++counter;				
			}			
		}		
	}
	return result;
}

::std::vector<OneTurnData*> comb = GetTurnCombinations();


INSTANTIATE_TEST_CASE_P(TurnEverySide, TurnTest,
	testing::ValuesIn(comb.begin(),comb.end()));

TEST_P(TurnTest,TwoTurnsAreTheSame)
{
	NumberCube drawer;

	RubiksCube cube1;
	cube1.turn(data->cubeside,data->cube1turn);
	std::stringstream cube1Str;
	cube1.draw(cube1Str,drawer);

	RubiksCube cube2;
	cube2.turn(data->cubeside,data->cube2turn);
	std::stringstream cube2Str;
	cube2.draw(cube2Str,drawer);

	if (data->equal)
		ASSERT_EQ(cube1Str.str(),cube2Str.str());	
	else
		ASSERT_NE(cube1Str.str(),cube2Str.str());	

}
*/