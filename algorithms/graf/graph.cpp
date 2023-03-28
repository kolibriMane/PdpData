#include "graph.h"

/* Constructor */
Graph::Graph() {
    a = new std::list<std::vector<char>*>();
}

/* Destructor */
Graph::~Graph() {
    delete a;
}

/* Insert node by value, and by vector */
void Graph::insertNode(char value, std::vector<char>* vector) {
    if (NULL == vector) {
        std::vector<char>* vector = new std::vector<char>();
        vector->push_back(value);
        a->push_back(vector);
        show(vector);
    } else {
        vector->insert(vector->begin(), value);
        a->push_back(vector);
        show(vector);
    }
}

/* Insert element by vector */
void Graph::insertNode(std::vector<char>* vector) {
    a->push_back(vector);
    show(vector);
}

/* Print inserted vector */
void Graph::show(std::vector<char>* a) {
    for (auto it = a->begin(); it != a->end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;
}