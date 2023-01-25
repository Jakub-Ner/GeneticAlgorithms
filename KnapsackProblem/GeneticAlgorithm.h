#ifndef GENETICALG_GENETICALGORITHM_H
#define GENETICALG_GENETICALGORITHM_H


#include "Individual.h"
#include "NumberGenerator.h"

class GeneticAlgorithm {
    int m_pop_size;
    double m_cross_prob;
    double m_mut_prob;

    Problem *m_problem;
    Individual *m_population;
    Individual *m_best_solution;

    NumberGenerator *m_num_generator;
public:

    GeneticAlgorithm(int popSize, double crossProb, double mutProb, Problem *problem, int seed);

    ~GeneticAlgorithm();

    void findBestSolution(int iterationsNumber);

    void applyCross2Individual(int childIdx);

    Individual *getBestSolution();

private:
    void generatePop();

    void findBest();

    Individual *selectParent();

    void applyMut2Individual(Individual *pIndividual);

    void crossPopulation(int shift);

    void mutatePopulation(int shift);

    void adaptPopulation(int shift);

    void printSolution(Individual *pIndividual);
};


#endif //GENETICALG_GENETICALGORITHM_H
