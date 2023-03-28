#include "func.h"

int main() {
    int size = 0;
    std::cout << "Enter array size: ";
    std::cin >> size;

    int* array = new int[size];
    std::cout << "**** Initialize array ****" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "array[" << i + 1 << "]: ";
        std::cin >> array[i];
    }

    std::cout << "Array : ";
    showArray(array, size);
    mergeSort(array, size);
    std::cout << "Sorted: ";
    showArray(array, size);

    return 0;
}