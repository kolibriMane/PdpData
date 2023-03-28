#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class List {
    private:
        int length;
        Node* head;
        void insertFirst(int);
        void insertLast(int);
        void removeFirst();
        void removeLast();

    public:
        int getLength();
        int getElement(int);
        bool syncInsertElement(int, int);
        bool asyncInsertElement(int, int);
        bool syncRemoveElement(int);
        bool asyncRemoveElement(int);
        bool empty();
        void show();
        bool isEmpty();
        List();
        List(int);
        ~List();
};

#endif
