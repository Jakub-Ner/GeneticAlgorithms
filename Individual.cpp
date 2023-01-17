#include <iostream>
#include <cstring>
#include "Individual.h"
#include "Problem.h"
#include "NumberGenerator.h"

Individual::Individual(int size, short *gen) {
    m_gen_size = size;
    m_gen = gen;
    m_adaptation = 0;
}


void Individual::calculateAdaptation(Problem *problem) {
    m_adaptation = problem->calculateSolutionValue(m_gen);
}

void Individual::mutate(int nucleoidIdx) {
    m_gen[nucleoidIdx] = 1 - m_gen[nucleoidIdx];
}

void printGen2(short *gen, int genSize) {
    for (int i = 0; i < genSize; i++) {
        std::cout << gen[i];
    }
    std::cout << ";;  ";
}

void Individual::cross(Individual *otherParent, Individual *child1, Individual *child2, NumberGenerator *numGen) {
    int crossPoint = numGen->generateFromRange(1, m_gen_size - 1);

    memcpy(child1->m_gen, m_gen, crossPoint * sizeof(short));
    memcpy(child1->m_gen + crossPoint, otherParent->m_gen + crossPoint, (m_gen_size - crossPoint) * sizeof(short));

    memcpy(child2->m_gen, otherParent->m_gen, crossPoint * sizeof(short));
    memcpy(child2->m_gen + crossPoint, m_gen + crossPoint, (m_gen_size - crossPoint) * sizeof(short));
}

Individual::~Individual() {
    if (m_gen != NULL) {
        delete[] m_gen;
    }
}

//Individual &Individual::operator=(Individual &&other) {
//    if (this == &other) return *this;
//    if (m_gen != NULL) {
//        delete[] m_gen;
//    }
//    m_gen = other.m_gen;
//    m_gen_size = other.m_gen_size;
//    other.m_gen = NULL;
//    return *this;
//}

void Individual::operator=(Individual &other) {
    if (this == &other) {
        return;
    }
    memcpy(m_gen, other.m_gen, m_gen_size * sizeof(short));
    m_adaptation = other.m_adaptation;
}

int Individual::getGenSize() {
    return m_gen_size;
}

float Individual::getAdaptation() {
    return m_adaptation;
}

short *Individual::getGen() const {
    return m_gen;
}

