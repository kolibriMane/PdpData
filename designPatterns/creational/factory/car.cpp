#include "car.h"

Client::Client() {
    CarType type = opel;
    pCar = Car::create(type);
}

Client::~Client() {
    if (pCar) {
        delete pCar;
        pCar = NULL;
    }
}

Car* Client::getCar() {
    return pCar;
}

Car* Car::create(CarType type) {
    if (type == mercedes) {
        return new Mercedes();
    } else if (type == opel) {
        return new Opel();
    } else if (type == nissan) {
        return new Nissan();
    }

    return NULL;
}