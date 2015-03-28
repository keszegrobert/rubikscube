# How to build:
# mkdir build
# cd build
# cmake .. -G "Unix Makefiles"

cmake_minimum_required(VERSION 2.8)
project ( rubikscube )
set(RUBIKSCUBE_VERSION 1.0.0)
set(GTEST_DIR "../gtest-1.7.0/include")

set(GTEST_HEADERS $(GTEST_DIR)/include/gtest/*.h
				$(GTEST_DIR)/include/gtest/internal/*.h)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror -isystem $(GTEST_DIR)/include")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

add_subdirectory(src)

include_directories( ./src ./test ./src/drawers ./src/validators ${GTEST_DIR})

add_executable(rubiks_cube main.cpp)
target_link_libraries(rubiks_cube rubiks_core)

add_executable(test_rubik test_rubik.cpp)
target_link_libraries(test_rubik gtest gtest_main pthread rubiks_core)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")

