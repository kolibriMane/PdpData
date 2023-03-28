#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

class Queue : protected List {
    public:
        int getLength();
        void push(int);
        void pop();
        bool cleanQueue();
        void showQueue();
        bool isQueueEmpty();
        Queue();
        Queue(int);
        ~Queue();
};

#endif