cmake_minimum_required(VERSION 3.3)
project(Evo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/cpp/test.cpp
    src/hpp/Select/fitnessProportionalSelection.hpp
    src/hpp/algorithm.hpp
    src/hpp/evo.hpp
    src/hpp/std.hpp src/hpp/Select/rouletteWheel.hpp src/hpp/Select/stochasticUniversalSampling.hpp src/hpp/Select/tournamentSelection.hpp src/hpp/Recombine/onePointCrossover.hpp src/hpp/Mutate/pointMutation.hpp src/hpp/Result.hpp src/hpp/Mutate/creep.hpp)

add_executable(Evo ${SOURCE_FILES})

add_definitions(-std=c++11)