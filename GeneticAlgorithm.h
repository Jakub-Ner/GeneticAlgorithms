#ifndef GENETICALG_GENETICALGORITHM_H
#define GENETICALG_GENETICALGORITHM_H


#include "Individual.h"
#include "NumberGenerator.h"

class GeneticAlgorithm {
    int m_pop_size;
    double m_cross_prob; // pstwo krzzowania
    double m_mut_prob;   // pstwo mutacji

    Problem *m_problem;
    Individual **m_population;
    Individual *m_best_solution;

    NumberGenerator *m_num_generator;
public:

    GeneticAlgorithm(int popSize, double crossProb, double mutProb, Problem *problem);

    ~GeneticAlgorithm();

    void findBestSolution(int iterationsNumber);

    void applyCross(int childIdx);

    Individual *getBestSolution();

private:
    void generatePop();

    Individual *findBest();

    Individual *selectParent();

    bool shouldCross();

    void applyMut(Individual *pIndividual);
};


#endif //GENETICALG_GENETICALGORITHM_H
