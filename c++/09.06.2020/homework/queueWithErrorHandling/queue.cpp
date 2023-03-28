#include <iostream>
#include "queue.hpp"
#include "myException.hpp"

/* Insert new element at the end of the queue */
template<typename T>
int Queue<T>::getLength() {
    return this->length;
}

/* Insert new element at the end of the queue */
template<typename T>
void Queue<T>::push(T value) {
    this->insertElement(this->length, value);
}

/* Remove first element of queue */
template<typename T>
void Queue<T>::pop() {
    this->removeElement(0);
}

/* Clear the queue */
template<typename T>
bool Queue<T>::cleanQueue() {
    return this->empty();
}

/* Print queue pretty */
template<typename T>
void Queue<T>::showQueue() {
    this->show();
}

/* Check is the queue empty */
template<typename T>
bool Queue<T>::isQueueEmpty() {
    return this->isEmpty();
}

/* Default constructor */
template<typename T>
Queue<T>::Queue() {
    this->length = 0;
}

/* Constructor */
template<typename T>
Queue<T>::Queue(T value) {
    this->length = 1;
}

/* Get element by index from queue */
template<typename T>
T Queue<T>::getElementByIndex(int index) {
    if (index >= this->length) {
        throw MyException("Can't get element, Index is great then length!");
    }
    return this->getElement(index);
}


/* Destructor */
template<typename T>
Queue<T>::~Queue() {
    cleanQueue();
}