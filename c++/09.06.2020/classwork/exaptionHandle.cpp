#include <iostream>
#include <string>
#include <stdlib.h>

/* Prototypes of functions */
double divide(int, int);
int getNumber(std::string);
int* createArray(int);
int getElementByIndex(int*, int, int);

int main() {
    int first = getNumber("Enter first number: ");
    int second = getNumber("Enter second number: ");

    double div = 0;
    try {
        std::cout << first << " / " << second << " = "
                  << divide(first, second) << std::endl;
    } catch(const char* err) {
        std::cout << err << std::endl;
    }

/*
    Floating point exception (core dumped)
    std::cout << first / 0 << std::endl;
*/

    int length = getNumber("Enter array size: ");
    srand(time(NULL));
    int* arr = createArray(length);
    std::cout << "*** Get element by index ***" << std::endl;
    int index = getNumber("Enter index to get element: ");

    try {
        std::cout << getElementByIndex(arr, length, index) << std::endl;
    } catch (int err) {
        if (-1 == err) {
            std::cout << "Index is small then 0 !" << std::endl;
        } else {
            std::cout << "Index is great then length of array !" << std::endl;
        }
    }

/*
    Segmentation fault (core dumped)
    std::cout << arr[length + 10000];
*/

    return 0;
}

/* Get division of numbers, with error throwing */
double divide(int a, int b) {
    if (0 == b) {
        throw "Division by zero!";
    }
    return a / (double)b;
}

/* Get integer number */
int getNumber(std::string key) {
    int n = 0;
    std::cout << key;
    std::cin >> n;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only integer number !!!" << std::endl;
        std::cout << key;
        std::cin >> n;
    }

    return n;
}

/* Create array by size */
int* createArray(int length) {
    int* arr = new int();

    /* Initialize array */
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return arr;
}

/* Get element from array by index */

int getElementByIndex(int* arr, int length, int index) {
    if (0 > index) {
        throw -1;
    } else if (index >= length) {
        throw -2;
    }

    return arr[index];
}