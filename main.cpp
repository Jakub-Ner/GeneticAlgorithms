#include <iostream>
#include <cstring>
#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"


void testAlg();

void test();

int main() {
    testAlg();
//    test();
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

void test() {
//    int *tab = new int[]{1, 2, 3, 4, 5};
    Individual **ind = new Individual *[10];
    for (int i = 0; i < 5; i++) {
        ind[i] = new Individual(5);
        ind[i + 5] = new Individual(5);
        for (int j = 0; j < 5; j++) {
            ind[i]->m_gen[j] = i;
            ind[i + 5]->m_gen[j] = i;
        }
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 5; j++)
            std::cout << ind[i]->m_gen[j] << " ";

//    memcpy(tab2 + 1, tab + 1, 4 * sizeof(int));
//    for (int i = 0; i < 5; i++) {
//        std::cout << tab2[i] << " ";
//    }
}
