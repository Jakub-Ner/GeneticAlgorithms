#include <iostream>
#include <cstring>
#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"


void testAlg();


int main() {
    testAlg();
    return 0;
}

void testAlg() {
    double *valueTable = new double[]{5, 1, 4, 3};
    double *spaceTable = new double[]{4, 1, 3, 2};

    KnapsackProblem *problem = new KnapsackProblem();
    problem->createTable(5, 4, spaceTable, valueTable);

    GeneticAlgorithm *algorithm = new GeneticAlgorithm(50, 0.6, 0.1, problem);
    algorithm->findBestSolution(500);
    for (int i = 0; i < algorithm->getBestSolution()->getGenSize(); i++) {
        std::cout << algorithm->getBestSolution()->m_gen[i];
    }
    std::cout << ": " << algorithm->getBestSolution()->getAdaptation();

    delete algorithm;
    delete problem;
    delete[] valueTable;
    delete[] spaceTable;
}

