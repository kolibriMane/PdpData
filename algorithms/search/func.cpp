#include <cmath>
#include "func.h"

/* Merge sort for array elements */
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

int linearSearch(int* a, int left, int n, int value) {
    for (int i = left; i < n; ++i) {
        if (value == a[i]) {
            return i;
        }
    }

    return -1;
}


int binarySearch(int* a, int left, int right, int value) {
    if (right >= left) {
        int index = left + (right - left) / 2;

        if (a[index] == value) {
            return index;
        } else if (a[index] < value) {
            return binarySearch(a, index + 1, right, value);
        }

        return binarySearch(a, left, index - 1, value);

    }

    return -1;
}

/* Jump search recursive way, used linearSearch */
int jumpSearch(int* a, int left, int size, int value) {
    if (left < size) {
        int jump = sqrt(size);
        int index = left;

        if (a[index] == value) {
            return index;
        } else if (a[index] > value) {
            return linearSearch(a, index + 1, size, value);
        } else {
            return jumpSearch(a, index + 1, size, value);
        }
    }

    return -1;
}

/* Find element with some formula */
int interpolationSearch(int* array, int size, int value) {
    /* First element index and minimum element index in array */
    int left = 0;
    /* Last element index and maximum element index in array */
    int right = size - 1;

    /* If value great then max value or less then min value in array */
    if (value < array[left] || value > array[right]) {
        return -1;
    }

    /* If array size 1 */
    if (left == right) {
        if (array[left] == value) {
            return left;
        }

        return -1;
    }

    /* Calculate near position for value */
    int position = left + (((double)(right - left) /
        (array[right] - array[left])) * (value - array[left]));

    /* Compair position value, or surrounded it */
    while (position <= right && position >= left) {
        if (array[position] == value) {
            return position;
        } else if (array[position] < value) {
            ++position;
        } else {
            --position;
        }
    }

    return -1;
}

/* Find value using binary search */
int exponentialSearch(int* array, int size, int value) {
    int index = 0;
    if (array[index] == value) {
        return index;
    }

    ++index;
    /* Get range to find binary */
    while (index < size && array[index] <= value) {
        index *= 2;
    }

    /* Check found range binary way */
    int minIndex = (index > size) ? size : index;
    return binarySearch(array, index / 2, minIndex, value);
}

/* Check are main arguments invalid */
bool isInvalidArgs(int count, char* array[]) {
    if (2 != count) {
        std::cerr << "Not valid arguments!" << std::endl;
        return true;
    }

    if (0 != strcmp(array[1], "binary") && 0 != strcmp(array[1], "jump")
        && 0 != strcmp(array[1], "linear") && 0 != strcmp(array[1], "inter")
        && 0 != strcmp(array[1], "expon") && 0 != strcmp(array[1], "tern")) {

        std::cerr << "Not valid arguments!" << std::endl;
        return true;
    }

    return false;
}

/* Find element in array, like binary search, but with 3 parts of array */
int ternarySearch(int* array, int left, int right, int value) {
    if (right >= left) {
        /* Find 2 middle elements */
        int index1 = left + (right - left) / 3;
        int index2 = right - (right - left) / 3;

        /* Compair 2 middle elements with value */
        if (array[index1] == value) {
            return index1;
        }

        if (array[index2] == value) {
            return index2;
        }

        /* If value can be in first part of array, find recursively */
        if (value < array[index1]) {
            return ternarySearch(array, left, index1 - 1, value);
        /* If value can be in second part of array, find recursively */
        } else if (value > array[index2]) {
            return ternarySearch(array, index2 + 1, right, value);
        /* If value can be in third part of array, find recursively */
        } else {
            return ternarySearch(array, index1 + 1, index2 - 1, value);
        }
    }

    return -1;
}