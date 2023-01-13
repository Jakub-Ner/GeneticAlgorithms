#include <iostream>
#include "Items.h"

//Items::Items() {
//    m_items_num = 0;
//    m_space = NULL;
//    m_value = NULL;
//}

Items::Items(int itemsNum, double *spaceTable, double *valueTables) {
    m_items_num = itemsNum;
    m_space = spaceTable;
    m_value = valueTables;
}

Items &Items::operator=(Items &&other) {
    if (this == &other) return *this;

    m_items_num = other.m_items_num;
    m_space = other.m_space;
    m_value = other.m_value;

    other.m_space = NULL;
    other.m_value = NULL;

    return *this;
}

int Items::getItemsNum() const {
    return m_items_num;
}

double Items::getValue(int idx) const {
    return m_value[idx];
}

double Items::getSpace(int idx) const {
    return m_space[idx];
}


