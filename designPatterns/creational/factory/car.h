#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

enum CarType {
    mercedes, opel, nissan
};

class Car {
    public:
        virtual void drive() = 0;
        static Car* create(CarType type);
};

class Mercedes: public Car {
    public:
        void drive() {
            std::cout << "Mercedes drive" << std::endl;
        }
};

class Opel: public Car {
public:
    void drive() {
        std::cout << "Opel drive" << std::endl;
    }
};

class Nissan: public Car {
    public:
    void drive() {
        std::cout << "Nissan drive" << std::endl;
    }
};

class Client {
    private:
        Car *pCar;
    public:
        Client();
        ~Client();
        Car* getCar();
};

#endif