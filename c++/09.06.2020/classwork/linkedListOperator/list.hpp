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
        bool insertElement(int, int);
        bool removeElement(int);
        Node* getHead();
        bool empty();
        void show();
        bool isEmpty();
        friend std::ostream& operator<<(std::ostream&, List&);
        List();
        List(int);
        ~List();
};

#endif