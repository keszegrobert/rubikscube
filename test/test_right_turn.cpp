using namespace RC;

TEST(rightturntest,turn_right_1)
{
	std::stringstream expected;
	expected 
<< "      212203            " << std::endl
<< "      242506            " << std::endl
<< "      272809            " << std::endl
<< "111213010243373431295253" << std::endl
<< "141516040546383532265556" << std::endl
<< "171819070849393633235859" << std::endl
<< "      414257            " << std::endl
<< "      444554            " << std::endl
<< "      474851            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(RIGHT,1);

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


TEST(rightturntest,turn_right_2)
{
	std::stringstream expected;
	expected 
<< "      212243            " << std::endl
<< "      242546            " << std::endl
<< "      272849            " << std::endl
<< "111213010257393837095253" << std::endl
<< "141516040554363534065556" << std::endl
<< "171819070851333231035859" << std::endl
<< "      414223            " << std::endl
<< "      444526            " << std::endl
<< "      474829            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(RIGHT,2);

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

TEST(rightturntest,turn_right_3)
{
	std::stringstream expected;
	expected 
<< "      212257            " << std::endl
<< "      242554            " << std::endl
<< "      272851            " << std::endl
<< "111213010223333639495253" << std::endl
<< "141516040526323538465556" << std::endl
<< "171819070829313437435859" << std::endl
<< "      414203            " << std::endl
<< "      444506            " << std::endl
<< "      474809            " << std::endl
<< "";

	NumberCube drawer;
	RubiksCube cube;
	cube.turn(RIGHT,3);

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
