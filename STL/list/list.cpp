#include <iostream>
#include "list.hpp"

/* Get length of list */
template<typename T>
int List<T>::getLength() {
    return length;
}

/* Get element by index */
template<typename T>
T List<T>::getElement(int index) {
    if (index <= length && index < length / 2) {
        int i = 0;
        Node<T>* current = head;
        while (i != index) {
            current = current->next;
            ++i;
        }
        return current->getValue();
    } else if (index <= length && index >= length / 2) {
        int i = length - 1;
        Node<T>* current = tail;
        while (i != index) {
            current = current->prev;
            --i;
        }
        return current->getValue();
    }
    return 0;
}

/* Insert new element at the beginning of the list */
template<typename T>
void List<T>::insertFirst(T value) {
    if (0 == length) {
        tail = head = new Node<T>(value);
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
        Node<T>* node = new Node<T>(value);
        tail->next = node;
        node->prev = tail;
        ++length;
        tail = tail->next;
    }
}

/* Insert to list new element by index */
template<typename T>
bool List<T>::insertElement(int index, T value) {
    if (index > length) {
        return false;
    }

    if (0 == index) {
        insertFirst(value);
    } else if (length == index) {
        insertLast(value);
    } else if (index > length / 2) {
        int i = length - 1;
        Node<T>* current = tail;
        while (i != index + 1) {
            current = current->next;
            ++i;
        }

        Node<T>* node = new Node<T>(value, current->next);
        current->next = node;
        node->prev = current;
        ++length;
    } else {
        int i = 0;
        Node<T>* current = head;
        while (i != index - 1) {
            current = current->prev;
            --i;
        }

        Node<T>* node = new Node<T>(value, current->next);
        current->next = node;
        ++length;
    }

    return true;
}

/* Remove element from list by index */
template<typename T>
bool List<T>::removeElement(int index) {
    if (index > length - 1) {
        return false;
    }

    if (0 == index) {
        removeFirst();
    } else if (index == length - 1) {
        removeLast();
    } else if (index > length / 2) {
        int i = length - 1;
        Node<T>* current = tail;
        while (i != index + 1) {
            current = current->prev;
            --i;
        }

        Node<T>* temp = current->prev;
        current->prev = temp->prev;
        --length;
        delete temp;
        return true;
    } else {
        int i = 0;
        Node<T>* current = head;
        while (i != index - 1) {
            current = current->next;
            ++i;
        }

        Node<T>* temp = current->next;
        current->next = temp->next;
        temp->prev = current->prev;
        --length;
        delete temp;
        return true;
    }
}

/* Remove first element of list */
template<typename T>
void List<T>::removeFirst() {
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    --length;
}

/* Remove last element of list */
template<typename T>
void List<T>::removeLast() {
    int i = 0;
    Node<T>* current = tail;

    Node<T>* tmp = current->prev;
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
        current = current->next;
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
    tail = head;
    length = 1;
}

/* Destructor */
template<typename T>
List<T>::~List() {
    empty();
}