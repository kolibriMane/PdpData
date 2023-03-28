#ifndef logger_h
#define logger_h

#include <string>
#include <iostream>

class Logger {
    private:
        static Logger* instance;
        std::string layer;
        Logger(std::string);
    public:
        static Logger* getInstance(std::string);
};

#endif