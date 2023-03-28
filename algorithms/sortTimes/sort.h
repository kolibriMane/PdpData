#ifndef SORT_H
#define SORT_H

#include <cstdlib>

inline void swap(int&, int&);
inline void showArray(int*, int);
int* initArray(int*, int);
int getSize();
int* insertionSort(int*, int);
int* selectionSort(int*, int);
inline int getMin(int*, int, int);
void mergeSort(int* array, int size);

#endif