cmake_minimum_required(VERSION 3.3)
project(Evo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/cpp/test.cpp
    src/hpp/Select/fitnessProportionalSelection.hpp
    src/hpp/Termination/generation.hpp
    src/hpp/algorithm.hpp
    src/hpp/evo.hpp
    src/hpp/std.hpp src/hpp/Select/rouletteWheel.hpp src/hpp/Select/stochasticUniversalSampling.hpp)

add_executable(Evo ${SOURCE_FILES})