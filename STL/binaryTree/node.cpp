#include <iostream>
#include "node.h"

/* Constructor */
template<typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}

/* Destructor */
template<typename T>
Node<T>::~Node() {
    value = 0;
    this->left = NULL;
    this->right = NULL;
}

/* Copy constructor */
template<typename T>
Node<T>::Node(Node* &node) {
    this->value = node->value;
    this->left = node->left;
    this->right = node->right;
}

/* = operator overloading */
template<typename T>
Node<T>* Node<T>::operator=(Node<T>* other) {
    this->value = other->value;
    this->left = other->left;
    this->right = other->right;
    return this;
}