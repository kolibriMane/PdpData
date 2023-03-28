#include <iostream>
#include "sort.h"

/* To set a in b, and opposite */
void swap(int& a, int& b) {
    a += b;
    b = a - b;
    a = a - b;
}

/* Get integer number, fixed bad cases */
int getSize() {
    int number = 0;
    std::cout << "Enter size: ";
    std::cin >> number;

    while (std::cin.fail() || number < 1) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cerr << "Size must be great then 0: ";
        std::cout << "Enter Size: ";
        std::cin >> number;
    }

    return number;
}

/* Create and initialize array with random numbers */
int* initArray(int* a, int n) {
    a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
    }
    return a;
}

/* Print array elements */
void showArray(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}

/* shell sort for array elements */
int* shellSort(int* array, int size) {
    int n = size;
    while (n / 2 > 0) {
        n /= 2;
        for (int i = n; i < size; ++i) {
            int j = i;
            while (j >= n && array[j] < array[j - n]) {
                swap(array[j], array[j - n]);
                j -= n;
            }
        }
    }

    return array;
}