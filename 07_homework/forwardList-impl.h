#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
struct ForwardList<T>::Node {
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

template <typename T>
class ForwardList<T>::Iter {
    private:
        typename ForwardList<T>::Node* m_current;
    public:
        Iter (ForwardList<T>::Node* node) : m_current(node) {};

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
ForwardList<T>::ForwardList() {
    this->m_head = nullptr;
    this->m_size = 0;

}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList<T>& a) {
    m_head = a.begin().get();
    this->m_size = a.size();
}

template <typename T>
ForwardList<T>::ForwardList(ForwardList<T>&& a) {
    m_head = a.begin().get();
    this->m_size = a.size();
}

template <typename T>
ForwardList<T>::~ForwardList() {
    while (this->m_head != nullptr) {
        erase();
    }
}

template <typename T>
void ForwardList<T>::push_back(T val) {
    Node* node = new Node(val);
    if (List<T>::isEmpty()) {
        this->m_head = node;
    }
    else {
        Node* intermediateNode = this->m_head;
        while (intermediateNode->m_next != nullptr) {
            intermediateNode = intermediateNode->m_next;
        }
            intermediateNode->m_next = node;
    }
    this->m_size++;
}

template <typename T>
void ForwardList<T>::insert(int pos, T val) {
    Node* node = new Node(val);
    if (List<T>::isEmpty()) {
        push_back(val);
        this->m_size++;
        return;
    }
    if (pos == 0) {
        node->m_next = this->m_head;
        this->m_head = node;
        this->m_size++;
        return;
    }
    if (List<T>::outOfRange(pos)) return;
    Node* intermediateNode = this->m_head;
    int cur_pos = 0;
    while (cur_pos < pos - 1) {
        intermediateNode = intermediateNode->m_next;
        cur_pos++;
    }
    node->m_next = intermediateNode->m_next;
    intermediateNode->m_next = node;
    this->m_size++;
}

template <typename T>
void ForwardList<T>::erase(int pos) {
    if (List<T>::isEmpty()) return;
    if (List<T>::outOfRange(pos)) return;
    if (List<T>::size() == 1) {
        delete this->m_head;
        this->m_head = nullptr;
        this->m_size = 0;
        return;
    }
    if (pos == 0) {
        Node* deleteNode = this->m_head;
        this->m_head = deleteNode->m_next;
        delete deleteNode;
        this->m_size--;
        return;
    }
    Node* intermediateNode = this->m_head;
    int cur_pos = 0;
    while (cur_pos < pos-1) {
        intermediateNode = intermediateNode->m_next;
        cur_pos++;
    }
    Node* deleteNode = intermediateNode->m_next;
    deleteNode->m_next == nullptr ? intermediateNode->m_next = nullptr : intermediateNode->m_next = deleteNode->m_next;
    delete deleteNode;
    this->m_size--;
}

template <typename T>
typename ForwardList<T>::Iter ForwardList<T>::begin() const {
    typename ForwardList<T>::Iter iter(this->m_head);
    return iter;

}

template <typename T>
typename ForwardList<T>::Iter ForwardList<T>::end() const {
    typename ForwardList<T>::Iter iter(this->m_head);
    while (iter.next() != nullptr) {
        ++iter;
    }
    return iter;
}

template <typename T>
T& ForwardList<T>::operator[] (const int pos) const {
    if (List<T>::outOfRange(pos)) exit;
    Node* intermediateNode = this->m_head;
    int cur_pos = 0;
    while (cur_pos < pos) {
        intermediateNode = intermediateNode->m_next;
        cur_pos++;
    }
    return intermediateNode->m_data;
}

template <typename T>
void ForwardList<T>::print() const {
    Node* intermediateNode = m_head;
    while (intermediateNode != nullptr) {
        std::cout << intermediateNode->m_data << " ";
        intermediateNode = intermediateNode->m_next;
    }
    std::cout << std::endl;
}

template <typename T>
void ForwardList<T>::makeTestForwardList(int size) {
    for (int i = 1; i < size; i++) {
        push_back(i);
    }
}





