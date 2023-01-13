#include "KnapsackProblem.h"
#include <iostream>

KnapsackProblem::KnapsackProblem() {
    m_capacity = 0;
    m_items = NULL;
}

// TODO
bool KnapsackProblem::loadTableFromFile() {
    return false;
}

bool KnapsackProblem::createTable(int capacity, int itemsNum, double *spaceTable, double *valueTables) {
    if (capacity <= 0 || itemsNum <= 0 || spaceTable == NULL || valueTables == NULL) {
        return false;
    }
    m_capacity = capacity;
    m_items = new Items(itemsNum, spaceTable, valueTables);
    return true;
}

double KnapsackProblem::calculateSolutionValue(int* gen) {
    double totalSpace = 0;

}

void KnapsackProblem::operator=(KnapsackProblem &other) {
    if (this == &other) {
        return;
    }
    m_capacity = other.m_capacity;
    m_items = other.m_items;

}

int KnapsackProblem::getGenSize() {
    return m_items->getItemsNum();
}
