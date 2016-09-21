cmake_minimum_required(VERSION 3.6)
project(task1_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sources/main.cpp sources/Tile.cpp headers/Tile.h sources/ColorConf.cpp headers/ColorConf.h headers/TileConfs.h sources/PermutationEngine.cpp headers/PermutationEngine.h)
add_executable(task1_1 ${SOURCE_FILES} sources/Tile.cpp headers/Tile.h sources/ColorConf.cpp headers/ColorConf.h headers/TileConfs.h sources/PermutationEngine.cpp headers/PermutationEngine.h)