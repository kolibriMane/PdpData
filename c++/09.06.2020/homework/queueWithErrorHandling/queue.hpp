#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

template<typename T>
class Queue : protected List<T> {
    public:
        int getLength();
        void push(T);
        void pop();
        bool cleanQueue();
        void showQueue();
        bool isQueueEmpty();
        T getElementByIndex(int);
        Queue();
        Queue(T);
        ~Queue();
};

#endif