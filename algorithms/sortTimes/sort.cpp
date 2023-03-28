#include <iostream>
#include "sort.h"

/* Get minimum number in array form index n to m */
int getMin(int* a, int n, int m) {
    int index = n;
    for (int i = n; i < m; ++i) {
        if (a[index] > a[i]) {
            index = i;
        }
    }
    return index;
}

/* To set a in b, and opposite */
void swap(int& a, int& b) {
    a += b;
    b = a - b;
    a = a - b;
}

/* Sort array, selection way */
int* selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = getMin(arr, i + 1, n);
        swap(arr[min], arr[i]);
    }

    return arr;
}

/* Sort array, insertion way */
int* insertionSort(int* array, int n) {
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && array[j] < array[j-1]) {
            swap(array[j], array[j-1]);
            --j;
        }
    }

    return array;
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

void showArray(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}

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