#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph {
    private:
        int** a;
        int size;
        void showPath(int*, int);
        bool getHamiltonianCycle(int*, int);
        bool isValid(int, int*, int);

    public:
        Graph(int);
        ~Graph();
        void setSide(int, int, int);
        int getWeight(int, int);
        void show();
        std::vector<int>* getWay(int, int);
        int getSize();
        bool hamiltonianCycle();
};

#endif