#pragma once


template <typename T>
class List { 
    public:
        int m_size;
        bool isEmpty() const;
        bool outOfRange(const size_t pos) const;
        size_t size() const;
        virtual void push_back(T val) = 0;
        virtual void insert(size_t pos, T val) = 0;
        virtual void erase(size_t pos = 0) = 0;
        virtual T& operator[] (const size_t pos) const = 0;
        virtual void print() const = 0;
};

template <typename T>
class ForwardList : public List<T> {
    private:
        struct Node;
        class Iter;
        Node* m_head;
    public:            
        ForwardList();
        ForwardList(const ForwardList<T>& a);
        ForwardList(ForwardList<T>&& a);
        ~ForwardList();
        Iter begin();
        Iter end();
        void push_back(T val) override;
        void insert(size_t pos, T val) override;
        void erase(size_t pos = 0) override;
        T& operator[] (const size_t pos) const override;
        void print() const override;
};

template <typename T>
class LinkedList : public List<T> {
    private:
        struct Node;
        class Iter;
        Node* m_head;
        Node* m_tail;
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& a);
        LinkedList(LinkedList<T>&& a);
        ~LinkedList();
        Iter begin();
        Iter end();
        void push_back(T val) override ;
        void insert(size_t pos, T val) override;
        void erase(size_t pos = 0) override;
        T& operator[] (const size_t pos) const override;
        void print() const override;
};

#include "list-impl.h"
#include "forwardList-impl.h"
#include "linkedList-impl.h"


