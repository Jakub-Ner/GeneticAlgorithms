#ifndef GENETICALG_INDIVIDUAL_H
#define GENETICALG_INDIVIDUAL_H

#include "Problem.h"
#include "NumberGenerator.h"

class Individual {

    bool *m_gen;
    int m_gen_size;
    float m_adaptation;

public:

    Individual();

    Individual(int size, bool *gen);

    void init(int size, bool *gen);

    ~Individual();

    void operator=(Individual &other);


    void calculateAdaptation(Problem *problem);

    void mutate(int nucleoidIdx);

    void cross(Individual *otherParent, Individual *child1, Individual *child2, NumberGenerator *numGen);

    bool *getGen() const;

    int getGenSize();

    float getAdaptation();

};


#endif //GENETICALG_INDIVIDUAL_H
