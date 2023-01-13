#include <random>
#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, int crossProb, int mutProb, Problem *problem) {
    m_pop_size = popSize;
    m_cross_prob = crossProb;
    m_mut_prob = mutProb;

    m_problem = problem;
    m_population = new Individual[2 * popSize];
    generatePop();
}

void GeneticAlgorithm::generatePop() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 1);

    int genSize = m_problem->getGenSize();

    for (int i = 0; i < m_pop_size; i++) {
        m_population[i] = Individual(genSize);
        m_population[2 * i] = Individual(genSize);
        std::cout << "\n";
        for (int j = 0; j < genSize; j++) {
            int nucleotide = distrib(gen);
            m_population[i].m_gen[j] = nucleotide;
            m_population[2 * i].m_gen[j] = nucleotide;
            std::cout << nucleotide;
        }
    }
}

void GeneticAlgorithm::findBestSolution() {
    for (int i = 0; i < m_pop_size; i++) {
    }
    m_best_solution = findBest();
}

Individual *GeneticAlgorithm::findBest() {
    return NULL;
}

GeneticAlgorithm::~GeneticAlgorithm() {
    if (m_population != NULL) {
        delete[] m_population;
    }
}

Individual *GeneticAlgorithm::getBest() {
    return m_best_solution;
}

