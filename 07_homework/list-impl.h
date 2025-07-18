#pragma once

#include <cstddef>
#include <iostream>


template <typename T>
int List<T>::size() const {
    return m_size;
}

template <typename T>
bool List<T>::isEmpty() const {
    return m_size == 0;
}

template <typename T>
bool List<T>::outOfRange(const int pos) const {
    if (pos > m_size-1) {
        std::cout << "Заданная позиция находится за пределами диапазона списка" << std::endl;
        return true;
    }
    return false;
}
