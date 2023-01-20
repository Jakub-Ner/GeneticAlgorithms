#ifndef GENETICALG_NUMBERGENERATOR_H
#define GENETICALG_NUMBERGENERATOR_H

#include <random>

class NumberGenerator {

    std::random_device m_rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 m_gen; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> m_distrib;
    std::uniform_real_distribution<> m_real_distrib;

public:

    NumberGenerator(int seed);

    void setRange(int min, int max);

    int generate();

    int generateFromRange(int min, int max);

    double generateDouble();
};

#endif //GENETICALG_NUMBERGENERATOR_H
