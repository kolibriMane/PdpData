#include "graph.h"

const int INF = 10000;

/* Constructor */
Graph::Graph(int size) {
    a = new int*[size];
    for (int i = 0; i < size; ++i) {
        a[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                a[i][j] = 0;
            } else {
                a[i][j] = INF;
            }
        }
    }

    this->size = size;
}

/* Destructor */
Graph::~Graph() {
    for (int i = 0; i < size; ++i) {
        delete [] a[i];
    }

    delete [] a;
}

/* Add side to the node */
void Graph::setSide(int n, int m, int weight) {
    if (n < size && m < size) {
        a[n][m] = weight;
    }
}

/* Get side value */
int Graph::getWeight(int n, int m) {
    if (n < size && m < size) {
        return a[n][m];
    }

    return -1;
}

/* Print graph pretty */
void Graph::show() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* Get node count */
int Graph::getSize() {
    return size;
}

void Graph::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int Graph::min(std::vector<int> vector) {
    int size = vector.size();
    int min = vector[0];
    for (int i = 1; i < size; ++i) {
        if (vector[i] < min) {
            swap(vector[i], min);
        }
    }

    return min;
}

int* Graph::bellmanFord(int start) {
    int nodeCount = getSize();
    int* way = new int[nodeCount];
    std::vector<int> vector;

    for (int i = 0; i < nodeCount; ++i) {
        way[i] = INF;
    }
    way[start] = 0;

    for (int k = 1; k < nodeCount; ++k) {
        for (int i = 0; i < nodeCount; ++i) {
            for (int j = 0; j < nodeCount; ++j) {
                vector.push_back(way[j] + getWeight(j, i));
            }
            way[i] = min(vector);
            vector.clear();
        }
    }

    return way;
}