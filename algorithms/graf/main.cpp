#include "graph.h"

int main() {
    /* Create clear graph */
    Graph* graph = new Graph();

    /* Create vector to insert element and sides */
    std::vector<char>* vector = new std::vector<char>();
    /* Insert head */
    vector->push_back('A');
    /* Insert sides */
    vector->push_back('B');
    vector->push_back('C');
    vector->push_back('D');
    /* Insert node to Graph */
    graph->insertNode(vector);

    /* Insert heads */
    graph->insertNode('B');
    graph->insertNode('C');

    /* Use created vector to add new node */
    vector->clear();
    vector->push_back('D');
    vector->push_back('E');
    vector->push_back('H');
    graph->insertNode(vector);

    /* Insert head */
    graph->insertNode('H');

    /* Use created vector to add new node */
    vector->clear();
    vector->push_back('E');
    vector->push_back('H');
    vector->push_back('D');
    graph->insertNode(vector);

    return 0;
}