#include <iostream>
#include <cmath>

/* Definition of functions */
int sum(int, int);
int mul(int, int);
int min(int, int);
int max(int, int);
int power(int, int);
double average(int, int);

int main() {
    /* Request a user to insert two integer numbers */
    int firstNum = 0;
    std::cout << "Enter first integer number: ";
    std::cin >> firstNum;

    int secondNum = 0;
    std::cout << "Enter second integer number: ";
    std::cin >> secondNum;

    /* Show input numbers */
    std::cout << "First number is: " << firstNum << std::endl;
    std::cout << "Second number is: " << secondNum << std::endl;

    /* Calculate minimum, maximum, product, arithmetic average, etc. */
    std::cout << "Max: " << max(firstNum, secondNum) << std::endl;
    std::cout << "Min: " << min(firstNum, secondNum) << std::endl;
    std::cout << "Sum: " << sum(firstNum, secondNum) << std::endl;
    std::cout << "Mul: " << mul(firstNum, secondNum) << std::endl;
    std::cout << "Pow: " << power(firstNum, secondNum) << std::endl;
    std::cout << "The arithmetic average: " << average(firstNum, secondNum) << std::endl;
    return 0;
}

/* Declarations of functions */
int sum(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int min(int a, int b) {
    return (a < b ? a : b);
}

int max(int a, int b) {
    return (a > b ? a : b);
}

double average(int a, int b) {
    return (a + b) / (double) 2;
}

int power(int a, int b) {
    return pow(a, b);
}
