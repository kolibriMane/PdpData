#include <iostream>
#include "node.h"

/* get the value of node */
template<typename T>
T Node<T>::getValue() {
    return value;
}

/* Get the next node of the current */
template<typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

/* Change the value of node */
template<typename T>
void Node<T>::setValue(T value) {
    this->value = value;
}

/* Change the next node of the current */
template<typename T>
void Node<T>::setNext(Node* next) {
    this->next = next;
}

/* Show pretty the node */
template<typename T>
void Node<T>::show() {
    std::cout << value << " ";
}

/* Constructor */
template<typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = NULL;
}

/* Constructor */
template<typename T>
Node<T>::Node(T value, Node* next) {
    this->value = value;
    this->next = next;
}

/* Destructor */
template<typename T>
Node<T>::~Node() {
    value = 0;
    next = NULL;
}

/* Copy constructor */
template<typename T>
Node<T>::Node(Node* &node) {
    this->value = node->value;
    this->next = node->next;
}