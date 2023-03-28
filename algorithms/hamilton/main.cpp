#include "graph.h"

int main() {
    /* Hamiltonian cyclic graph */
    int nodeCount = 4;
    Graph* graph = new Graph(nodeCount);

    graph->setSide(0, 1, 1);
    graph->setSide(1, 2, 1);
    graph->setSide(2, 3, 1);
    graph->setSide(3, 0, 1);

    /* Show graph, get cycle path and free used memory */
    graph->show();
    graph->hamiltonianCycle();
    delete graph;


    /* Not Hamiltonian cyclic graph */
    nodeCount = 5;
    graph = new Graph(nodeCount);

    graph->setSide(0, 1, 1);
    graph->setSide(0, 2, 2);
    graph->setSide(0, 3, 1);
    graph->setSide(1, 2, 6);
    graph->setSide(2, 1, 6);
    graph->setSide(2, 4, 8);
    graph->setSide(4, 3, 3);
    graph->setSide(3, 1, 5);

    /* Show graph, get cycle path and free used memory */
    graph->show();
    graph->hamiltonianCycle();
    delete graph;

    return 0;
}