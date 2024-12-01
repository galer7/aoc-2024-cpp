cmake_minimum_required(VERSION 3.10)
project(advent_of_code_2024)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

# Add executable for each day
add_executable(day01 src/day01/day01.cpp src/utils/file_reader.cpp) 