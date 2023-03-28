#include <iostream>

#include "list.hpp"
#include "myException.hpp"

/* Get length of list */
template<typename T>
int List<T>::getLength() {
    return length;
}

/* Get element by index */
template<typename T>
T List<T>::getElement(int index) {
    if (index < length) {
        int i = 0;
        Node<T>* current = head;
        while (i != index) {
            current = current->getNext();
            ++i;
        }
        return current->getValue();
    } else {
        throw MyException("Can't get element, Index is great then length");
    }
}

/* insert new element at the beginning of the list */
template<typename T>
void List<T>::insertFirst(T value) {
    if (0 == length) {
        head = new Node<T>(value);
    } else {
        Node<T>* temp = head;
        head = new Node<T>(value, temp);
    }
    ++length;
}

/* Insert new element at the end of the list */
template<typename T>
void List<T>::insertLast(T value) {
    if (0 == length) {
        insertFirst(value);
    } else {
        Node<T>* current = head;
        while (NULL != current->getNext()) {
            current = current->getNext();
        }
        Node<T>* node = new Node<T>(value);
        current->setNext(node);
        ++length;
    }
}

/* Insert to list new element by index */
template<typename T>
bool List<T>::insertElement(int index, T value) {
    if (index > length) {
        throw MyException("Can't add element, Index is great then length");
    }

    if (0 == index) {
        insertFirst(value);
    } else if (length == index) {
        insertLast(value);
    } else {
        int i = 0;
        Node<T>* current = head;
        while (i != index - 1) {
            current = current->getNext();
            ++i;
        }

        Node<T>* node = new Node<T>(value, current->getNext());
        current->setNext(node);
        ++length;
    }

    return true;
}

/* Remove element from list by index */
template<typename T>
bool List<T>::removeElement(int index) {
    if (index > length - 1) {
        throw MyException("Cant Remove element, Index is great then length");
        return false;
    }

    if (0 == index) {
        removeFirst();
    } else if (index == length - 1) {
        removeLast();
    } else {
        int i = 0;
        Node<T>* current = head;
        while (i != index - 1) {
            current = current->getNext();
            ++i;
        }

        Node<T>* temp = current->getNext();
        current->setNext(temp->getNext());
        --length;
        delete temp;
        return true;
    }
}

/* Remove first element of list */
template<typename T>
void List<T>::removeFirst() {
    Node<T>* tmp = head;
    head = head->getNext();
    delete tmp;
    --length;
}

/* Remove last element of list */
template<typename T>
void List<T>::removeLast() {
    int i = 0;
    Node<T>* current = head;
    while (i != length - 2) {
        current = current->getNext();
        ++i;
    }

    Node<T>* tmp = current->getNext();
    current->setNext(NULL);
    delete tmp;
    --length;
}

/* Clear the list */
template<typename T>
bool List<T>::empty() {
    while (!isEmpty()) {
        removeFirst();
    }

    return true;
}

/* Print list pretty */
template<typename T>
void List<T>::show() {
    Node<T>* current = head;
    for (int i = 0; i < length; ++i) {
        std::cout << current->getValue() << " -> ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

/* Check is the list empty */
template<typename T>
bool List<T>::isEmpty() {
    return (0 == length) ? true : false;
}

/* Default constructor */
template<typename T>
List<T>::List() {
    length = 0;
}

/* Constructor */
template<typename T>
List<T>::List(T head) {
    this->head->setValue(head);
    this->head->setNext(NULL);
    length = 1;
}

/* Destructor */
template<typename T>
List<T>::~List() {
    empty();
}