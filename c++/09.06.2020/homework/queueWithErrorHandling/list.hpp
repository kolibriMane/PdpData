#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

template<typename T>
class List {
    protected:
        int length;

    private:
        Node<T>* head;
        void insertFirst(T);
        void insertLast(T);
        void removeFirst();
        void removeLast();

    public:
        int getLength();
        T getElement(int);
        bool insertElement(int, T);
        bool removeElement(int);
        bool empty();
        void show();
        bool isEmpty();
        List();
        List(T);
        ~List();
};

#endif