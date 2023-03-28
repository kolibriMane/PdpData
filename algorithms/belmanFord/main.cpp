#include "graph.h"

int main() {
    int nodeCount = 4;
    Graph* graph = new Graph(nodeCount);

    graph->setSide(0, 1, 1);
    graph->setSide(1, 2, 1);
    graph->setSide(2, 3, 1);
    graph->setSide(3, 0, 1);

    int* way = graph->bellmanFord(0);
    for (int i = 0; i < nodeCount; ++i) {
        std::cout << i << " : " << way[i] << std::endl;
    }

    /* Show graph, get cycle path and free used memory */
    graph->show();
    delete graph;

    return 0;
}