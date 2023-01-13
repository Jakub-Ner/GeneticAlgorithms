#ifndef GENETICALG_GENETICALGORITHM_H
#define GENETICALG_GENETICALGORITHM_H


#include "SmartPtr.h"
#include "Individual.h"
#include "Problem.h"

class GeneticAlgorithm {
    int m_pop_size;
    double m_cross_prob; // pstwo krzzowania
    double m_mut_prob;   // pstwo mutacji

    Problem* m_problem;
    Individual *m_population;
    Individual *m_best_solution;
public:

    GeneticAlgorithm(int popSize, int crossProb, int mutProb, Problem* problem);

    ~GeneticAlgorithm();

    void findBestSolution();

    Individual* getBest();

private:
    void generatePop();

    Individual* findBest();
};


#endif //GENETICALG_GENETICALGORITHM_H
