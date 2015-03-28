using namespace RC;

TEST(leftturntest,turn_left_1)
{
	std::stringstream expected;
	expected 
<< "      592223            " << std::endl
<< "      562526            " << std::endl
<< "      532829            " << std::endl
<< "171411210203313233515247" << std::endl
<< "181512240506343536545544" << std::endl
<< "191613270809373839575841" << std::endl
<< "      014243            " << std::endl
<< "      044546            " << std::endl
<< "      074849            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(LEFT,1);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}


TEST(leftturntest,turn_left_2)
{
	std::stringstream expected;
	expected 
<< "      412223            " << std::endl
<< "      442526            " << std::endl
<< "      472829            " << std::endl
<< "191817590203313233515207" << std::endl
<< "161514560506343536545504" << std::endl
<< "131211530809373839575801" << std::endl
<< "      214243            " << std::endl
<< "      244546            " << std::endl
<< "      274849            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(LEFT,2);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}

TEST(leftturntest,turn_left_3)
{
	std::stringstream expected;
	expected 
<< "      012223            " << std::endl
<< "      042526            " << std::endl
<< "      072829            " << std::endl
<< "131619410203313233515227" << std::endl
<< "121518440506343536545524" << std::endl
<< "111417470809373839575821" << std::endl
<< "      594243            " << std::endl
<< "      564546            " << std::endl
<< "      534849            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(LEFT,3);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}
