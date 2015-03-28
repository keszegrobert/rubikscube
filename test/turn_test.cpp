using namespace RC;


void CompareTurns(eSides cubeside, int cube1turn, int cube2turn, bool equal)
{
//	std::cout << cube1turn <<"~"<< cube2turn<<"~"<<equal <<std::endl;
	SCOPED_TRACE(testing::Message() 
		<< "CompareTurns(side="<<cubeside
		<< ", turn1="<<cube1turn
		<< ", turn2="<<cube2turn
		<< ", equal="<<equal
		<< ")"	);

	NumberCube drawer;

	RubiksCube cube1;
	cube1.turn(cubeside,cube1turn);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube1));

	TileNeighbourValidator tnv;
	ASSERT_TRUE(tnv.check(&cube1));

	TileUniquenessValidator tuv;
	ASSERT_TRUE(tuv.check(&cube1));

	std::stringstream cube1Str;
	drawer.draw(cube1Str,&cube1);

	RubiksCube cube2;
	cube2.turn(cubeside,cube2turn);

	ASSERT_TRUE(tcv.check(&cube2));
	ASSERT_TRUE(tnv.check(&cube2));
	ASSERT_TRUE(tuv.check(&cube2));

	std::stringstream cube2Str;
	drawer.draw(cube2Str,&cube2);


	if (equal)
	{
		ASSERT_EQ(cube1Str.str(),cube2Str.str());	
		EXPECT_TRUE(cube1.compareTo(&cube2));	
	}
	else
	{
		ASSERT_NE(cube1Str.str(),cube2Str.str());	
		EXPECT_FALSE(cube1.compareTo(&cube2));	
	}

}

TEST(turn_test,every_turn_should_be_atomic)
{
	for (int side = 0; side < COUNT; ++side)
	{
		for (int cube1 = -4; cube1 <= 4; ++cube1)
		{
			for (int cube2 = -4; cube2 <= 4; ++cube2)
			{
				int counter = (cube1-cube2+8)%4;
				{
					ASSERT_NO_FATAL_FAILURE(
						CompareTurns(eSides(side),cube1,cube2,!counter)
					);
				}
				++counter;
				counter %= 4;				
			}		
		}
	}
}

void CheckTurnSteps(eSides cubeside,int turncount)
{
	SCOPED_TRACE(testing::Message() 
		<< "CompareTurns(side="<<cubeside
		<< ", turn="<<turncount
		<< ")"	);

	NumberCube drawer;

	RubiksCube cube1;
	cube1.turn(cubeside,turncount);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube1));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube1));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube1));

	std::stringstream cube1Str;
	drawer.draw(cube1Str,&cube1);

	RubiksCube cube2;
	for (int i = 0; i<turncount; ++i)
	{
		SCOPED_TRACE(testing::Message() 
			<< "CompareTurns(side="<<cubeside
			<< ", turn="<<turncount
			<< ",i="<<i
			<< ")" );
		std::stringstream cube2Str;
		drawer.draw(cube2Str,&cube2);
	
		EXPECT_NE(cube1Str.str(),cube2Str.str());
		EXPECT_FALSE(cube1.compareTo(&cube2));	
		cube2.turn(cubeside,1);

		ASSERT_TRUE(tcv.check(&cube2));
		ASSERT_TRUE(tnv.check(&cube2));
		ASSERT_TRUE(tuv.check(&cube2));
	}

	std::stringstream cube2Str;
	drawer.draw(cube2Str,&cube2);

	EXPECT_EQ(cube1Str.str(),cube2Str.str());
	EXPECT_TRUE(cube1.compareTo(&cube2));	
}

TEST(turn_test,test_every_possible_turn)
{
	for (int side = 0; side < COUNT; ++side)
	{
		for (int j = 0; j < 4; ++j)
		{
			ASSERT_NO_FATAL_FAILURE(
				CheckTurnSteps(eSides(side),j)
			);
		}
	}
}
