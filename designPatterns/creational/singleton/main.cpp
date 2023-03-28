#include "logger.h"

int main() {
    Logger* obj1 = Logger::getInstance("info");
    Logger* obj2 = Logger::getInstance("error");

    std::cout << obj1 << std::endl;
    std::cout << obj2 << std::endl;

    delete obj1;
    delete obj2;
    return 0;
}