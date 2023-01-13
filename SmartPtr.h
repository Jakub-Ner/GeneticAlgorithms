#ifndef LISTA_1_SMARTPTR_H
#define LISTA_1_SMARTPTR_H

#include <iostream>

template<typename T>
class SmartPtr {
private:
    T *m_ptr;
    int *m_ref_count;
public:
    SmartPtr(T *ptr) {
        m_ptr = ptr;
        m_ref_count = new int(1);
    }

    SmartPtr(SmartPtr<T> &other) {
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;
        (*m_ref_count)++;
    }


    ~SmartPtr() {
        if (--(*m_ref_count) == 0) {
            delete m_ptr;
            delete m_ref_count;
        }
    }


    T &operator*() {
        return *m_ptr;
    }

    T *operator->() {
        return m_ptr;
    }

    void operator=(SmartPtr<T> &other) {
        if (this == &other) {
            return;
        }
        if (m_ptr != NULL and --(*m_ref_count) == 0) {
            delete m_ptr;
            delete m_ref_count;
        }
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;
        (*m_ref_count)++;
    }

    SmartPtr<T> &operator=(SmartPtr<T> &&other) {
        if (this == &other) return *this;

        if (m_ptr != NULL and --(*m_ref_count) == 0) {
            delete m_ptr;
            delete m_ref_count;
        }
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;

        other.m_ref_count = NULL;
        other.m_ptr = NULL;

        return *this;
    }


    int getRefCount() const {
        return *m_ref_count;
    }

    SmartPtr() {
        m_ptr = NULL;
        m_ref_count = NULL;
    }
};


#endif //LISTA_1_SMARTPTR_H
