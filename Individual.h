#ifndef GENETICALG_INDIVIDUAL_H
#define GENETICALG_INDIVIDUAL_H

#include "Problem.h"
#include "NumberGenerator.h"

class Individual {
    short *m_gen;
    int m_gen_size;
    float m_adaptation;

public:

    Individual(int size, short *gen);

    ~Individual();

    void operator=(Individual &other);

//    Individual &operator=(Individual &&other);

    void calculateAdaptation(Problem *problem);

    void mutate(int nucleoidIdx);

    void cross(Individual *otherParent, Individual *child1, Individual *child2, NumberGenerator *numGen);

    short *getGen() const;

    int getGenSize();

    float getAdaptation();

};


#endif //GENETICALG_INDIVIDUAL_H
