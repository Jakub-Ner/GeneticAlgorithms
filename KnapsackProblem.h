#ifndef GENETICALG_KNAPSACKPROBLEM_H
#define GENETICALG_KNAPSACKPROBLEM_H


#include <string>
#include "Items.h"
#include "Problem.h"

class KnapsackProblem : public Problem {
    Items *m_items;
    float m_capacity;

public:
    KnapsackProblem();

    bool loadTableFromFile(std::string &&filename) override;

    bool createTable(float capacity, int itemsNum, float *spaceTable, float *valueTables) override;

    float calculateSolutionValue(short *gen) override;

    int getGenSize() override;

    void operator=(KnapsackProblem &other);
};


#endif //GENETICALG_KNAPSACKPROBLEM_H
