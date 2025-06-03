#pragma once


template <typename T>
class List {
    private:
        struct Node {
            Node() {
                m_next = NULL;
            };
            Node(const T& data) {
                m_data = data;
                m_next = NULL;
            }
            T m_data;
            Node* m_next;
        };
        Node* m_head;
        int m_size;
        
    public:
        List() {
            m_head = NULL;
            m_size = 0;

        }
        List(const List<T> & a) {
            m_head = a.begin();
            m_size = a.size();
        }
        ~List() {
            while (m_head) {
                erase();
            }
        }
        void push_back(T val) {
            Node* node = new Node(val);
            Node* intermediateNode = m_head;
            while (intermediateNode->m_next) {
                intermediateNode = intermediateNode->m_next;
            }
            intermediateNode->m_next = node;
            m_size++;
        }

        void insert(int pos, T val) {
            Node* node = new Node(val);
            Node* intermediateNode = m_head;
            for (int i = 0; i < pos; ++i) {
                intermediateNode = intermediateNode->m_next;
            }
            node->m_next = intermediateNode->m_next.m_next;
            intermediateNode->m_next = node;
            m_size++;
        }

        void erase(int pos = 0) {
            Node* intermediateNode = m_head;
            for (int i=0; i < pos; ++i) {
                intermediateNode = intermediateNode->m_next;
            }
            intermediateNode->m_next = intermediateNode->m_next->m_next;
            delete intermediateNode;
            m_size--;
        }

        int size() const {
            return m_size;
        }

        T& begin() const {
            return m_head;
        }

        T & operator[] (int pos) {
            Node* intermediateNode = m_head;
            for (int i = 0; i < pos; ++i) {
                intermediateNode = intermediateNode->m_next;
            }
            return intermediateNode->m_data;
        }

        void print() const {
            Node* intermediateNode = m_head;
            while (intermediateNode->m_next) {
                std::cout << intermediateNode->m_data << " ";
            }
            std::cout << std::endl;
        }
};


