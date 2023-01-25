#include <iostream>
#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include <filesystem>

namespace fs = std::filesystem;

void testAlg() {
    std::string currentDir = __FILE__;
    currentDir = currentDir.substr(0, currentDir.find_last_of("/\\"));

    KnapsackProblem *problem = new KnapsackProblem();
    problem->loadTableFromFile(currentDir  + "/data.txt");

    GeneticAlgorithm *algorithm = new GeneticAlgorithm(500, 0.5, 0.1, problem, -5);
    algorithm->findBestSolution(5000);


    delete algorithm;
    delete problem;
}


int main() {
    testAlg();
    return 0;
}



