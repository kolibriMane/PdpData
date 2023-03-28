#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

class Options {
    protected:
        int size;
        std::string cheese;
        std::string sauce;
        std::string pepperoni;
        std::string olive;
        std::string mushroom;
        std::string bacon;
        std::string onion;
        std::string pepper;
    public:
        virtual void setSize(int) = 0;
        virtual void setCheese(std::string) = 0;
        virtual void setSauce(std::string) = 0;
        virtual void setPepperoni(std::string) = 0;
        virtual void setOlive(std::string) = 0;
        virtual void setMushroom(std::string) = 0;
        virtual void setBacon(std::string) = 0;
        virtual void setOnion(std::string) = 0;
        virtual void setPepper(std::string) = 0;
};

class Pizza: public Options {
    protected:
        std::string name;
    public:
        Pizza() {}
        Pizza(std::string);
        ~Pizza();
        void setSize(int);
        void setCheese(std::string);
        void setSauce(std::string);
        void setPepperoni(std::string);
        void setOlive(std::string);
        void setMushroom(std::string);
        void setBacon(std::string);
        void setOnion(std::string);
        void setPepper(std::string);
};

class Builder {
    public:
        Pizza* createSiciliana();
};


#endif