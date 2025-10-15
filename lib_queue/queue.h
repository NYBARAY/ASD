
template<class T>
class Queue {
	T* _data;
	int _size;
	int _head;
	int _count;

public:

	Queue(int size = 20);
	/*Queue(const Queue& other);*/

	~Queue();


	void push(const T& val);
	void pop();
	inline T head() const;
	inline bool is_empty() const noexcept;
	inline bool is_full() const noexcept;
	void clear();

	int size() const;


};

template<class T>
Queue<T>::Queue(int size) : _size(size), _head(0), _count(0) {
	_data = new T[_size];
}

template<class T>
Queue<T>::~Queue() {
	delete[] _data;
}

template<class T>
void Queue<T>::push(const T& val) {
	if (is_full()) {
		throw std::logic_error("Queue is full");
	}
	_count++;
	_data((_head + _count - 1) % size) = val;
}

template<class T>
void Queue<T>::pop() {
	if (is_empty) {
		throw std::logic_error("Queue is empty");
	}
	_count--;
	_head = (++_head) % _size;
}

template<class T>
T Queue<T>::head() const {
	return _data[_head];
}


template<class T>
void Queue<T>::clear() noexcept {
	_head = 0;
	_count = 0;
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
	return count;
}
