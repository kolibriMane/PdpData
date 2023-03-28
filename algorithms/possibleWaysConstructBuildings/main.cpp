#include "possibleWays.h"

int main() {
    std::cout << "Enter space count: ";
    int space = getInteger();
    std::cout << "House count is: " << getHouseCount(space) << std::endl;
    return 0;
}