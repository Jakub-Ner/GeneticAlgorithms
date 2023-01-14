#include <random>
#include <iostream>

#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, double crossProb, double mutProb, Problem *problem) {
    m_pop_size = popSize;
    m_cross_prob = crossProb;
    m_mut_prob = mutProb;

    m_problem = problem;
    m_population = new Individual *[2 * popSize];
    m_num_generator = new NumberGenerator();
    generatePop();
}

void printAllSolution(Individual **population, int popSize, int shift) {
    for (int i = shift; i < popSize + shift; i++) {
        std::cout << ";; ";
        for (int j = 0; j < population[i]->getGenSize(); j++) {
            std::cout << population[i]->m_gen[j];
            if (j+1 == population[i]->getGenSize())
                std::cout<<"A:"<<population[i]->getAdaptation();
        }
    }
    std::cout << "\n";
}

void GeneticAlgorithm::generatePop() {
    m_num_generator->setRange(0, 1);

    int genSize = m_problem->getGenSize();

    for (int i = 0; i < m_pop_size; i++) {
        m_population[i] = new Individual(genSize);
        m_population[i + m_pop_size] = new Individual(genSize);
        std::cout << "; ";
        for (int j = 0; j < genSize; j++) {
            int nucleotide = m_num_generator->generate();
            m_population[i]->m_gen[j] = nucleotide;
            m_population[i + m_pop_size]->m_gen[j] = nucleotide;
            std::cout << m_population[i + m_pop_size]->m_gen[j];
        }
    }
    std::cout << std::endl;
}

void GeneticAlgorithm::findBestSolution(int iterationsNumber) {
    int even = 0;
    for (int j = 0; j < iterationsNumber; j++) {
        int shift = even * m_pop_size;

        for (int i = 0; i < m_pop_size; i++) {
            m_population[i + shift]->calculateAdaptation(m_problem);
        }

        m_num_generator->setRange(shift, m_pop_size + shift - 1);
        int counterShift = ((even + 1) % 2) * m_pop_size;
        for (int i = 0; i < m_pop_size / 2; i++) {
            applyCross(i + counterShift); // what if pop_size is uneven
        }

        for (int i = 0; i < m_pop_size; i++) {
            applyMut(m_population[i + counterShift]);
        }
        printAllSolution(m_population, m_pop_size, shift); // print parents
        even = (even + 1) % 2;
    }

    for (int i = 0; i < m_pop_size; i++) {
        m_population[i + even * m_pop_size]->calculateAdaptation(m_problem);
    }
    printAllSolution(m_population, m_pop_size, even * m_pop_size); // print parents
    m_best_solution = findBest();
}

void GeneticAlgorithm::applyMut(Individual *pIndividual) {
    for (int i = 0; i < pIndividual->getGenSize(); i++) {
        if (m_num_generator->generate() < m_mut_prob) {
            pIndividual->mutate(0);
        }
    }
}

void printGen(int *gen, int genSize) {
    for (int i = 0; i < genSize; i++) {
        std::cout << gen[i];
    }
    std::cout << ";;  ";
}

void GeneticAlgorithm::applyCross(int childIdx) {
    if (shouldCross()) {
        Individual *first = selectParent();
        Individual *second = selectParent();

//        std::cout<<"\n";
//        printGen(m_population[childIdx]->m_gen, m_population[childIdx]->getGenSize());
//        printGen(m_population[childIdx + 1]->m_gen, m_population[childIdx + 1]->getGenSize());
        first->cross(second, m_population[childIdx], m_population[childIdx + 1], m_num_generator);

//        printGen(m_population[childIdx]->m_gen, m_population[childIdx]->getGenSize());
//        printGen(m_population[childIdx + 1]->m_gen, m_population[childIdx + 1]->getGenSize());
//        std::cout<<"\n";
    }
}

bool GeneticAlgorithm::shouldCross() {
    double crossValue = m_num_generator->generateDouble();
    if (crossValue < m_cross_prob) {
        return true;
    }
    return false;
}

Individual *GeneticAlgorithm::selectParent() {
    Individual *first = m_population[m_num_generator->generate()];
    Individual *second = m_population[m_num_generator->generate()];
    return first->getAdaptation() > second->getAdaptation() ? first : second;
}

Individual *GeneticAlgorithm::findBest() {
    Individual *best = m_population[0];
    for (int i = 0; i < m_pop_size; i++) {
        if (m_population[i]->getAdaptation() > best->getAdaptation()) {
            best = m_population[i];
        }
    }
    return best;
}

GeneticAlgorithm::~GeneticAlgorithm() {
    if (m_population != NULL) {
        for (int i = 0; i < 2 * m_pop_size; i++) {
            delete m_population[i];
        }
        delete[] m_population;
    }
    if (m_num_generator != NULL) {
        delete m_num_generator;
    }

}

Individual *GeneticAlgorithm::getBestSolution() {
    return m_best_solution;
}

