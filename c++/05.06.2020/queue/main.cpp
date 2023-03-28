#include <iostream>
#include "queue.hpp"

/* Functions prototypes */
int getInteger(std::string key, int number = 0);

int main() {
    /* Get size of queue */
    int size = 0;
    while (size < 1) {
        size = getInteger("Enter link size(> 1): ");
    }

    /* Create queue by size and initialize it */
    Queue* queue = new Queue();
    for (int i = 0; i < size; ++i) {
        int value = getInteger("Enter element ", i + 1);
        queue->push(value);
    }

    /* Print created queue pretty */
    std::cout << "******* Queue *******" << std::endl;
    queue->showQueue();
    std::cout << "*** Now length is: " << queue->getLength() << std::endl;

    /* Add element */
    int value = getInteger("Enter value of element: ");
    queue->push(value);
    std::cout << "New node added!" << std::endl;
    std::cout << "******* Queue *******" << std::endl;
    queue->showQueue();
    std::cout << "*** Now length is: " << queue->getLength() << std::endl;

    /* Delete element from queue */
    queue->pop();
    std::cout << "New node added!" << std::endl;
    std::cout << "******* Queue *******" << std::endl;
    queue->showQueue();
    std::cout << "*** Now length is: " << queue->getLength() << std::endl;

    /* Clear the queue all elements */
    std::cout << "******* Now clear the queue *******" << std::endl;
    queue->cleanQueue();
    std::cout << "Is empty the queue? ";
    if (queue->isQueueEmpty()) {
        std::cout << "Yes, queue is empty!" << std::endl;
    } else {
        std::cout << "Queue isn't empty!" << std::endl;
    }

    /* Delete used memory */
    delete queue;
    return 0;
}

/* Function return integer number
    args:
     key : what we want
     number: index number
*/
int getInteger(std::string key, int number) {
    int n = 0;
    if (0 == number) {
        std::cout << key;
    } else {
        std::cout << key << number << ": ";
    }
    std::cin >> n;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only integer number!!!" << std::endl;
        if (0 == number) {
            std::cout << key;
        } else {
            std::cout << key << number << ": ";
        }
        std::cin >> n;
    }

    return n;
}
