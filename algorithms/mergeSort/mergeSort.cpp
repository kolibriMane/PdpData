#include "mergeSort.h"

/* Merge sort - recursive way */
void mergeSort(int* array, int size) {
    /* If array size great then 1 */
    if (size > 1) {
        /* New array first part of array */
        int n = size / 2;
        int* array1 = new int[n];
        int m = size - n;
        int* array2 = new int[m];

        for (int i = 0; i < n; ++i) {
            array1[i] = array[i];
        }

        for (int i = 0, j = n; j < size; ++i, ++j) {
            array2[i] = array[j];
        }

        /* Divide arrays in small arrays */
        mergeSort(array1, n);
        mergeSort(array2, m);

        /* Current element index in first array */
        int i = 0;
        /* Current element index in second array */
        int j = 0;
        /* Current element index in new array */
        int k = 0;

        /* while in 2 arrays exists element, add smaller */
        while (i < n && j < m) {
            if (array1[i] <= array2[j]) {
                array[k++] = array1[i++];
            } else {
                array[k++] = array2[j++];
            }
        }

        /* While in first array exists element, add in new array */
        while (i < n) {
            array[k++] = array1[i++];
        }

        /* While in first array exists element, add in new array */
        while (j < m) {
            array[k++] = array2[j++];
        }
    }
}

/*
* Get integer number, fixed bad cases
* If bigger is true, number must be greater then 0
* If bigger is false, number can be any integer number
*/
int getInteger(bool bigger) {
    int number = 0;
    if (bigger) {
        std::cout << "Enter integer number(> 0): ";
    } else {
        std::cout << "Enter integer number: ";
    }
    std::cin >> number;

    if (bigger) {
        /* Enter number while it is not integer number or smaller 0 */
        while (std::cin.fail() || number < 1) {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Enter integer number(> 0): ";
            std::cin >> number;
        }
    } else {
        /* Enter number while it is not intger number*/
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Enter integer number: ";
            std::cin >> number;
        }
    }

    return number;
}

/* Create and initialize array */
int* initArray(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "a[" << i + 1 << "]: ";
        a[i] = getInteger(false);
    }

    return a;
}

/* Print array */
void showArray(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}