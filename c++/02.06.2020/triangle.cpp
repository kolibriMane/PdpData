#include <iostream>

/* Definition of functions */
void printTriangle(int);

int main() {
    /* Get size of triangle's side */
    int size = 0;
    std::cout << "Enter integer number(> 1): ";
    std::cin >> size;

    while (std::cin.fail() || size < 2) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only integer number and great then 1!!!" << std::endl;
        std::cout << "Enter integer number(> 1): ";
        std::cin >> size;
    }

    /* Show triangle */
    printTriangle(size);
    return 0;
}

/* Print the triangle by size */
void printTriangle(int size) {
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j < 2 * size - i; ++j) {
            if (i == 1) {
                if (1 == j % 2) {
                    std::cout << "*";
                } else {
                    std::cout << " ";
                }
            } else if (j == i) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "*" << std::endl;
    }
}
