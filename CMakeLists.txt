cmake_minimum_required(VERSION 3.24)
project(GeneticAlg)

set(CMAKE_CXX_STANDARD 11)

add_executable(GeneticAlg main.cpp SmartPtr.h KnapsackProblem.cpp KnapsackProblem.h GeneticAlgorithm.cpp GeneticAlgorithm.h Individual.cpp Individual.h Items.h Items.cpp Problem.h)
