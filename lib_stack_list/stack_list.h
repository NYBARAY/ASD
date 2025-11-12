#include "list.h"

template <class T>
class StackList {
	List<T> _list;

public:
	StackList() {}

	StackList(const StackList& other) : _list(other._list) {}

	~StackList() {}

	StackList& operator=(const StackList& other);

	void push(const T& val);
	void pop();
	inline T top() const;
	inline bool is_empty() const noexcept;
	inline bool is_full() const noexcept;

	void clear() noexcept;

	int size() const;
};

template <class T>
StackList<T>& StackList<T>::operator=(const StackList& other) {
	if (this != &other) {
		_list = other._list;
	}
	return *this;
}


template <class T>
void StackList<T>::push(const T& val) {
	_list.push_back(val);
}


template <class T>
void StackList<T>::pop() {
	_list.pop_back();
}


template <class T>
T StackList<T>::top() const {
	return _list.back();
}


template <class T>
bool StackList<T>::is_empty() const noexcept {
	return _list.is_empty();
}


template <class T>
bool StackList<T>::is_full() const noexcept {
	return _list.is_full();
}


template <class T>
void StackList<T>::clear() noexcept {
	return _list.clear();
}


template <class T>
int StackList<T>::size() const {
	return _list.size();
}