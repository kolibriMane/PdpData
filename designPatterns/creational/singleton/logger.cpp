#include "logger.h"

Logger* Logger::instance = NULL;

Logger* Logger::getInstance(std::string layer) {
    if (instance == NULL) {
        instance = new Logger(layer);
    }

    return instance;
}

Logger::Logger(std::string layer) {
    this->layer = layer;
}