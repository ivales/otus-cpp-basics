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
        List() {
            m_head = nullptr;
            m_size = 0;

        }
        List(const List<T>& a) {
            m_head = a.begin();
            m_size = a.size();
        }
        ~List() {
            while (m_head != nullptr) {
                erase();
            }
        }
        void push_back(T val) {
            Node* node = new Node(val);
            if (isEmpty()) {
                m_head = node;
            }
            else {
                Node* lastNode = end();
                lastNode->m_next = node;
            }
            m_size++;
        }

        void insert(int pos, T val) {
            Node* node = new Node(val);
            Node* intermediateNode = m_head;
            for (int i = 0; i < pos; ++i) {
                intermediateNode = intermediateNode->m_next;
            }
            node->m_next = intermediateNode->m_next->m_next;
            intermediateNode->m_next = node;
            m_size++;
        }

        void erase(int pos = 0) {
            if (!isEmpty()) {
                Node* intermediateNode = m_head;
                Node* deleteNode;
                for (int i=0; i < pos; i++) {
                    intermediateNode = intermediateNode->m_next;
                }
                if (intermediateNode->m_next) {
                    deleteNode = intermediateNode;
                    intermediateNode = intermediateNode->m_next->m_next;
                }
                delete deleteNode;
                m_size--;
            }
        }

        int size() const {
            return m_size;
        }

        bool isEmpty() const {
            return m_head == nullptr;
        }

        Node* begin() const {
            return m_head;
        }

        Node* end() const {
            Node* intermediateNode = m_head;
            while (intermediateNode->m_next != nullptr) {
                intermediateNode = intermediateNode->m_next;
            }
            return intermediateNode;
        }

        Node* operator[] (int pos) {
            Node* intermediateNode = m_head;
            for (int i = 0; i < pos; ++i) {
                intermediateNode = intermediateNode->m_next;
            }
            return intermediateNode->m_data;
        }

        void print() const {
            Node* intermediateNode = m_head;
            while (intermediateNode != nullptr) {
                std::cout << intermediateNode->m_data << " ";
                intermediateNode = intermediateNode->m_next;
            }
            std::cout << std::endl;
        }
};


