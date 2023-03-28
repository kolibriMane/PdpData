#include "stack.h"
#include "node.h"
#include <iostream>

/* Constructor */
template <typename T>
Stack<T>::Stack(int count, T value) {
    last = NULL;
    if (0 < count) {
        for (int i = 0; i < count; ++i) {
            Node<T>* node = new Node<T>(value);
            node->setNext(last);
        }
        this->count = count;
    }
}

/* Copy constructor */
template <typename T>
Stack<T>::Stack(const Stack<T>& cont) {
    std::cout << "Copy constructor" << std::endl;
    Node<T>* current = cont.getLast();
    Stack<T> stack;
    count = 0;
    while (current != NULL) {
        stack.push(current->getValue());
        current = current->getNext();
        ++count;
    }

    current = stack.getLast();
    count = 0;
    while (current != NULL) {
        this->push(current->getValue());
        current = current->getNext();
        ++count;
    }
}

/* Destructor */
template <typename T>
Stack<T>::~Stack() {
    while (last != NULL) {
        pop();
    }
}

/* Delete last element */
template <typename T>
void Stack<T>::pop() {
    Node<T>* temp = last;
    last = last->getNext();
    delete temp;
    --count;
}

/* Add element from end */
template <typename T>
void Stack<T>::push(const T value) {
    Node<T>* node = new Node<T>(value);
    node->setNext(last);
    last = node;
    ++count;
}

/*  */
template <typename T>
int Stack<T>::size() const {
    return count;
}

template <typename T>
bool Stack<T>::empty() const {
    if (0 == count) {
        return true;
    }
    return false;
}

template <typename T>
T Stack<T>::top() {
    return last->getValue();
}

template <typename T>
Node<T>* Stack<T>::getLast() {
    return last;
}