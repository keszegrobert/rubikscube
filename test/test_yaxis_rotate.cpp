using namespace RC;

TEST(yaxisrotatetest,rotate_yaxis_1)
{
	std::stringstream expected;
	expected 
<< "      272421            " << std::endl
<< "      282522            " << std::endl
<< "      292623            " << std::endl
<< "010203313233515253111213" << std::endl
<< "040506343536545556141516" << std::endl
<< "070809373839575859171819" << std::endl
<< "      434649            " << std::endl
<< "      424548            " << std::endl
<< "      414447            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(YAXIS,1);

	TileColorValidator tcv;
	EXPECT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	EXPECT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	EXPECT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);
	EXPECT_EQ(expected.str(),stream.str());	
}


TEST(yaxisrotatetest,rotate_yaxis_2)
{
	std::stringstream expected;
	expected 
<< "      292827            " << std::endl
<< "      262524            " << std::endl
<< "      232221            " << std::endl
<< "313233515253111213010203" << std::endl
<< "343536545556141516040506" << std::endl
<< "373839575859171819070809" << std::endl
<< "      494847            " << std::endl
<< "      464544            " << std::endl
<< "      434241            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(YAXIS,2);

	TileColorValidator tcv;
	EXPECT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	EXPECT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	EXPECT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);
	EXPECT_EQ(expected.str(),stream.str());	
}

TEST(yaxisrotatetest,rotate_yaxis_3)
{
	std::stringstream expected;
	expected 
<< "      232629            " << std::endl
<< "      222528            " << std::endl
<< "      212427            " << std::endl
<< "515253111213010203313233" << std::endl
<< "545556141516040506343536" << std::endl
<< "575859171819070809373839" << std::endl
<< "      474441            " << std::endl
<< "      484542            " << std::endl
<< "      494643            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(YAXIS,3);


	TileColorValidator tcv;
	EXPECT_TRUE(tcv.check(&cube));

	TileColorValidator tnv;
	EXPECT_TRUE(tnv.check(&cube));

	TileColorValidator tuv;
	EXPECT_TRUE(tuv.check(&cube));

	std::stringstream stream;
	drawer.draw(stream,&cube);

	EXPECT_EQ(expected.str(),stream.str());	
}
