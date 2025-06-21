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

        void insert(size_t pos, T val) {
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

        void erase(size_t pos = 0) {
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

        size_t size() const {
            return m_size;
        }

        bool isEmpty() const {
            return m_head == nullptr;
        }

        bool outOfRange(int pos) {
            if (pos > m_size-1) {
                std::cout << "Заданная позиция находится за пределами диапазона списка" << std::endl;
                return true;
            }
            return false;
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

        T& operator[] (size_t pos) const {
            if (outOfRange(pos)) exit;
            Node* intermediateNode = m_head;
            size_t cur_pos = 0;
            while (cur_pos < pos) {
                intermediateNode = intermediateNode->m_next;
                cur_pos++;
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


