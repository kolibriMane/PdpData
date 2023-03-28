#include "func.h"

int main() {
    std::cout << "Enter old string: ";
    std::string str = "";
    std::cin >> str;

    std::cout << "Enter new string: ";
    std::string newStr = "";
    std::cin >> newStr;

    std::cout << "String 1: " << str << std::endl;
    std::cout << "String 2: " << newStr << std::endl;
    std::cout << "Strings Difference: ";
    std::cout << stringDiff(str, newStr) << std::endl;

    return 0;
}