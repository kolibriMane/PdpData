#include <iostream>
#include "sort.h"

/* To set a in b, and opposite */
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
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

/* Quick sort for array elements, pivot is middle element */
int* quickSort(int* a, int left, int right) {
    /* Index in left side */
    int i = left;
    /* Index in right side */
    int j = right;
    /* Pivot last element of array */
    int pivot = a[right];

    /* while current element in left side less then pivot, send cursor right */
    while (i <= j && a[i] < pivot) {
        ++i;
    }

    /* While current element from right is bigger, send cursor left */
    while (a[j] > pivot) {
        --j;
    }

    /* If current element in left great then or equal to current in right side */
    if (a[i] >= a[j]) {
        swap(a[i++], a[j--]);
    }

    /* Sort new small arrays while array size great then 1 */
    if (j > left) {
        quickSort(a, left, j);
    }
    if (i < right) {
        quickSort(a, i, right);
    }

    return a;
}