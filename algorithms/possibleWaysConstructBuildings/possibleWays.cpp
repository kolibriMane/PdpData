#include "possibleWays.h"

/* get Fibonacci index-nth number */
int getFibonacciElement(int index, std::vector<int>& vector) {
    int size = vector.size();
    if (size > index) {
        return vector[index];
    } else if (1 == size) {
        vector.push_back(1);
    } else if (0 == size) {
        vector.push_back(1);
        vector.push_back(1);
    }

    size = vector.size();
    for (int i = size - 1; i < index; ++i) {
        vector.push_back(vector[i - 1] + vector[i]);
    }

    return vector[index - 1];
}

/* Count possible ways to construct buildings */
int getHouseCount(int space) {
    std::vector<int> vector;
    int num = getFibonacciElement(space + 1, vector);
    return num * num;
}

/*
* Get integer number, fixed bad cases
* If bigger is true, number must be greater then 0
* If bigger is false, number can be any integer number
*/
int getInteger() {
    int number = 0;
    std::cin >> number;

    /* Enter number while it is not integer number or smaller 0 */
    while (std::cin.fail() || number < 1) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Enter number, great then 0: ";
        std::cin >> number;
    }

    return number;
}