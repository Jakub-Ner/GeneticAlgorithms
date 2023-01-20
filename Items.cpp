#include <iostream>
#include "Items.h"

Items::Items(int itemsNum, float *spaceTable, float *valueTables) {
    m_items_num = itemsNum;
    m_space = spaceTable;
    m_value = valueTables;
}

int Items::getItemsNum() const {
    return m_items_num;
}

float Items::getValue(int idx) const {
    return m_value[idx];
}

float Items::getSpace(int idx) const {
    return m_space[idx];
}

Items::~Items() {
    if (m_space != NULL) {
        delete[] m_space;
    }
    if (m_value != NULL) {
        delete[] m_value;
    }

}


