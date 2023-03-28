#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <cstring>

/* Function's prototypes */
int getInteger(bool);
void mergeSort(int*, int);
void showArray(int*, int);
int* initArray(int*, int);
bool isInvalidArgs(int, char**);
int jumpSearch(int*, int, int, int);
int binarySearch(int*, int, int, int);
int linearSearch(int*, int, int, int);
int exponentialSearch(int*, int, int);
int ternarySearch(int*, int, int, int);
int interpolationSearch(int*, int, int);

#endif