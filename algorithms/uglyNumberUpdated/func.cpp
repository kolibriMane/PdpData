#include "func.h"

int getInteger() {
    int n = 0;
    std::cin >> n;

    while (std::cin.fail() || n < 1) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cerr << "Invalid number, try again)" << std::endl;
        std::cin >> n;
    }

    return n;
}

/* Function to check if a number is ugly or not */
int isUgly(int number) {
    while (0 == number % 2) {
        number /= 2;
    }

    while (0 == number % 3) {
        number /= 3;
    }

    while (0 == number % 5) {
        number /= 5;
    }

    return (1 == number) ? true : false;
}

/* Function returns next ugly number for number 2, 3 or 5*/
int getNextUgly(int number, int last) {
    int value = 0;
    do {
        value = last / number;
        ++value;
        value *= number;
        last = value;
    } while (!isUgly(value));
    return value;
}

/* Get index-th ugly number */
int getUglyNumber(int index) {
    int ugly2 = 2;
    int ugly3 = 3;
    int ugly5 = 5;

    int* array = new int[index];
    array[0] = 1;
    int k = 1;

    while (k < index) {
        if (ugly2 == ugly3 && ugly3 == ugly5) {
            array[k++] = ugly5;
            ugly5 = getNextUgly(5, ugly5);
            ugly3 = getNextUgly(3, ugly3);
            ugly2 = getNextUgly(2, ugly2);
        } else if (ugly2 < ugly3 && ugly2 < ugly5) {
            array[k++] = ugly2;
            ugly2 = getNextUgly(2, ugly2);
        } else if (ugly3 < ugly2 && ugly3 < ugly5) {
            array[k++] = ugly3;
            ugly3 = getNextUgly(3, ugly3);
        } else if (ugly5 < ugly2 && ugly5 < ugly3) {
            array[k++] = ugly5;
            ugly5 = getNextUgly(5, ugly5);
        } else if (ugly2 == ugly3) {
            array[k++] = ugly2;
            ugly2 = getNextUgly(2, ugly2);
            ugly3 = getNextUgly(3, ugly3);
        } else if (ugly2 == ugly5) {
            array[k++] = ugly5;
            ugly5 = getNextUgly(5, ugly5);
            ugly2 = getNextUgly(2, ugly2);
        } else if (ugly5 == ugly3) {
            array[k++] = ugly5;
            ugly3 = getNextUgly(3, ugly3);
            ugly5 = getNextUgly(5, ugly5);
        }
    }

    return array[index - 1];
}