#ifndef GENETICALG_ITEMS_H
#define GENETICALG_ITEMS_H

class Items {
    int m_items_num;
    float *m_value;
    float *m_space;

public:
    ~Items();

    Items(int itemsNum, float *spaceTable, float *valueTables);

    Items &operator=(Items &&other);

    int getItemsNum() const;

    float getValue(int idx) const;

    float getSpace(int idx) const;
};

#endif //GENETICALG_ITEMS_H
