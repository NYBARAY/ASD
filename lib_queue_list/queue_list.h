#include "list.h"

template <class T>
class QueueList {
	List<T> _list;

public:
    QueueList() {}
    QueueList(const QueueList& other) : _list(other._list) {}
    ~QueueList() {}
    QueueList& operator=(const QueueList& other);

    void push(const T& val);
    void pop();
    inline T head() const;
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    void clear() noexcept;
    int size() const;
};


template <class T>
QueueList<T>& QueueList<T>::operator=(const QueueList& other) {
    if (this != &other) {
        _list = other._list;
    }
    return* this;
}

template <class T>
void QueueList<T>::push(const T& val) {
    _list.push_back(val);
}


template <class T>
void QueueList<T>::pop() {
    _list.pop_front();
}


template <class T>
T QueueList<T>::head() const {
    return _list.front();
}


template <class T>
bool QueueList<T>::is_empty() const noexcept {
    return _list.is_empty();
}


template <class T>
bool QueueList<T>::is_full() const noexcept {
    return false;
}


template <class T>
void QueueList<T>::clear() noexcept {
    _list.clear();
}


template <class T>
int QueueList<T>::size() const {
    return _list.size();
}