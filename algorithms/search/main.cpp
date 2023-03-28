#include "func.h"

int main(int argc, char** argv) {
    /* If arguments are invalid, end the code with error code */
    if (isInvalidArgs(argc, argv)) {
        return -1;
    }

    /* Array initialization */
    std::cout << "Array size: ";
    const int size = getInteger(true);
    int* a = new int[size];
    a = initArray(a, size);
    std::cout << std::endl;

    /* Print array */
    std::cout << "Array--------> ";
    showArray(a, size);

    /* Sort and print array */
    mergeSort(a, size);
    std::cout << "Sorted array-> ";
    showArray(a, size);

    /* Get value to find index array */
    std::cout << "Integer value to find: ";
    const int value = getInteger(false);
    std::cout << std::endl;

    /* Find element in array, with way you want */
    std::cout << "Index of element: ";
    if (strcmp(argv[1], "binary") == 0) {
        std::cout << binarySearch(a, 0, size, value) << std::endl;
    } else if (strcmp(argv[1], "jump") == 0) {
        std::cout << jumpSearch(a, 0, size, value) << std::endl;
    } else if (strcmp(argv[1], "linear") == 0) {
        std::cout << linearSearch(a, 0, size, value) << std::endl;
    } else if (strcmp(argv[1], "inter") == 0) {
        std::cout << interpolationSearch(a, size, value) << std::endl;
    } else if (strcmp(argv[1], "expon") == 0) {
        std::cout << exponentialSearch(a, size, value) << std::endl;
    } else if (strcmp(argv[1], "tern") == 0) {
        std::cout << ternarySearch(a, 0, size + 1, value) << std::endl;
    }

    return 0;
}