#ifndef GENETICALG_ITEMS_H
#define GENETICALG_ITEMS_H

class Items {
    int m_items_num;
    double *m_value;
    double *m_space;

public:
//    Items();

    Items(int itemsNum, double *spaceTable, double *valueTables);

    Items& operator=(Items&& other);

    int getItemsNum() const;

    double getValue(int idx) const;

    double getSpace(int idx) const;
};

#endif //GENETICALG_ITEMS_H
