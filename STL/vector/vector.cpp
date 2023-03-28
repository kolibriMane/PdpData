#include "vector.h"
#include <cstring>

template <typename T>
Vector<T>::Vector(): Vector<T>::Vector(1) {
}

template <typename T>
Vector<T>::Vector(int n) {
    if (n > 0) {
        a = new T[n];
        memset(a, 0, n);
        length = n;
        cap = 0;
    }

    first = new Iterator<T>(a);
    last = new Iterator<T>(a);
}

template <typename T>
Vector<T>::~Vector() {
    length = 0;
    cap = 0;
    delete [] a;
}

template <typename T>
Vector<T>::Vector(Vector& vector) {
    int newSize = vector.size();
    this->resize(newSize);
    for (int i = 0; i < newSize; ++i) {
        a[i] = vector[i];
    }

    this->first = new Iterator<T>(vector.begin());
    this->last = new Iterator<T>(vector.end());
}

template <typename T>
void Vector<T>::pushBack(const T& value) {
    if (length == cap) {
        a = (T*) realloc(a, length * 2 * sizeof(T));
        length *= 2;
        a[cap++] = value;
        if (cap == 1) {
            Iterator<T>* temp = new Iterator<T>(a);
            first = temp;
            last = temp;
        } else {
            Iterator<T>* temp = new Iterator<T>(a + cap - 1);
            last = temp;
        }
    } else if (cap < length) {
        a[cap++] = value;
        if (cap == 1) {
            Iterator<T>* temp = new Iterator<T>(a);
            first = temp;
            last = temp;
        } else {
            Iterator<T>* temp = new Iterator<T>(a + cap - 1);
            last = temp;
        }
    }
}

template <typename T>
void Vector<T>::pushBack(Iterator<T> iter) {
    T value = *(iter);
    std::cout << value << std::endl;
    if (length == cap) {
        a = (T*) realloc(a, length * 2 * sizeof(T));
        length *= 2;
        a[cap++] = value;
        if (cap == 1) {
            Iterator<T>* temp = new Iterator<T>(a);
            first = temp;
            last = temp;
        } else {
            Iterator<T>* temp = new Iterator<T>(a + cap - 1);
            last = temp;
        }
    } else if (cap < length) {
        a[cap++] = value;
        if (cap == 1) {
            Iterator<T>* temp = new Iterator<T>(a);
            first = temp;
            last = temp;
        } else {
            Iterator<T>* temp = new Iterator<T>(a + cap - 1);
            last = temp;
        }
    }
}

template <typename T>
void Vector<T>::popBack() {
    if (cap > 0) {
        a[cap--] = 0;
        Iterator<T>* temp = new Iterator<T>(a + cap - 1);
        last = temp;
    }
}

template <typename T>
int Vector<T>::size() const{
    return length;
}

template <typename T>
int Vector<T>::capacity() const {
    return cap;
}

template <typename T>
bool Vector<T>::empty() const {
    if (0 == cap) {
        return true;
    }
    return false;
}

template <typename T>
void Vector<T>::resize(int n, T value) {
    if (n < length) {
        a = (T*) realloc(a, n * sizeof(T));
        length = cap = n;
    } else if (n > length) {
        a = (T*) realloc(a, n * sizeof(T));
        for (int i = length; i < n; ++i) {
            a[i] = value;
        }
        length = n;
    }
}

template <typename T>
void swap(T& a, T&b) {
    a += b;
    b = a - b;
    a = a - b;
}

template <typename T>
void Vector<T>::reverse() {
    for (int i = 0, j = cap - 1; i < cap / 2; ++i, --j) {
        swap(a[i], a[j]);
    }
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    if (cap < length) {
        a = (T*) realloc(a, cap * sizeof(T));
        length = cap;
    }
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector& v) {
    a = (T*) realloc(v, v.size() * sizeof(v[0]));
    return a;
}

template <typename T>
T Vector<T>::operator[] (int n) {
    return a[n];
}

template <typename T>
Iterator<T>* Vector<T>::begin() {
    return first;
}

template <typename T>
Iterator<T>* Vector<T>::end() {
    return last;
}