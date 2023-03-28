#include <iostream>
#include "node.hpp"

/* get the value of node */
int Node::getValue() {
    return value;
}

/* Get the next node of the current */
Node* Node::getNext() {
    return next;
}

/* Change the value of node */
void Node::setValue(int value) {
    this->value = value;
}

/* Change the next node of the current */
void Node::setNext(Node* next) {
    this->next = next;
}

/* Show pretty the node */
void Node::show() {
    std::cout << value << " ";
}

/* Constructor */
Node::Node(int value) {
    this->value = value;
    this->next = NULL;
}

/* Constructor */
Node::Node(int value, Node* next) {
    this->value = value;
    this->next = next;
}

/* Destructor */
Node::~Node() {
    value = 0;
    next = NULL;
}

/* Copy constructor */
Node::Node(Node* &node) {
    this->value = node->value;
    this->next = node->next;
}