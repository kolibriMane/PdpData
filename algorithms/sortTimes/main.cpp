#include <iostream>
#include <chrono>

#include "sort.h"

int main() {
    /* Initialize rand number generator */
    srand(time(NULL));

    /* Create and initialize array to sort*/
    int size = getSize();
    int* a = initArray(a, size);
    int* b = a;
    int* c = a;


    /* Sort insertion way and count miliseconds */
    auto start1 = std::chrono::high_resolution_clock::now();
    a = insertionSort(a, size);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);

    std::cout << "Insertion sort -> "<< duration1.count() << std::endl;


    /* Sort selection way and count miliseconds */
    auto start2 = std::chrono::high_resolution_clock::now();
    b = selectionSort(b, size);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

    std::cout << "Selection sort -> "<< duration2.count() << std::endl;

    /* Sort merge way and count miliseconds */
    auto start3 = std::chrono::high_resolution_clock::now();
    mergeSort(c, size);
    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);

    std::cout << "Merge sort -> "<< duration3.count() << std::endl;


    return 0;
}