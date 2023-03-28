#ifndef ITERATOR_H
#define ITERATOR_H

#include <ostream>
template <typename T>
class Iterator {
    public:
        Iterator();
        Iterator(T*);
        ~Iterator();
        Iterator& operator+(int);
        Iterator& operator-(int);
        Iterator operator++(int);
        Iterator operator++();
        Iterator operator--(int);
        Iterator operator--();
        T& operator*();
        friend std::ostream& operator<<(std::ostream& os, const Iterator<T>& iter) {
            os << *(iter.ptr);
            return os;
        }
        Iterator<T>*& operator=(Iterator<T>*);
        Iterator<T>* operator=(T*);
        bool operator==(const Iterator& b) const;
        bool operator!=(const Iterator& b) const;
    private:
        T* ptr;
};

#endif