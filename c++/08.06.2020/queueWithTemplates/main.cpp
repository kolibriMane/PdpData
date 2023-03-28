#include <iostream>

#include "queue.hpp"
#include "list.cpp"
#include "node.cpp"
#include "queue.cpp"

/* Functions prototypes */
template<typename T>
int getNumber(std::string key, int number = 0);

int main() {
    /* Get size of queue with integer values */
    int size = 0;
    while (size < 1) {
        size = getNumber<int>("Enter integer-value queue size(> 1): ");
    }

    /* Create queue with integer values by size and initialize it */
    Queue<int>* intQueue = new Queue<int>();
    for (int i = 0; i < size; ++i) {
        int value = getNumber<int>("Enter integer element ", i + 1);
        intQueue->push(value);
    }

    /* Get size of queue with double values */
    size = 0;
    while (size < 1) {
        size = getNumber<int>("Enter double-value queue size(> 1): ");
    }

    /* Create queue with double values by size and initialize it */
    Queue<double>* doubleQueue = new Queue<double>();
    for (int i = 0; i < size; ++i) {
        double value = getNumber<double>("Enter double element ", i + 1);
        doubleQueue->push(value);
    }

    /* Print created queues pretty */
    std::cout << "******* Integer queue *******" << std::endl;
    intQueue->showQueue();
    std::cout << "*** Now length is: " << intQueue->getLength() << std::endl;

    std::cout << "******* Double queue *******" << std::endl;
    doubleQueue->showQueue();
    std::cout << "*** Now length is: " << doubleQueue->getLength() << std::endl;

    /* Add element to int queue*/
    int intValue = getNumber<int>("Enter value of element(int): ");
    intQueue->push(intValue);
    std::cout << "New node added!" << std::endl;
    std::cout << "******* Integer queue *******" << std::endl;
    intQueue->showQueue();
    std::cout << "*** Now length is: " << intQueue->getLength() << std::endl;

    /* Add element to int queue*/
    double doubleValue = getNumber<double>("Enter value of element(double): ");
    doubleQueue->push(doubleValue);
    std::cout << "New node added!" << std::endl;
    std::cout << "******* Double queue *******" << std::endl;
    doubleQueue->showQueue();
    std::cout << "*** Now length is: " << doubleQueue->getLength() << std::endl;

    /* Delete element from integer queue */
    intQueue->pop();
    std::cout << "New node deleted!" << std::endl;
    std::cout << "******* Integer queue *******" << std::endl;
    intQueue->showQueue();
    std::cout << "*** Now length is: " << intQueue->getLength() << std::endl;

    /* Delete element from double queue */
    doubleQueue->pop();
    std::cout << "New node deleted!" << std::endl;
    std::cout << "******* Double queue *******" << std::endl;
    doubleQueue->showQueue();
    std::cout << "*** Now length is: " << doubleQueue->getLength() << std::endl;

    /* Clear the integer queue all elements */
    std::cout << "******* Now clear the integer queue *******" << std::endl;
    intQueue->cleanQueue();
    std::cout << "Is empty the integer queue? ";
    if (intQueue->isQueueEmpty()) {
        std::cout << "Yes, integer queue is empty!" << std::endl;
    } else {
        std::cout << "Integer queue isn't empty!" << std::endl;
    }

    /* Clear the double queue all elements */
    std::cout << "******* Now clear the double queue *******" << std::endl;
    doubleQueue->cleanQueue();
    std::cout << "Is empty the double queue? ";
    if (doubleQueue->isQueueEmpty()) {
        std::cout << "Yes, double queue is empty!" << std::endl;
    } else {
        std::cout << "double queue isn't empty!" << std::endl;
    }


    /* Delete used memory */
    delete intQueue;
    delete doubleQueue;
    return 0;
}

/* Function return number
    args:
     key : what we want
     number: index number
*/
template<typename T>
int getNumber(std::string key, int number) {
    T n = 0;
    if (0 == number) {
        std::cout << key;
    } else {
        std::cout << key << number << ": ";
    }
    std::cin >> n;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only number!!!" << std::endl;
        if (0 == number) {
            std::cout << key;
        } else {
            std::cout << key << number << ": ";
        }
        std::cin >> n;
    }

    return n;
}
