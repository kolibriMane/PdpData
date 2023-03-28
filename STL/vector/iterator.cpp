#include <iostream>
#include "iterator.h"

template <typename T>
Iterator<T>::Iterator() {
    ptr = new T();
}

template <typename T>
Iterator<T>::Iterator(T* ptr) {
    this->ptr = new T(*ptr);
}

template <typename T>
Iterator<T>::~Iterator() {
    delete ptr;
}

template <typename T>
Iterator<T>& Iterator<T>::operator+(int count) {
    ptr = (ptr + count);
    return ptr;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-(int count) {
    ptr += count;
    return ptr;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Iterator<T> Iterator<T>::operator++() {
    Iterator<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator<T> temp = *this;
    --(*this);
    return temp;
}
template <typename T>
Iterator<T> Iterator<T>::operator--() {
    Iterator<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
T& Iterator<T>::operator*() {
    return *(ptr);
}

template <typename T>
Iterator<T>*& Iterator<T>::operator=(Iterator* it) {
    return it;
}

template <typename T>
Iterator<T>* Iterator<T>::operator=(T* ptr) {
    this->ptr = ptr;
    return this;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& b) const {
    if (this == b) {
        return true;
    }
    return false;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& b) const {
    if (this == &b) {
        return false;
    }
    return true;
}