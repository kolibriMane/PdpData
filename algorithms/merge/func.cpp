#include "func.h"

void mergeSort(int* array, int size) {
    if (size > 1) {
        int n = size / 2;
        int* array1 = new int[n];
        int m = size - n;
        int* array2 = new int[m];

        for (int i = 0; i < n; ++i) {
            array1[i] = array[i];
        }

        for (int i = 0, j = n; i < m; ++i, ++j) {
            array2[i] = array[j];
        }

        mergeSort(array1, n);
        mergeSort(array2, m);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n && j < m) {
            if (array1[i] <= array2[j]) {
                array[k++] = array1[i++];
            } else {
                array[k++] = array2[j++];
            }
        }

        while (i < n) {
            array[k++] = array1[i++];
        }

        while (j < m) {
            array[k++] = array2[j++];
        }
    }
}

void showArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}