#include "KnapsackProblem.h"
#include "FileReader.h"

KnapsackProblem::KnapsackProblem() {
    m_capacity = 0;
    m_items = NULL;
}

bool KnapsackProblem::loadTableFromFile(std::string &&filename) {
    FileReader fileReader("/home/jakubner/CLionProjects/GeneticAlg/data.txt");

    int itemsNum;
    float *spaceTable;
    float *valueTable;
    bool ok = fileReader.readFromFile(&m_capacity, &itemsNum, &spaceTable, &valueTable);
    if (!ok) {
        return false;
    }
    m_items = new Items(itemsNum, spaceTable, valueTable);
    return true;
}

bool KnapsackProblem::createTable(float capacity, int itemsNum, float *spaceTable, float *valueTables) {
    if (spaceTable == NULL || valueTables == NULL) {
        return false;
    }
    if (capacity <= 0 || itemsNum <= 0) {
        delete[] spaceTable;
        delete[] valueTables;
        return false;
    }
    m_capacity = capacity;
    m_items = new Items(itemsNum, spaceTable, valueTables);
    return true;
}

float KnapsackProblem::calculateSolutionValue(bool *gen) {
    float totalSpace = 0;
    float totalValue = 0;

    for (int i = 0; i < m_items->getItemsNum(); i++) {
        if (gen[i] == true) {
            totalSpace += m_items->getSpace(i);
            totalValue += m_items->getValue(i);
        }
    }
    if (totalSpace > m_capacity) {
        return 0;
    }
    return totalValue;
}

void KnapsackProblem::operator=(KnapsackProblem &other) {
    if (this == &other) {
        return;
    }
    m_capacity = other.m_capacity;
    m_items = other.m_items;

}

int KnapsackProblem::getGenSize() {
    if (m_items == NULL) {
        return 0;
    }
    return m_items->getItemsNum();
}

KnapsackProblem::~KnapsackProblem() {
    if (m_items != NULL) {
        delete m_items;
    }
}
