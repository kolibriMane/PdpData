#include <iostream>
#include <string>

#include "myException.hpp"

/* Constructor */
MyException::MyException(const std::string& errorMess) throw() {
    this->errorMess = errorMess;
}

/* convert the error message to const char* and return */
const char* MyException::what() {
    return errorMess.c_str();
}