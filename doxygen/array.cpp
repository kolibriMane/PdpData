#include "array.h"

/* Print array */
bool Array::showArray(int* a, int n) {
    if (n < 0) {
        throw "Invalid size of array!";
    }
    if (n == 0) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
    return true;
}

/* Print array old way*/
void Array::showArrayOld(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}