#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class List {
    protected:
        int length;

    private:
        Node* head;
        void insertFirst(int);
        void insertLast(int);
        void removeFirst();
        void removeLast();

    public:
        int getLength();
        int getElement(int);
        bool insertElement(int, int);
        bool removeElement(int);
        bool empty();
        void show();
        bool isEmpty();
        List();
        List(int);
        ~List();
};

#endif
