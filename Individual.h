#ifndef GENETICALG_INDIVIDUAL_H
#define GENETICALG_INDIVIDUAL_H

#include "SmartPtr.h"

class Individual {
public:
    int *m_gen;
    int m_gen_size;

public:
    Individual(int size);

    Individual();

    ~Individual();

    void operator=(Individual& other);
    Individual& operator=(Individual&& other);

    int calculateAdaptation();

    void mutate();

    SmartPtr<Individual> cross();

};


#endif //GENETICALG_INDIVIDUAL_H
