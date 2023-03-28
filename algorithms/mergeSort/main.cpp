#include <iostream>
#include "mergeSort.h"

int main() {
    int size = getInteger(true);
    int* a = new int[size];
    a = initArray(a, size);
    std::cout << "******************************" << std::endl;
    std::cout << "Array--------> ";
    showArray(a, size);

    mergeSort(a, size);
    std::cout << "Sorted array-> ";
    showArray(a, size);

    return 0;
}