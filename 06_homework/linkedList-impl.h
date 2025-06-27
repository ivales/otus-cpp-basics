#pragma once

#include <cstddef>
#include <iostream>
#include "list.h"

template <typename T>
struct LinkedList<T>::Node {
    Node() {
        m_next = nullptr;
        m_previous = nullptr;
    };
    Node(const T& data) {
        m_data = data;
        m_next = nullptr;
        m_previous = nullptr;
    }
    T m_data;
    Node* m_next;
    Node* m_previous;

};
template <typename T>
class LinkedList<T>::Iter {
    private:
        typename LinkedList<T>::Node* m_current;
    public:
        Iter (LinkedList<T>::Node* node) : m_current(node) {};

        const T& operator *() const {
            return m_current->m_data;
        }

        Iter& operator ++() {
            if (m_current.m_next != nullptr) {
                m_current = m_current->m_next;
            }
            return *this;
        }

        Iter& operator --() {
            if (m_current.m_previous != nullptr) {
                m_current = m_current->m_previous;
            }
            return *this;
        }
        
        typename LinkedList<T>::Node* get() const {
            return m_current;
        }

        typename LinkedList<T>::Node* next() const {
            return m_current->m_next;
        }

        typename LinkedList<T>::Node* prev() const {
            return m_current->m_previous;
        }
};

template <typename T>
LinkedList<T>::LinkedList() {
    m_head = nullptr;
    m_tail = nullptr;
    this->m_size = 0;

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& a) {
    m_head = a.begin();
    m_tail = a.end();
    this->m_size = a.size();
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (this->m_head != nullptr) {
        erase();
    }
}

template <typename T>
void LinkedList<T>::push_back(T val) {
    Node* node = new Node(val);
    if (List<T>::isEmpty()) {
        m_head = node;
        m_tail = m_head;
    }
    else {
        m_tail->m_next = node;
        node->m_previous = m_tail;
        m_tail = node;
    }
    this->m_size++;
}

template <typename T>
void LinkedList<T>::insert(size_t pos, T val) {
    Node* node = new Node(val);
    if (List<T>::isEmpty()) {
        push_back(val);
        this->m_size++;
        return;
    }
    if (pos == 0) {
        m_head->m_previous = node;
        node->m_next = m_head;
        m_head = node;
        this->m_size++;
        return;
    }
    if (List<T>::outOfRange(pos)) return;
    Node* prevNode = m_head;
    size_t cur_pos = 0;
    while (cur_pos < pos - 1) {
        prevNode = prevNode->m_next;
        cur_pos++;
    }
    Node* nextNode = prevNode->m_next;
    prevNode->m_next = node;
    node->m_previous = prevNode;
    nextNode->m_previous = node;
    node->m_next = nextNode;

    this->m_size++;
}

template <typename T>
void LinkedList<T>::erase(size_t pos) {
    if (List<T>::isEmpty()) return;
    if (List<T>::outOfRange(pos)) exit;
    if (List<T>::size() == 1) {
        delete this->m_head;
        this->m_head = nullptr;
        this->m_tail = nullptr;
        this->m_size = 0;
        return;
    }
    Node* intermediateNode = this->m_head;
    size_t cur_pos = 0;
        while (cur_pos < pos ) {
            intermediateNode = intermediateNode->m_next;
            cur_pos++;
        }
        intermediateNode->m_previous->m_next = intermediateNode->m_next;
        intermediateNode->m_next->m_previous = intermediateNode->m_previous;
        delete intermediateNode;
        this->m_size--;
}

template <typename T>
typename LinkedList<T>::Iter begin() {
    typename LinkedList<T>::Iter iter(typename LinkedList<T>::m_head);
    return iter;

}

template <typename T>
typename LinkedList<T>::Iter end() {
    typename LinkedList<T>::Iter iter(typename LinkedList<T>::m_tail);
    return iter;
}

template <typename T>
T& LinkedList<T>::operator[] (const size_t pos) const {
    if (List<T>::outOfRange(pos)) exit;
    Node* intermediateNode = this->m_head;
    size_t cur_pos = 0;
    while (cur_pos < pos) {
        intermediateNode = intermediateNode->m_next;
        cur_pos++;
    }
    return intermediateNode->m_data;
}

template <typename T>
void LinkedList<T>::print() const {
    Node* intermediateNode = m_head;
    while (intermediateNode != nullptr) {
        std::cout << intermediateNode->m_data << " ";
        intermediateNode = intermediateNode->m_next;
    }
    std::cout << std::endl;
}






