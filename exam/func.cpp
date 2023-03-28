#include "func.h"

/* Get integer number, fixed bad cases */
int getInteger() {
    int number = 0;
    std::cin >> number;

    /* Enter number while it is not integer number or smaller then 0 */
    while (std::cin.fail() || number < 1) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Enter integer number(> 0): ";
        std::cin >> number;
    }

    return number;
}

/* Show all things in shop with costs */
void showThings(int* a, int* b, int n) {
    std::cout << "*** We have ***" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " -> " << b[i] << std::endl;
    }
}

/* Swap function, will be used for double and int */
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/* Get maximum value from array */
int getMax(double* a, int n, int m) {
    int index = n;
    for (int i = n; i < m; ++i) {
        if (a[index] < a[i]) {
            index = i;
        }
    }
    return index;
}

/* Get priority for elements to put in box */
void getPriority(int* a, int* b, double* c, int count) {
    for (int i = 0; i < count; ++i) {
        c[i] = b[i] / (double) a[i];
    }

    /* Sort priorities (selection way) and correspondingly change volume and cost */
    for (int i = 0; i < count - 1; ++i) {
        int min = getMax(c, i + 1, count);
        swap(c[min], c[i]);
        swap(a[min], a[i]);
        swap(b[min], b[i]);
    }
}

/* Get maximum cost elements to put in box */
void getOptimalWay(int* a, int* b, int count, int volume) {
    int i = 0;
    int cost = 0;

    for (i = 0; i < count && volume > 0; ++i) {
        if (a[i] <= volume) {
            volume -= a[i];
            cost += b[i];
            std::cout << a[i] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Maximum cost is: " << cost << std::endl;
}