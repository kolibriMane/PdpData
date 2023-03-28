#ifndef STACK_H
#define STACK_H

#include "node.h"

template <typename T>
class Stack {
    private:
        int count;
        Node<T>* last;
    public:
        Stack(int size = 0, T value = 0);
        Stack(const Stack<T>&);
        Node<T>* getLast();
        ~Stack();
        void pop();
        void push(const T);
        int size() const;
        bool empty() const;
        T top();
};

#endif