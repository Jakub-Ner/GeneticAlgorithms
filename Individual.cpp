#include <iostream>
#include <cstring>
#include "Individual.h"
#include "Problem.h"
#include "NumberGenerator.h"

Individual::Individual(int size) {
    m_gen_size = size;
    m_gen = new int[m_gen_size];
    m_adaptation = 0;

}

Individual::Individual() {
    m_gen_size = 0;
    m_gen = NULL;
    m_adaptation = 0;
}

void Individual::calculateAdaptation(Problem *problem) {
    m_adaptation = problem->calculateSolutionValue(m_gen);
}

void Individual::mutate(int nucleoidIdx) {
    m_gen[nucleoidIdx] = 1 - m_gen[nucleoidIdx];
}

void printGen2(int *gen, int genSize) {
    for (int i = 0; i < genSize; i++) {
        std::cout << gen[i];
    }
    std::cout << ";;  ";
}

void Individual::cross(Individual *otherParent, Individual *child1, Individual *child2, NumberGenerator *numGen) {
    int crossPoint = numGen->generateFromRange(1, m_gen_size - 1);

    memcpy(child1->m_gen, m_gen, crossPoint * sizeof(int));
    memcpy(child1->m_gen + crossPoint, otherParent->m_gen + crossPoint, (m_gen_size - crossPoint) * sizeof(int));

    memcpy(child2->m_gen, otherParent->m_gen, crossPoint * sizeof(int));
    memcpy(child2->m_gen + crossPoint, m_gen + crossPoint, (m_gen_size - crossPoint) * sizeof(int));
}

Individual::~Individual() {
    if (m_gen != NULL) {
        delete[] m_gen;
    }
}

Individual &Individual::operator=(Individual &&other) {
    if (this == &other) return *this;
    if (m_gen != NULL) {
        delete[] m_gen;
    }
    m_gen = other.m_gen;
    m_gen_size = other.m_gen_size;
    other.m_gen = NULL;
    return *this;
}

void Individual::operator=(Individual &other) {
    if (this == &other) {
        return;
    }
    if (m_gen != NULL) {
        delete[] m_gen;
    }
    m_gen_size = other.m_gen_size;
    m_gen = other.m_gen;

}

int Individual::getGenSize() {
    return m_gen_size;
}

double Individual::getAdaptation() {
    return m_adaptation;
}


