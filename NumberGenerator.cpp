#include "NumberGenerator.h"

NumberGenerator::NumberGenerator() {
    m_real_distrib = std::uniform_real_distribution<>(0.0, 1.0);
}

void NumberGenerator::setRange(int min, int max) {
    m_distrib = std::uniform_int_distribution<>(min, max);
}

int NumberGenerator::generateFromRange(int min, int max) {
    return std::uniform_int_distribution<>(min, max)(m_gen);
}

int NumberGenerator::generate() {
    return m_distrib(m_gen);
}

double NumberGenerator::generateDouble() {
    return m_real_distrib(m_gen);
}
