#pragma once

#include <cstddef>
#include <iostream>
#include "list.h"


template <typename T>
class List<T>::Iter {
    private:
        Node* m_current;
    public:
        Iter (Node* node) : m_current(node) {};

        const T& operator *() const {
            return m_current->m_data;
        }

        Iter& operator ++() {
            if (m_current != nullptr) {
                m_current = m_current->m_next;
            }
            return *this;
        }
        
        Node* get() const {
            return m_current;
        }

        Node* next() const {
            return m_current->m_next;
        }
};

template <typename T>
List<T>::List() {
    m_head = nullptr;
    m_size = 0;

}

template <typename T>
List<T>::List(const List<T>& a) {
    m_head = a.begin();
    m_size = a.size();
}

template <typename T>
List<T>::~List() {
    while (m_head != nullptr) {
        erase();
    }
}

template <typename T>
void List<T>::push_back(T val) {
    Node* node = new Node(val);
    if (isEmpty()) {
        m_head = node;
    }
    else {
        Node* lastNode = end().get();
        lastNode->m_next = node;
    }
    m_size++;
}

template <typename T>
void List<T>::insert(size_t pos, T val) {
    Node* node = new Node(val);
    if (isEmpty()) {
        push_back(val);
        m_size++;
        return;
    }
    if (pos == 0) {
        node->m_next = m_head;
        m_head = node;
        m_size++;
        return;
    }
    if (outOfRange(pos)) return;
    Node* intermediateNode = m_head;
    size_t cur_pos = 0;
    while (cur_pos < pos - 1) {
        intermediateNode = intermediateNode->m_next;
        cur_pos++;
    }
    node->m_next = intermediateNode->m_next;
    intermediateNode->m_next = node;
    m_size++;
}

template <typename T>
void List<T>::erase(size_t pos) {
    if (isEmpty()) return;
    if (outOfRange(pos)) exit;
    if (size() == 1) {
        delete m_head;
        m_head = nullptr;
        m_size = 0;
        return;
    }
    Node* intermediateNode = m_head;
    size_t cur_pos = 0;
        while (cur_pos < pos-1) {
            intermediateNode = intermediateNode->m_next;
            cur_pos++;
        }
        Node* deleteNode = intermediateNode->m_next;
        deleteNode->m_next == nullptr ? intermediateNode->m_next = nullptr : intermediateNode->m_next = deleteNode->m_next;
        delete deleteNode;
        m_size--;
}

template <typename T>
size_t List<T>::size() const {
    return m_size;
}

template <typename T>
bool List<T>::isEmpty() const {
    return m_head == nullptr;
}

template <typename T>
bool List<T>::outOfRange(int pos) {
    if (pos > m_size-1) {
        std::cout << "Заданная позиция находится за пределами диапазона списка" << std::endl;
        return true;
    }
    return false;
}

template <typename T>
typename List<T>::Iter List<T>::begin() const {
    return Iter(m_head);
}

template <typename T>
typename List<T>::Iter List<T>::end() const {
    Iter iter(m_head);
    while (iter.next() != nullptr) {
        ++iter;
    }
    return iter;
}

template <typename T>
T& List<T>::operator[] (size_t pos) const {
    if (outOfRange(pos)) exit;
    Node* intermediateNode = m_head;
    size_t cur_pos = 0;
    while (cur_pos < pos) {
        intermediateNode = intermediateNode->m_next;
        cur_pos++;
    }
    return intermediateNode->m_data;
}

template <typename T>
void List<T>::print() const {
    Node* intermediateNode = m_head;
    while (intermediateNode != nullptr) {
        std::cout << intermediateNode->m_data << " ";
        intermediateNode = intermediateNode->m_next;
    }
    std::cout << std::endl;
}



