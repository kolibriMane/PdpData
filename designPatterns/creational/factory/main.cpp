#include "car.h"

int main() {
    Client* pClient = new Client();
    Car* pCar = pClient->getCar();
    pCar->drive();

    delete pClient;
    delete pCar;

    return 0;
}