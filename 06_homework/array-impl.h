#pragma once


#include <cstddef>
#include <iostream>
#include "array.h"

template <typename T>
Array<T>::Array() {
    m_size = 0;
    m_capacity = 0;
    m_data = NULL;
}

template <typename T>
Array<T>::Array(const Array<T> & a) {
    m_size = a.m_size;
    m_capacity = m_size;
    m_data = NULL;
    if (m_size != 0)
        m_data = new T[m_size];
    else
        m_data = 0;
    for (int i = 0; i < m_size; ++i)
        m_data[i] = a.m_data[i];
}

template <typename T>
Array<T>::Array(int size) {
    m_size = size;
    m_capacity = size;
    if (size != 0)
        m_data = new T[size];
    else
        m_data = 0;
}

template <typename T>
Array<T>::~Array() {
    if (m_data)
        delete[] m_data;
}

template <typename T>
int Array<T>::max (int a, int b) {
    return a < b ? a : b;
}

template <typename T>
void Array<T>::resize(int size) {
    if (size > m_capacity) {
        int new_capacity = max(size, m_size * 2);
        T * new_data = new T[new_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_size = size;
}

template <typename T>
void Array<T>::push_back(T val) {
    resize(m_size + 1);
    m_data[m_size - 1] = val;
}

template <typename T>
void Array<T>::insert(int pos, T val) {
    resize(m_size + 1);
    for (int i = m_size; i > pos; --i) {
        m_data[i] = m_data[i-1];
    }
    m_data[pos] = val;
}

template <typename T>
void Array<T>::erase(int pos) {
    for (int i = pos; i < m_size; ++i) {
        m_data[i] = m_data[i+1];
    }
    m_size -= 1;
}

template <typename T>
int Array<T>::size() const {
    return m_size;
}

template <typename T>
T& Array<T>::operator[] (int i) {
    return m_data[i];
}

template <typename T>
void Array<T>::print() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}



