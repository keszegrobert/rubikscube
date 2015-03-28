#include <unistd.h>
#include <iostream>
#include "src/drawers/ascii_cube.h"
#include "src/drawers/colored_cube.h"
#include "src/drawers/number_cube.h"
#include "src/rubiks_cube.h"
#include "src/instruction_parser.h"

int main()
{
	ColoredCube drawer;
	RC::RubiksCube cube;
	drawer.draw(std::cout, &cube);
	std::cout << std::endl;

	InstructionParser stepparser;
	std::string line;

	while (std::cin)
	{
		getline(std::cin,line);
		if (!line.size())
			break;
		stepparser.Process(&cube,line);

		drawer.draw(std::cout, &cube);
		std::cout << std::endl;
	}

	return 0;
}
