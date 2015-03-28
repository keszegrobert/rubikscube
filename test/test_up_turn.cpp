using namespace RC;

TEST(upturntest,turn_up_1)
{
	std::stringstream expected;
	expected 
<< "      272421            " << std::endl
<< "      282522            " << std::endl
<< "      292623            " << std::endl
<< "010203313233515253111213" << std::endl
<< "141516040506343536545556" << std::endl
<< "171819070809373839575859" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(UP,1);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	ASSERT_EQ(expected.str(),stream.str());	
}


TEST(upturntest,turn_up_2)
{
	std::stringstream expected;
	expected 
<< "      292827            " << std::endl
<< "      262524            " << std::endl
<< "      232221            " << std::endl
<< "313233515253111213010203" << std::endl
<< "141516040506343536545556" << std::endl
<< "171819070809373839575859" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(UP,2);

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

TEST(upturntest,turn_up_3)
{
	std::stringstream expected;
	expected 
<< "      232629            " << std::endl
<< "      222528            " << std::endl
<< "      212427            " << std::endl
<< "515253111213010203313233" << std::endl
<< "141516040506343536545556" << std::endl
<< "171819070809373839575859" << std::endl
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(UP,3);

	TileColorValidator tcv;
	ASSERT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	ASSERT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	ASSERT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	ASSERT_EQ(expected.str(),stream.str());	
}
