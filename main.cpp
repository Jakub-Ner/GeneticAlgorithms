#include <iostream>
#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"


void testAlg();

void testRead() {
    KnapsackProblem problem;
    std::cout << problem.loadTableFromFile("/home/jakubner/CLionProjects/GeneticAlg/data.txt");
}

int main() {
    testAlg();
//    testRead();
    return 0;
}


void testAlg() {
    KnapsackProblem *problem = new KnapsackProblem();
    problem->loadTableFromFile("/home/jakubner/CLionProjects/GeneticAlg/data.txt");

    GeneticAlgorithm *algorithm = new GeneticAlgorithm(500, 0.6, 0.1, problem);
    algorithm->findBestSolution(5000);


    delete algorithm;
    delete problem;
}


