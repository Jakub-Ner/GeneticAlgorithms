#include <random>
#include <iostream>

#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, double crossProb, double mutProb, Problem *problem, int seed) {
    m_pop_size = popSize % 2 == 0 ? popSize : popSize + 1;
    m_cross_prob = crossProb;
    m_mut_prob = mutProb;

    m_problem = problem;
    m_population = new Individual[2 * m_pop_size];

    m_num_generator = new NumberGenerator(seed);
    generatePop();
    m_best_solution = new Individual(m_problem->getGenSize(), new bool[m_problem->getGenSize()]);
}


void GeneticAlgorithm::printSolution(Individual *pIndividual) {
    for (int i = 0; i < pIndividual->getGenSize(); i++) {
        std::cout << pIndividual->getGen()[i];
    }
    std::cout << ": " << pIndividual->getAdaptation();

}

void GeneticAlgorithm::generatePop() {
    m_num_generator->setRange(0, 1);

    int genSize = m_problem->getGenSize();

    for (int i = 0; i < m_pop_size; i++) {
        bool *gen = new bool[genSize];
        for (int j = 0; j < genSize; j++) {
            bool nucleotide = m_num_generator->generate();
            gen[j] = nucleotide;
        }
        m_population[i].init(genSize, gen);
        m_population[i + m_pop_size].init(genSize, new bool[genSize]);
    }
}

void GeneticAlgorithm::findBestSolution(int iterationsNumber) {
    if (m_problem->getGenSize() == 0) return;

    int even = 0;
    int shift = 0;
    for (int j = 0; j < iterationsNumber; j++) {
        adaptPopulation(shift);
        findBest();
        if (j % 200 == 0) {
            std::cout << "\nBest solution: ";
            printSolution(m_best_solution);
        }

        m_num_generator->setRange(shift, m_pop_size + shift - 1);
        even = (even + 1) % 2;
        shift = even * m_pop_size;

        crossPopulation(shift);
        mutatePopulation(shift);

    }
    adaptPopulation(shift);
    findBest();
    std::cout << "\nBest solution: ";
    printSolution(m_best_solution);
}

void GeneticAlgorithm::adaptPopulation(int shift) {
    for (int i = 0; i < m_pop_size; i++) {
        m_population[i + shift].calculateAdaptation(m_problem);
    }
}

void GeneticAlgorithm::crossPopulation(int shift) {
    for (int i = 0; i < m_pop_size / 2; i++) {
        applyCross2Individual(i + shift);
    }
}

void GeneticAlgorithm::mutatePopulation(int shift) {
    for (int i = 0; i < m_pop_size; i++) {
        applyMut2Individual(&m_population[i + shift]);
    }
}

void GeneticAlgorithm::applyMut2Individual(Individual *pIndividual) {
    for (int i = 0; i < pIndividual->getGenSize(); i++) {
        if (m_num_generator->generateDouble() < m_mut_prob) {
            pIndividual->mutate(0);
        }
    }
}

void GeneticAlgorithm::applyCross2Individual(int childIdx) {
    if (m_num_generator->generateDouble() < m_cross_prob) {
        Individual *first = selectParent();
        Individual *second = selectParent();

        first->cross(second, &m_population[childIdx], &m_population[childIdx + 1], m_num_generator);
    }
}

Individual *GeneticAlgorithm::selectParent() {
    Individual *first = &m_population[m_num_generator->generate()];
    Individual *second = &m_population[m_num_generator->generate()];
    return first->getAdaptation() > second->getAdaptation() ? first : second;
}

void GeneticAlgorithm::findBest() {
    for (int i = 0; i < m_pop_size; i++) {
        if (m_population[i].getAdaptation() > m_best_solution->getAdaptation()) {
            *m_best_solution = m_population[i];
        }
    }
}

GeneticAlgorithm::~GeneticAlgorithm() {
    if (m_population != NULL) {
        delete[] m_population;
    }
    if (m_num_generator != NULL) {
        delete m_num_generator;
    }
    if (m_best_solution != NULL) {
        delete m_best_solution;
    }

}

Individual *GeneticAlgorithm::getBestSolution() {
    return m_best_solution;
}

