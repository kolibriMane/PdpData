#ifndef VECTOR_H
#define  VECTOR_H

#include "iterator.h"

template <typename T>
class Vector {
    public:
        Vector();
        Vector(int);
        ~Vector();
        Vector(Vector&);

        void pushBack(const T&);
        void pushBack(Iterator<T> iter);
        void popBack();
        int size() const;
        int capacity() const;
        bool empty() const;
        void resize(int , T value = 0);
        void reserve(int);
        void reverse();
        void shrink_to_fit();
        Vector& operator=(const Vector&);
        T operator[](int );
        Iterator<T>* begin();
        Iterator<T>* end();

    private:
        int length;
        int cap;
        T* a;
        Iterator<T>* first;
        Iterator<T>* last;
};

#endif