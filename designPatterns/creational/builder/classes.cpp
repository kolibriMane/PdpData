#include "classes.h"

void Pizza::setSize(int size) {
    this->size = size;
}

void Pizza::setCheese(std::string cheese) {
    this->cheese = cheese;
}

void Pizza::setSauce(std::string sauce) {
    this->sauce = sauce;
}

void Pizza::setPepperoni(std::string pepperoni) {
    this->pepperoni = pepperoni;
}

void Pizza::setOlive(std::string olive) {
    this->olive = olive;
}

void Pizza::setMushroom(std::string mushroom) {
    this->mushroom = mushroom;
}

void Pizza::setBacon(std::string bacon) {
    this->bacon = bacon;
}

void Pizza::setOnion(std::string onion) {
    this->onion = onion;
}

void Pizza::setPepper(std::string pepper) {
    this->pepper = pepper;
}

Pizza::Pizza(std::string name) {
    this->name = name;
}

Pizza::~Pizza() {}

Pizza* Builder::createSiciliana() {
    Pizza* pizza = new Pizza("Siciliana");
    pizza->setSize(2);
    pizza->setCheese("Mocarella");
    pizza->setBacon("chicken");
    return pizza;
}