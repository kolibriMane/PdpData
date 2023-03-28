#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph {
    private:
        int** a;
        int size;
        void swap(int&, int&);
        int min(std::vector<int>);

    public:
        Graph(int);
        ~Graph();
        void setSide(int, int, int);
        int getWeight(int, int);
        void show();
        int getSize();
        int* bellmanFord(int);
};

#endif