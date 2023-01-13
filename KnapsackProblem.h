#ifndef GENETICALG_KNAPSACKPROBLEM_H
#define GENETICALG_KNAPSACKPROBLEM_H


#include "Items.h"
#include "Problem.h"

class KnapsackProblem: public Problem {
    Items *m_items;
    int m_capacity;

public:
    KnapsackProblem();

    bool loadTableFromFile() override;

    bool createTable(int capacity, int itemsNum, double *spaceTable, double *valueTables) override;

    double calculateSolutionValue(int* gen) override;

    int getGenSize() override;

    void operator=(KnapsackProblem& other);
};


#endif //GENETICALG_KNAPSACKPROBLEM_H
