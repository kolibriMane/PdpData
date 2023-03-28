#include "func.h"

int main() {
    std::cout << "Enter index: ";
    int index = getInteger();
    int number = getUglyNumber(index);
    std::cout << "Ugly number: " << number << std::endl;
    return 0;
}