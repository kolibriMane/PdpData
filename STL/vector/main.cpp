#include <iostream>

#include "vector.cpp"
#include "iterator.cpp"

int main() {
    Vector<int> vector;
    std::cout << "Default max size: " << vector.capacity() << std::endl;
    if (vector.empty()) {
        std::cout << "Vector is clear!" << std::endl;
    } else {
        std::cout << "Vector isn't clear!" << std::endl;
    }

    for (int i = 1; i <= 5; ++i) {
        vector.pushBack(i * 100);
    }

    Iterator<int>* i = vector.begin();
    std::cout << *i << std::endl;
    i = vector.end();
    std::cout << *i << std::endl;

    int *a = new int(666);
    Iterator<int> iter(a);
    vector.pushBack(iter);
    for (int i = 0; i < 6; ++i) {
        std::cout << "vector element [" << i << "] is " << vector[i] << std::endl;
    }

    std::cout << "Now size is: " << vector.capacity() << std::endl;
    vector.shrink_to_fit();
    std::cout << "After shrink - capacity is: " << vector.capacity() << std::endl;

    while (!vector.empty()) {
        vector.popBack();
    }

    for (int i = 1; i <= 19; ++i) {
        vector.pushBack(i * 10);
    }

    vector.reverse();
    for (int i = 0; i < 19; ++i) {
        std::cout << "vector element: " << vector[i] << std::endl;
    }

    /* Free used memory */
    delete i;
    delete a;
    return 0;
}