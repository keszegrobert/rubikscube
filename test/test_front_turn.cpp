TEST(frontturntest,default)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "111213010203313233515253" << std::endl
<< "141516040506343536545556" << std::endl
<< "171819070809373839575859" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	RubiksCube cube;

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	NumberCube drawer;
	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}


TEST(frontturntest,turn_front)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      191613            " << std::endl
<< "111241070401273233515253" << std::endl
<< "141542080502283536545556" << std::endl
<< "171843090603293839575859" << std::endl
<< "      373431            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	RubiksCube cube;
	cube.turn(FRONT,1);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	NumberCube drawer;
	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}

TEST(frontturntest,turn_front_2)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      434241            " << std::endl
<< "111237090807193233515253" << std::endl
<< "141534060504163536545556" << std::endl
<< "171831030201133839575859" << std::endl
<< "      292827            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	RubiksCube cube;
	cube.turn(FRONT,2);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	NumberCube drawer;
	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}
TEST(frontturntest,turn_front_3)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      313437            " << std::endl
<< "111229030609433233515253" << std::endl
<< "141528020508423536545556" << std::endl
<< "171827010407413839575859" << std::endl
<< "      131619            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	RubiksCube cube;
	cube.turn(FRONT,3);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	NumberCube drawer;
	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}
