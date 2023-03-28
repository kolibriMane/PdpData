#include "fibon.h"

int getFibonacciElement(int index, std::vector<int>& vector) {
    int size = vector.size();
    if (size > index) {
        return vector[index];
    } else if (1 == size) {
        vector.push_back(1);
    } else if (0 == size) {
        vector.push_back(0);
        vector.push_back(1);
    }

    size = vector.size();
    for (int i = size - 1; i < index; ++i) {
        vector.push_back(vector[i - 1] + vector[i]);
    }

    for (int i = 0; i < index; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    return vector[index - 1];
}

int getRecurse(int index, std::vector<int>& vector) {
    int size = vector.size();
    if (size > index) {
        return vector[index];
    } else if (1 == size) {
        vector.push_back(1);
    } else if (0 == size) {
        vector.push_back(0);
        vector.push_back(1);
    }

    size = vector.size();
    if (size < index) {
        vector.push_back(vector[size - 2] + vector[size - 1]);
        getRecurse(index, vector);
    }

    return vector[index - 1];
}