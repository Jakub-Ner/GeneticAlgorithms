#ifndef GENETICALG_PROBLEM_H
#define GENETICALG_PROBLEM_H


class Problem {
public:
    virtual bool loadTableFromFile(std::string &&filename) = 0;

    virtual bool createTable(float capacity, int itemsNum, float *spaceTable, float *valueTables) = 0;

    virtual float calculateSolutionValue(bool *gen) = 0;

    virtual int getGenSize() = 0;
};


#endif //GENETICALG_PROBLEM_H
