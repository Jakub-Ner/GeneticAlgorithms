#include "Individual.h"

Individual::Individual(int size) {
    m_gen_size = size;
    m_gen = new int[m_gen_size];
}

Individual::Individual() {
    m_gen_size = 0;
    m_gen = NULL;

}

int Individual::calculateAdaptation() {
    return 0;
}

void Individual::mutate() {

}

SmartPtr<Individual> Individual::cross() {
    SmartPtr<Individual> newCross(NULL);
    return newCross;
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

