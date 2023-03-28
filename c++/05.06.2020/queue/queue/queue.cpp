#include <iostream>
#include "queue.hpp"

/* Insert new element at the end of the queue */
int Queue::getLength() {
    return length;
}

/* Insert new element at the end of the queue */
void Queue::push(int value) {
    insertElement(length, value);
}

/* Remove first element of queue */
void Queue::pop() {
    removeElement(0);
}

/* Clear the queue */
bool Queue::cleanQueue() {
    return empty();
}

/* Print queue pretty */
void Queue::showQueue() {
    show();
}

/* Check is the queue empty */
bool Queue::isQueueEmpty() {
    return isEmpty();
}

/* Default constructor */
Queue::Queue() {
    length = 0;
}

/* Constructor */
Queue::Queue(int value) {
    length = 1;
}

/* Destructor */
Queue::~Queue() {
    cleanQueue();
}