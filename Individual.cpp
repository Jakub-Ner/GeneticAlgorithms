#include <iostream>
#include <cstring>
#include "Individual.h"
#include "Problem.h"
#include "NumberGenerator.h"

Individual::Individual() {
    m_gen = NULL;
    m_gen_size = 0;
    m_adaptation = 0;
}

Individual::Individual(int size, bool *gen) {
    init(size, gen);
    m_adaptation = 0;
}

void Individual::init(int size, bool *gen) {
    m_gen_size = size;
    m_gen = gen;
}


void Individual::calculateAdaptation(Problem *problem) {
    m_adaptation = problem->calculateSolutionValue(m_gen);
}

void Individual::mutate(int nucleoidIdx) {
    m_gen[nucleoidIdx] = 1 - m_gen[nucleoidIdx];
}

void Individual::cross(Individual *otherParent, Individual *child1, Individual *child2, NumberGenerator *numGen) {
    int crossPoint = numGen->generateFromRange(1, m_gen_size - 1);

    memcpy(child1->m_gen, m_gen, crossPoint * sizeof(bool));
    memcpy(child1->m_gen + crossPoint, otherParent->m_gen + crossPoint, (m_gen_size - crossPoint) * sizeof(bool));

    memcpy(child2->m_gen, otherParent->m_gen, crossPoint * sizeof(bool));
    memcpy(child2->m_gen + crossPoint, m_gen + crossPoint, (m_gen_size - crossPoint) * sizeof(bool));
}

Individual::~Individual() {
    if (m_gen != NULL) {
        delete[] m_gen;
    }
}


void Individual::operator=(Individual &other) {
    if (this == &other) {
        return;
    }
    memcpy(m_gen, other.m_gen, m_gen_size * sizeof(bool));
    m_adaptation = other.m_adaptation;
}

int Individual::getGenSize() {
    return m_gen_size;
}

float Individual::getAdaptation() {
    return m_adaptation;
}

bool *Individual::getGen() const {
    return m_gen;
}

