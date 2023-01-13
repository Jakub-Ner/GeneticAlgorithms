#ifndef GENETICALG_PROBLEM_H
#define GENETICALG_PROBLEM_H


class Problem {
public:
    virtual bool loadTableFromFile() = 0;

    virtual bool createTable(int capacity, int itemsNum, double *spaceTable, double *valueTables) = 0;

    virtual double calculateSolutionValue(int *gen) = 0;

    virtual int getGenSize() = 0;
};


#endif //GENETICALG_PROBLEM_H
