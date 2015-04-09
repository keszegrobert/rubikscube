using namespace RC;

TEST(zaxisrotatetest,rotate_zaxis_1)
{
	std::stringstream expected;
	expected 
<< "      171411            " << std::endl
<< "      181512            " << std::endl
<< "      191613            " << std::endl
<< "474441070401272421535659" << std::endl
<< "484542080502282522525558" << std::endl
<< "494643090603292623515457" << std::endl
<< "      373431            " << std::endl
<< "      383532            " << std::endl
<< "      393633            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(ZAXIS,1);

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


TEST(zaxisrotatetest,rotate_zaxis_2)
{
	std::stringstream expected;
	expected 
<< "      494847            " << std::endl
<< "      464544            " << std::endl
<< "      434241            " << std::endl
<< "393837090807191817595857" << std::endl
<< "363534060504161514565554" << std::endl
<< "333231030201131211535251" << std::endl
<< "      292827            " << std::endl
<< "      262524            " << std::endl
<< "      232221            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(ZAXIS,2);

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

TEST(zaxisrotatetest,rotate_zaxis_3)
{
	std::stringstream expected;
	expected 
<< "      333639            " << std::endl
<< "      323538            " << std::endl
<< "      313437            " << std::endl
<< "232629030609434649575451" << std::endl
<< "222528020508424548585552" << std::endl
<< "212427010407414447595653" << std::endl
<< "      131619            " << std::endl
<< "      121518            " << std::endl
<< "      111417            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(ZAXIS,3);


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
