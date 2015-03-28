set(SRCS
	./rubiks_cube.cpp
	./cube_compare.cpp
	./drawers/colored_cube.cpp
	./drawers/ascii_cube.cpp
	./drawers/number_cube.cpp
	./validators/tile_neighbour_validator.cpp
	./validators/tile_color_validator.cpp 
	./validators/tile_uniqueness_validator.cpp 
	./instruction_parser.cpp
)

set(HEADERS
	./i_colored_cube.h
	./i_turnable.h
	./rubiks_cube.h
	./cube_compare.h
	./i_cube_draw.h
	./drawers/colored_cube.h
	./drawers/ascii_cube.h
	./drawers/number_cube.h
	./i_cube_validator.h
	./validators/tile_neighbour_validator.h
	./validators/tile_color_validator.h 
	./validators/tile_uniqueness_validator.h 
	./instruction_parser.h
)

include_directories( . ./drawers ./validators)

add_library(rubiks_core ${SRCS} ${HEADERS})

