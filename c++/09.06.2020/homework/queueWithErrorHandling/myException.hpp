#ifndef MY_EXCEPTION_HPP
#define MY_EXCEPTION_HPP

#include <string>
#include <exception>

class MyException : public std::exception {
public:
    private:
        std::string errorMess;
    public:
        virtual ~MyException() throw() {}
        MyException (const std::string&) throw();
        virtual const char* what();
};

#endif