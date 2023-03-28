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

/* Function returns array where ugly numbers for 2, 3 or 5 */
int* getNumber(int index, int number) {
    int* array = new int[index];
    array[0] = 1;

    for (int i = 1, j = 1; i < index; ++j) {
        if (isUgly(j * number)) {
            array[i++] = j * number;
        }
    }

    for (int i = 0; i < index; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return array;
}

int getUglyNumber(int index) {
    int* a2 = getNumber(index, 2);
    int* a3 = getNumber(index, 3);
    int* a5 = getNumber(index, 5);

    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    int j = 0;
    int* array = new int[index];

    while (i2 < index && i3 < index && i5 < index && j < index) {
        if (a2[i2] == a3[i3] && a2[i2] == a5[i5]) {
            array[j++] = a5[i5++];
            ++i2;
            ++i3;
        } else if (a2[i2] < a3[i3] && a2[i2] < a5[i5]) {
            array[j++] = a2[i2++];
        } else if (a3[i3] < a2[i2] && a3[i3] < a5[i5]) {
            array[j++] = a3[i3++];
        } else if (a5[i5] < a3[i3] && a5[i5] < a2[i2]) {
            array[j++] = a5[i5++];
        } else if (a2[i2] == a3[i3]) {
            array[j++] = a2[i2++];
            ++i3;
        } else if (a2[i2] == a5[i5]) {
            array[j++] = a2[i2++];
            ++i5;
        } else if (a5[i5] == a3[i3]) {
            array[j++] = a5[i5++];
            ++i3;
        }
    }

    while (j < index && i2 < index && i3 < index) {
        if (a2[i2] < a3[i3]) {
            array[j++] = a2[i2++];
        } else if (a2[i2] < a3[i3]) {
            array[j++] = a3[i3++];
        } else {
            array[j++] = a3[i3++];
            ++i2;
        }
    }

    while (j < index && i2 < index && i5 < index) {
        if (a2[i2] < a5[i5]) {
            array[j++] = a2[i2++];
        } else if (a2[i2] < a5[i5]) {
            array[j++] = a5[i5++];
        } else {
            array[j++] = a3[i5++];
            ++i2;
        }
    }

    while (j < index && i5 < index && i3 < index) {
        if (a5[i5] < a3[i3]) {
            array[j++] = a5[i5++];
        } else if (a5[i5] < a3[i3]) {
            array[j++] = a3[i3++];
        } else {
            array[j++] = a3[i3++];
            ++i5;
        }
    }

    for (int i = 0; i < index; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return array[index - 1];
}
