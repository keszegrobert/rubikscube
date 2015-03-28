#include <sstream>
#include <gtest/gtest.h>
#include "rubiks_cube.h"
#include "number_cube.h"
#include "tile_uniqueness_validator.h"
#include "tile_color_validator.h"
#include "tile_neighbour_validator.h"
#include "instruction_parser.h"

using namespace RC;
#include "test_instruction_parser.cpp"
/*#include "test_front_turn.cpp"
#include "test_left_turn.cpp"
#include "test_up_turn.cpp"
#include "test_right_turn.cpp"
#include "test_down_turn.cpp"
#include "test_back_turn.cpp"
#include "turn_test.cpp"
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}