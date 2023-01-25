cmake_minimum_required(VERSION 3.24)
project(GeneticAlg)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneticAlg KnapsackProblem/main.cpp KnapsackProblem/KnapsackProblem.cpp KnapsackProblem/KnapsackProblem.h KnapsackProblem/GeneticAlgorithm.cpp KnapsackProblem/GeneticAlgorithm.h KnapsackProblem/Individual.cpp KnapsackProblem/Individual.h KnapsackProblem/Items.h KnapsackProblem/Items.cpp KnapsackProblem/Problem.h KnapsackProblem/NumberGenerator.h KnapsackProblem/NumberGenerator.cpp KnapsackProblem/FileReader.cpp KnapsackProblem/FileReader.h)
