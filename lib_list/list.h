
template <class T>
class List {
private:
    template <class T>
    struct Node {
        T value;
        Node<T>* next;
        Node(T value_, Node<T>* next_ = nullptr) : value(value_), next(next_) {}
    };

    Node<T>* _head;
    Node<T>* _tail;
    int _count;

public:
    List() : _head(nullptr), _tail(nullptr), _count(0) {}

    List(const List& other) : _head(nullptr), _tail(nullptr), _count(0) {
        Node<T>* current = other._head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other._head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }

    ~List() {
        clear();
    }

    void push_front(const T& val) noexcept {
        Node<T>* newNode = new Node<T>(val, _head);
        _head = newNode;
        if (_tail == nullptr) {
            _tail = _head;
        }
        _count++;
    }

   
    void push_back(const T& val) noexcept {
        Node<T>* newNode = new Node<T>(val);
        if (_tail == nullptr) {
            _head = _tail = newNode;
        }
        else {
            _tail->next = newNode;
            _tail = newNode;
        }
        _count++;
    }

    
    void insert(int pos, const T& val) {
        if (pos < 0 || pos > _count) {
            throw std::out_of_range("Position out of range");
        }

        if (pos == 0) {
            push_front(val);
        }
        else if (pos == _count) {
            push_back(val);
        }
        else {
            Node<T>* current = _head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node<T>* newNode = new Node<T>(val, current->next);
            current->next = newNode;
            _count++;
        }
    }

    
    void insert(Node<T>* node, const T& val) {
        if (node == nullptr) {
            throw std::invalid_argument("Node cannot be null");
        }

        Node<T>* newNode = new Node<T>(val, node->next);
        node->next = newNode;

        if (node == _tail) {
            _tail = newNode;
        }
        _count++;
    }

    void pop_front() {
        if (is_empty()) {
            throw std::runtime_error("Cannot pop from empty list");
        }

        Node<T>* temp = _head;
        _head = _head->next;
        delete temp;
        _count--;

        if (_head == nullptr) {
            _tail = nullptr;
        }
    }

    
    void pop_back() {
        if (is_empty()) {
            throw std::runtime_error("Cannot pop from empty list");
        }

        if (_head == _tail) {
            delete _head;
            _head = _tail = nullptr;
        }
        else {
            Node<T>* current = _head;
            while (current->next != _tail) {
                current = current->next;
            }
            delete _tail;
            _tail = current;
            _tail->next = nullptr;
        }
        _count--;
    }

    
    void erase(int pos) {
        if (pos < 0 || pos >= _count) {
            throw std::out_of_range("Position out of range");
        }

        if (pos == 0) {
            pop_front();
        }
        else {
            Node<T>* current = _head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node<T>* toDelete = current->next;
            current->next = toDelete->next;

            if (toDelete == _tail) {
                _tail = current;
            }

            delete toDelete;
            _count--;
        }
    }

    
    void erase(Node<T>* node) {
        if (node == nullptr || is_empty()) {
            throw std::invalid_argument("Node cannot be null or list is empty");
        }

        if (node == _head) {
            pop_front();
            return;
        }

        
        Node<T>* prev = _head;
        while (prev != nullptr && prev->next != node) {
            prev = prev->next;
        }

        if (prev == nullptr) {
            throw std::invalid_argument("Node not found in the list");
        }

        prev->next = node->next;

        if (node == _tail) {
            _tail = prev;
        }

        delete node;
        _count--;
    }

    
    Node<T>* find(const T& value) {
        Node<T>* current = _head;
        while (current != nullptr) {
            if (current->value == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    
    bool is_empty() const {
        return _count == 0;
    }

    
    int size() const {
        return _count;
    }

    
   

   

    
    void clear() {
        while (!is_empty()) {
            pop_front();
        }
    }

    

    
    Node<T>* head() const {
        return _head;
    }


    Node<T>* end() const {
        return nullptr;
    }

    Iterator begin() { return Iterator(_head); }
    Iterator end() { return Iterator(nullptr); }

    class Iterator {
        Node<T>* current;
    public:
        Iterator() : current(nullptr) {};
        Iterator(Node<T>* pos) : current(pos) {};
        Iterator(const Iterator& other) : current(other.current) {};

        Iterator& operator=(const Iterator& other) {
            if (this != &other) {
                current = other.current;
            }
            return *this;
        }

        T& operator*() {
            if (current == nullptr) {
                throw std::logic_erorr("currernt = 0");
            }
            return current->value;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        Iterator operator++(int) {
            Iterator tmp(*this);
            if (current != nullptr) {
                current = current->next;
            }
            return tmp;
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }
    };
};