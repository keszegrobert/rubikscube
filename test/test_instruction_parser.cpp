#include <map>

void CompareCubes(RubiksCube& cube1, RubiksCube& cube2)
{
	SCOPED_TRACE(testing::Message() << "CompareCubes");
	NumberCube drawer;
	std::stringstream cube1Str;
	drawer.draw(cube1Str,&cube1);
	std::stringstream cube2Str;
	drawer.draw(cube2Str,&cube2);

	ASSERT_EQ(cube1Str.str(),cube2Str.str());	
	EXPECT_TRUE(cube1.compareTo(&cube2));	
}

void ValidateParseStep(RubiksCube& cube2, 
	int count, char ch, eSides op, int state, 
	eSides expop, int expstate, int expcount, bool expvalid)
{
	SCOPED_TRACE(testing::Message() 
		<< "ValidateParseStep("
		<< "count=" << count << ","
		<< "ch=" << ch << ","
		<< "op=" << op << ","
		<< "state=" << state << ","
		<< "expop=" << expop << ","
		<< "expstate=" << expstate << ","
		<< "expcount=" << expcount << ","
		<< "expvalid=" << expvalid 
		<< ")");

	InstructionParser ip;
	ip.mCount = count;
	ip.mOperation = op;
	RubiksCube cube1;
	if (expvalid)
		ASSERT_TRUE(ip.Parse(&cube1,state,ch));
	else
		ASSERT_FALSE(ip.Parse(&cube1,state,ch));

	ASSERT_EQ(expstate,state);
	ASSERT_EQ(expcount,ip.mCount);
	ASSERT_EQ(expop,ip.mOperation);
	CompareCubes(cube1,cube2);
}

TEST(instruction_parser,not_turned_reads_F)
{
	RubiksCube cube;
	ValidateParseStep(cube,0,'F',COUNT,stStart,
		FRONT, stOperation, 1, true);
}

TEST(instruction_parser,turned_F_reads_F)
{
	RubiksCube cube;
	cube.turn(FRONT,1);
	ValidateParseStep(cube,1,'F',FRONT,stOperation,
		FRONT, stOperation, 1, true);
}

TEST(instruction_parser,turned_F_reads_0)
{
	RubiksCube cube;
	cube.turn(FRONT,0);
	ValidateParseStep(cube,1,'0',FRONT,stOperation,
		COUNT, stStart, 0, true);
}

TEST(instruction_parser,turned_F_reads_1)
{
	RubiksCube cube;
	cube.turn(FRONT,1);
	ValidateParseStep(cube,1,'1',FRONT,stOperation,
		COUNT, stStart, 0, true);
}

TEST(instruction_parser,read_F_reads_apostrophe)
{
	RubiksCube cube;
	cube.turn(FRONT,-1);
	ValidateParseStep(cube,1,'\'',FRONT,stOperation,
		COUNT, stStart, 0, true);
}


TEST(instruction_parser,start_read_1)
{
	InstructionParser ip;
	int state = stStart;
	RubiksCube cube1;
	ASSERT_FALSE(ip.Parse(&cube1,state,'1'));
}

TEST(instruction_parser,op_read_invalid_char)
{
	InstructionParser ip;
	int state = stStart;
	RubiksCube cube1;
	ASSERT_FALSE(ip.Parse(&cube1,state,'X'));
}

void CompareTurnSequence(RubiksCube& cube2,std::string turn_sequence)
{
	SCOPED_TRACE(testing::Message() 
		<< "CompareTurnSequence(seq=" << turn_sequence << ")");

	TileColorValidator tcv;
	TileNeighbourValidator tnv;
	TileUniquenessValidator tuv;

	ASSERT_TRUE(tcv.check(&cube2));
	ASSERT_TRUE(tnv.check(&cube2));
	ASSERT_TRUE(tuv.check(&cube2));

	RubiksCube cube1;
	InstructionParser ip;
	ASSERT_TRUE(ip.Process(&cube1,turn_sequence));

	ASSERT_TRUE(tcv.check(&cube1));
	ASSERT_TRUE(tnv.check(&cube1));
	ASSERT_TRUE(tuv.check(&cube1));

	CompareCubes(cube1,cube2);
}


TEST(instruction_parser,front_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"F0");
	cube.turn(FRONT,1);
	CompareTurnSequence(cube,"F");
	CompareTurnSequence(cube,"F1");
	cube.turn(FRONT,1);
	CompareTurnSequence(cube,"FF");
	CompareTurnSequence(cube,"F2");
	cube.turn(FRONT,1);
	CompareTurnSequence(cube,"FFF");
	CompareTurnSequence(cube,"F3");
	CompareTurnSequence(cube,"F'");
	cube.turn(FRONT,1);
	CompareTurnSequence(cube,"FFFF");
	CompareTurnSequence(cube,"F4");
}

TEST(instruction_parser,left_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"L0");
	cube.turn(LEFT,1);
	CompareTurnSequence(cube,"L");
	CompareTurnSequence(cube,"L1");
	cube.turn(LEFT,1);
	CompareTurnSequence(cube,"LL");
	CompareTurnSequence(cube,"L2");
	cube.turn(LEFT,1);
	CompareTurnSequence(cube,"LLL");
	CompareTurnSequence(cube,"L3");
	CompareTurnSequence(cube,"L'");
	cube.turn(LEFT,1);
	CompareTurnSequence(cube,"LLLL");
	CompareTurnSequence(cube,"L4");
}

