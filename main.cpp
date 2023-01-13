#include <iostream>
#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"



int main() {
    double *valueTable = new double[]{5, 1, 4, 3};
    double *spaceTable = new double[]{4, 1, 3, 2};

    KnapsackProblem* problem = new KnapsackProblem();
    problem->createTable(5, 4, spaceTable, valueTable);

    GeneticAlgorithm *algorithm = new GeneticAlgorithm(6, 0.6, 0.1, problem);

    delete algorithm;
    delete problem;
    delete[] valueTable;
    delete[] spaceTable;
//    test();
    return 0;
}
