using namespace RC;

TEST(xaxisrotatetest,rotate_xaxis_1)
{
	std::stringstream expected;
	expected 
<< "      010203            " << std::endl
<< "      040506            " << std::endl
<< "      070809            " << std::endl
<< "131619414243373431292827" << std::endl
<< "121518444546383532262524" << std::endl
<< "111417474849393633232221" << std::endl
<< "      595857            " << std::endl
<< "      565554            " << std::endl
<< "      535251            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(XAXIS,1);

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


TEST(xaxisrotatetest,rotate_xaxis_2)
{
	std::stringstream expected;
	expected 
<< "      414243            " << std::endl
<< "      444546            " << std::endl
<< "      474849            " << std::endl
<< "191817595857393837090807" << std::endl
<< "161514565554363534060504" << std::endl
<< "131211535251333231030201" << std::endl
<< "      212223            " << std::endl
<< "      242526            " << std::endl
<< "      272829            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(XAXIS,2);

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

TEST(xaxisrotatetest,rotate_xaxis_3)
{
	std::stringstream expected;
	expected 
<< "      595857            " << std::endl
<< "      565554            " << std::endl
<< "      535251            " << std::endl
<< "171411212223333639494847" << std::endl
<< "181512242526323538464544" << std::endl
<< "191613272829313437434241" << std::endl
<< "      010203            " << std::endl
<< "      040506            " << std::endl
<< "      070809            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(XAXIS,3);


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
