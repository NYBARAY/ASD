template<class T>
class Queue {
    T* _data;
    int _size; 
    int _head;
    int _count;

public:
    Queue(int size = 20); 
    Queue(const Queue& other); 
    ~Queue();  // деструктор
    Queue& operator=(const Queue& other); 

    void push(const T& val);  
    void pop();
    inline T head() const;  
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    void clear() noexcept;
    int size() const;  
};


template<class T>
Queue<T>::Queue(int size) : _size(size), _head(0), _count(0) {
    _data = new T[_size];
}

template<class T>
Queue<T>::Queue(const Queue& other) : _size(other._size), _head(other._head), _count(other._count) {
    _data = new T[_size];
    for (int i = 0; i < _count; i++) {
        int index = (_head + i) % _size;
        _data[index] = other._data[index];
    }
}

template<class T>
Queue<T>::~Queue() {
    delete[] _data;
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _head = other._head;
        _count = other._count;
        _data = new T[_size];
        for (int i = 0; i < _count; i++) {
            int index = (_head + i) % _size;
            _data[index] = other._data[index];
        }
    }
    return *this;
}

template<class T>
void Queue<T>::push(const T& val) {
    if (is_full()) {
        throw std::logic_error("Queue is full");
    }
    int tail = (_head + _count) % _size;
    _data[tail] = val;
    _count++;
}

template<class T>
void Queue<T>::pop() {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    _head = (_head + 1) % _size;
    _count--;
}

template<class T>
T Queue<T>::head() const {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    return _data[_head];
}

template<class T>
bool Queue<T>::is_empty() const noexcept {
    return _count == 0;
}

template<class T>
bool Queue<T>::is_full() const noexcept {
    return _count == _size;
}

template<class T>
void Queue<T>::clear() noexcept {
    _head = 0;
    _count = 0;
}

template<class T>
int Queue<T>::size() const {
    return _count;
}