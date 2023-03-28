#include <iostream>
#include "list.hpp"

/* Get length of list */
int List::getLength() {
    return length;
}

/* Get element by index */
int List::getElement(int index) {
    if (index <= length) {
        int i = 0;
        Node* current = head;
        while (i != index) {
            current = current->getNext();
            ++i;
        }
        return current->getValue();
    }
    return 0;
}

/* insert new element at the beginning of the list */
void List::insertFirst(int value) {
    if (0 == length) {
        head = new Node(value);
    } else {
        Node* temp = head;
        head = new Node(value, temp);
    }
    ++length;
}

/* Insert new element at the end of the list */
void List::insertLast(int value) {
    if (0 == length) {
        insertFirst(value);
    } else {
        Node* current = head;
        while (NULL != current->getNext()) {
            current = current->getNext();
        }
        Node* node = new Node(value);
        current->setNext(node);
        ++length;
    }
}

/* Insert to list new element by index */
bool List::insertElement(int index, int value) {
    if (index > length) {
        return false;
    }

    if (0 == index) {
        insertFirst(value);
    } else if (length == index) {
        insertLast(value);
    } else {
        int i = 0;
        Node* current = head;
        while (i != index - 1) {
            current = current->getNext();
            ++i;
        }

        Node* node = new Node(value, current->getNext());
        current->setNext(node);
        ++length;
    }

    return true;
}

/* Remove element from list by index */
bool List::removeElement(int index) {
    if (index > length - 1) {
        return false;
    }

    if (0 == index) {
        removeFirst();
    } else if (index == length - 1) {
        removeLast();
    } else {
        int i = 0;
        Node* current = head;
        while (i != index - 1) {
            current = current->getNext();
            ++i;
        }

        Node* temp = current->getNext();
        current->setNext(temp->getNext());
        --length;
        delete temp;
        return true;
    }
}

/* Remove first element of list */
void List::removeFirst() {
    Node* tmp = head;
    head = head->getNext();
    delete tmp;
    --length;
}

/* Remove last element of list */
void List::removeLast() {
    int i = 0;
    Node* current = head;
    while (i != length - 2) {
        current = current->getNext();
        ++i;
    }

    Node* tmp = current->getNext();
    current->setNext(NULL);
    delete tmp;
    --length;
}

/* Clear the list */
bool List::empty() {
    while (!isEmpty()) {
        removeFirst();
    }

    return true;
}

/* Print list pretty */
void List::show() {
    Node* current = head;
    for (int i = 0; i < length; ++i) {
        std::cout << current->getValue() << " -> ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

/* Check is the list empty */
bool List::isEmpty() {
    return (0 == length) ? true : false;
}

/* Default onstructor */
List::List() {
    length = 0;
}

/* Constructor */
List::List(int head) {
    this->head->setValue(head);
    this->head->setNext(NULL);
    length = 1;
}

/* Destructor */
List::~List() {
    empty();
}