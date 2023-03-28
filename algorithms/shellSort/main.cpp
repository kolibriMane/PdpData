#include <iostream>
#include "sort.h"

int main() {
    int size = getSize();
    int* a = new int[size];
    a = initArray(a, size);
    std::cout << "******************************" << std::endl;
    std::cout << "Array--------> ";
    showArray(a, size);

    a = shellSort(a, size);
    std::cout << "Sorted array-> ";
    showArray(a, size);

    return 0;
}