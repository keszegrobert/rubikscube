TEST(backturntest,turn_back_1)
{
	std::stringstream expected;
	expected 
<< "      333639            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "231213010203313249575451" << std::endl
<< "221516040506343548585552" << std::endl
<< "211819070809373847595653" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      111417            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(BACK,1);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileNeighbourValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileUniquenessValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}


TEST(backturntest,turn_back_2)
{
	std::stringstream expected;
	expected 
<< "      494847            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "391213010203313217595857" << std::endl
<< "361516040506343514565554" << std::endl
<< "331819070809373811535251" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      232221            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(BACK,2);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileNeighbourValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileUniquenessValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}

TEST(backturntest,turn_back_3)
{
	std::stringstream expected;
	expected 
<< "      171411            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "471213010203313221535659" << std::endl
<< "481516040506343522525558" << std::endl
<< "491819070809373823515457" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      393633            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(BACK,3);


	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileNeighbourValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileUniquenessValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}
