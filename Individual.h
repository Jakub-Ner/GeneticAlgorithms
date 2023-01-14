#ifndef GENETICALG_INDIVIDUAL_H
#define GENETICALG_INDIVIDUAL_H

#include "Problem.h"
#include "NumberGenerator.h"

class Individual {
public:
    int *m_gen;

private:
    int m_gen_size;
    double m_adaptation;

public:
    Individual();

    Individual(int size);

    ~Individual();

    void operator=(Individual &other);

    Individual &operator=(Individual &&other);

    void calculateAdaptation(Problem *problem);

    void mutate(int nucleoidIdx);

    void cross(Individual *otherParent, Individual *child1, Individual *child2, NumberGenerator *numGen);

    int getGenSize();

    double getAdaptation();

};


#endif //GENETICALG_INDIVIDUAL_H
