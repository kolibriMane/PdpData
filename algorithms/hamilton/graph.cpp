#include "graph.h"

/* Constructor */
Graph::Graph(int size) {
    a = new int*[size];
    for (int i = 0; i < size; ++i) {
        a[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = 0;
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

/* If node exists, then it is not valid */
bool Graph::isValid(int n, int* path, int pos) {
    int side = this->getWeight(pos - 1, n);
    /* If side doesn't exist */
    if (0 == side) {
        return false;
    }

    /* Is node exists in path array */
    for (int i = 0; i < pos; ++i) {
        if (n == path[i]) {
            return false;
        }
    }
    return true;
}

/* Hamiltonian cycle */
bool Graph::getHamiltonianCycle(int* path, int pos) {
    int n = this->size;
    /* If all nodes are exist */
    if (n == pos) {
        int side = this->getWeight(pos - 1, path[0]);
        if (side) {
            return true;
        }
        return false;
    }

    /* If node is valid to add */
    for (int i = 1; i < n; ++i) {
        if (isValid(i, path, pos)) {
            path[pos] = i;
            if (getHamiltonianCycle(path, pos + 1)) {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}

/* Get and print hamiltonian cycle */
bool Graph::hamiltonianCycle() {
    /* Create array for path, and initialize with -1 value */
    int n = this->size;
    int* path = new int[n];
    for (int i = 0; i < n; ++i) {
        path[i] = -1;
    }

    /* Get Hamiltonian cycle if it exists */
    path[0] = 0;
    if (!getHamiltonianCycle(path, 1)) {
        std::cout << "Hamiltonian cycle doesn't exist !!!" << std::endl;
        return false;
    }

    /* Show hamiltonian cycle */
    showPath(path, n);
    return true;
}

/* print cycle path */
void Graph::showPath(int* path, int size) {
    std::cout << "Hamiltonian cycle is: ";
    for (int i = 0; i < size; ++i) {
        std::cout << path[i] << " ";
    }
    std::cout << path[0] << std::endl;
}