TEST(instruction_parser,right_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"R0");
	cube.turn(RIGHT,1);
	CompareTurnSequence(cube,"R");
	CompareTurnSequence(cube,"R1");
	cube.turn(RIGHT,1);
	CompareTurnSequence(cube,"RR");
	CompareTurnSequence(cube,"R2");
	cube.turn(RIGHT,1);
	CompareTurnSequence(cube,"RRR");
	CompareTurnSequence(cube,"R3");
	CompareTurnSequence(cube,"R'");
	cube.turn(RIGHT,1);
	CompareTurnSequence(cube,"RRRR");
	CompareTurnSequence(cube,"R4");
}

TEST(instruction_parser,up_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"U0");
	cube.turn(UP,1);
	CompareTurnSequence(cube,"U");
	CompareTurnSequence(cube,"U1");
	cube.turn(UP,1);
	CompareTurnSequence(cube,"UU");
	CompareTurnSequence(cube,"U2");
	cube.turn(UP,1);
	CompareTurnSequence(cube,"UUU");
	CompareTurnSequence(cube,"U3");
	CompareTurnSequence(cube,"U'");
	cube.turn(UP,1);
	CompareTurnSequence(cube,"UUUU");
	CompareTurnSequence(cube,"U4");
}


TEST(instruction_parser,down_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"D0");
	cube.turn(DOWN,1);
	CompareTurnSequence(cube,"D");
	CompareTurnSequence(cube,"D1");
	cube.turn(DOWN,1);
	CompareTurnSequence(cube,"DD");
	CompareTurnSequence(cube,"D2");
	cube.turn(DOWN,1);
	CompareTurnSequence(cube,"DDD");
	CompareTurnSequence(cube,"D3");
	CompareTurnSequence(cube,"D'");
	cube.turn(DOWN,1);
	CompareTurnSequence(cube,"DDDD");
	CompareTurnSequence(cube,"D4");
}


TEST(instruction_parser,back_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"B0");
	cube.turn(BACK,1);
	CompareTurnSequence(cube,"B");
	CompareTurnSequence(cube,"B1");
	cube.turn(BACK,1);
	CompareTurnSequence(cube,"BB");
	CompareTurnSequence(cube,"B2");
	cube.turn(BACK,1);
	CompareTurnSequence(cube,"BBB");
	CompareTurnSequence(cube,"B3");
	CompareTurnSequence(cube,"B'");
	cube.turn(BACK,1);
	CompareTurnSequence(cube,"BBBB");
	CompareTurnSequence(cube,"B4");
}

TEST(instruction_parser,change_order_of_3_corners)
{
	RubiksCube cube;
	cube.turn(FRONT,-1);
	cube.turn(RIGHT,-1);
	cube.turn(FRONT,1);
	cube.turn(LEFT,1);
	cube.turn(FRONT,-1);
	cube.turn(RIGHT,1);
	cube.turn(FRONT,1);
	cube.turn(LEFT,-1);

	CompareTurnSequence(cube,"F'R'FLF'RFL'");
	std::map<int,int> mapChanges;
	mapChanges[37] = 31;
	mapChanges[31] = 1;
	mapChanges[1] = 37;
	mapChanges[3] = 13;
	mapChanges[13] = 43;
	mapChanges[43] = 3;
	mapChanges[29] = 27;
	mapChanges[27] = 9;
	mapChanges[9] = 29;
	
}


TEST(instruction_parser,xaxis_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"x0");
	cube.turn(XAXIS,1);
	CompareTurnSequence(cube,"x");
	CompareTurnSequence(cube,"x1");
	cube.turn(XAXIS,1);
	CompareTurnSequence(cube,"xx");
	CompareTurnSequence(cube,"x2");
	cube.turn(XAXIS,1);
	CompareTurnSequence(cube,"xxx");
	CompareTurnSequence(cube,"x3");
	CompareTurnSequence(cube,"x'");
	cube.turn(XAXIS,1);
	CompareTurnSequence(cube,"xxxx");
	CompareTurnSequence(cube,"x4");
}


TEST(instruction_parser,yaxis_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"y0");
	cube.turn(YAXIS,1);
	CompareTurnSequence(cube,"y");
	CompareTurnSequence(cube,"y1");
	cube.turn(YAXIS,1);
	CompareTurnSequence(cube,"yy");
	CompareTurnSequence(cube,"y2");
	cube.turn(YAXIS,1);
	CompareTurnSequence(cube,"yyy");
	CompareTurnSequence(cube,"y3");
	CompareTurnSequence(cube,"y'");
	cube.turn(YAXIS,1);
	CompareTurnSequence(cube,"yyyy");
	CompareTurnSequence(cube,"y4");
}


TEST(instruction_parser,zaxis_turns)
{
	RubiksCube cube;
	CompareTurnSequence(cube,"");
	CompareTurnSequence(cube,"z0");
	cube.turn(ZAXIS,1);
	CompareTurnSequence(cube,"z");
	CompareTurnSequence(cube,"z1");
	cube.turn(ZAXIS,1);
	CompareTurnSequence(cube,"zz");
	CompareTurnSequence(cube,"z2");
	cube.turn(ZAXIS,1);
	CompareTurnSequence(cube,"zzz");
	CompareTurnSequence(cube,"z3");
	CompareTurnSequence(cube,"z'");
	cube.turn(ZAXIS,1);
	CompareTurnSequence(cube,"zzzz");
	CompareTurnSequence(cube,"z4");
}
