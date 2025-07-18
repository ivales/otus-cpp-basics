#pragma once


template <typename T>
class Array
{
    private:
        int m_size;
        int m_capacity;
        T * m_data;
    public:
        Array();
        Array(const Array<T> & a);
        Array(const Array<T> && a);
        Array(int size);
        ~Array();

        int max (int a, int b);
        void resize(int size);
        void push_back(T val);
        void insert(int pos, T val);
        void erase(int pos);
        int size() const;
        T& operator[] (int i);
        void print() const;
};

#include "array-impl.h"


