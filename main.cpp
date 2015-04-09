#include <unistd.h>
#include <string.h>
#include <iostream>
#include "src/drawers/ascii_cube.h"
#include "src/drawers/colored_cube.h"
#include "src/drawers/number_cube.h"
#include "src/rubiks_cube.h"
#include "src/instruction_parser.h"

int main(int argc,char* argv[])
{
	ICubeDraw* drawer=NULL;
	if (argc > 1)
	{
		if (strcmp(argv[1],"--colored")==0)
			drawer = new ColoredCube();		
		else if (strcmp(argv[1],"--ascii")==0)
			drawer = new AsciiCube();		
		else if (strcmp(argv[1],"--number")==0)
			drawer = new NumberCube();		
		else 
			drawer = new ColoredCube();		
	}
	else 
		drawer = new ColoredCube();
	RC::RubiksCube cube;
	drawer->draw(std::cout, &cube);
	std::cout << std::endl;

	InstructionParser stepparser;
	std::string line;

	while (std::cin)
	{
		getline(std::cin,line);
		if (!line.size())
			break;
		stepparser.Process(&cube,line);

		drawer->draw(std::cout, &cube);
		std::cout << std::endl;
	}

	return 0;
}
