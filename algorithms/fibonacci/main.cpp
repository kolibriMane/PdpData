#include "fibon.h"

int main() {
    std::vector<int> vector;
    std::cout << "Fibonacci 1: "  << getRecurse(1, vector) << std::endl;
    std::cout << "Fibonacci 2: "  << getRecurse(2, vector) << std::endl;
    std::cout << "Fibonacci 10: "  << getRecurse(10, vector) << std::endl;
    return 0;
}