#include <iostream>

/* Definition of functions */
int recurse(int);
int loop(int);

int main() {
    int number = 0;

    /*
      Require integer number from client
      Enter number great then 0
    */

    std::cout << "Enter integer number(> 0): ";
    std::cin >> number;

    while (std::cin.fail() || number < 1) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only integer number and great then 0!!!" << std::endl;
        std::cout << "Enter integer number(> 0): ";
        std::cin >> number;
    }

    /* Print number's factorial */
    std::cout << number << " factorial using recursive method: ";
    std::cout << recurse(number) << std::endl;
    std::cout << number <<" factorial using loop method: ";
    std::cout << loop(number) << std::endl;
    return 0;
}

/* Calculate number's factorial using recursive method */
int recurse(int number) {
    if (1 == number) {
        return 1;
    } else {
        return number * recurse(number -1);
    }
}

/* Calculate number's factorial using loop method */
int loop(int number) {
    int factorial = 1;
    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}
