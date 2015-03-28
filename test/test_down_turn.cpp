using namespace RC;

TEST(downturntest,turn_down_1)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "111213010203313233515253" << std::endl
<< "141516040506343536545556" << std::endl
<< "575859171819070809373839" << std::endl
<< "      474441            " << std::endl
<< "      484542            " << std::endl
<< "      494643            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(DOWN,1);
	
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


TEST(downturntest,turn_down_2)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "111213010203313233515253" << std::endl
<< "141516040506343536545556" << std::endl
<< "373839575859171819070809" << std::endl
<< "      494847            " << std::endl
<< "      464544            " << std::endl
<< "      434241            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(DOWN,2);

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

TEST(downturntest,turn_down_3)
{
	std::stringstream expected;
	expected 
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "111213010203313233515253" << std::endl
<< "141516040506343536545556" << std::endl
<< "070809373839575859171819" << std::endl
<< "      434649            " << std::endl
<< "      424548            " << std::endl
<< "      414447            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(DOWN,3);

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
