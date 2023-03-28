#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>

class Graph {
    private:
        std::list<std::vector<char>*>* a;
    public:
        Graph();
        ~Graph();
        void insertNode(std::vector<char>*);
        void insertNode(char, std::vector<char>* vector = NULL);
        void show(std::vector<char>*);
};

#endif