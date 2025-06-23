#pragma once


template <typename T>
class List {
    private:
        struct Node {
            Node() {
                m_next = nullptr;
            };
            Node(const T& data) {
                m_data = data;
                m_next = nullptr;
            }
            T m_data;
            Node* m_next;
        };
        Node* m_head;
        int m_size;
        
    public:
        class Iter;

        List();
        List(const List<T>& a);
        ~List();

        void push_back(T val);
        void insert(size_t pos, T val);
        void erase(size_t pos = 0);
        size_t size() const;
        bool isEmpty() const;
        bool outOfRange(const size_t pos) const;
        typename List<T>::Iter begin() const;
        typename List<T>::Iter end() const;
        T& operator[] (const size_t pos) const;
        void print() const;
};

#include "list-impl.h"


