#include <iostream>
#include "list.hpp"

/* Functions prototypes */
int getInteger(std::string key, int number = 0);

int main() {
    /* Get size of list */
    int size = 0;
    while (size < 1) {
        size = getInteger("Enter link size(> 1): ");
    }

    /* Create list by size and initialize it */
    List* list = new List();
    for (int i = 0; i < size; ++i) {
        int value = getInteger("Enter element ", i + 1);
        list->asyncInsertElement(i + 1, value);
    }

    /* Print created list pretty */
    std::cout << "******* List *******" << std::endl;
    list->show();
    std::cout << "*** Now length is: " << list->getLength() << std::endl;

    /* Add element by index */
    int index = -1;
    while (index < 1) {
        index = getInteger("Enter index to add element(> 0): ");
    }
    int value = getInteger("Enter value of element: ");
    if (list->asyncInsertElement(index - 1, value)) {
        std::cout << "New node added!" << std::endl;
        std::cout << "******* List *******" << std::endl;
        list->show();
        std::cout << "*** Now length is: " << list->getLength() << std::endl;
    } else {
        std::cout << "Can't add element in index " << index << std::endl;
    }

    /* Delete element by index */
    index = -1;
    while (index < 0) {
        index = getInteger("Enter index to delete element(> 0): ");
    }
    if (list->asyncRemoveElement(index - 1)) {
        std::cout << "New node added!" << std::endl;
        std::cout << "******* List *******" << std::endl;
        list->show();
        std::cout << "*** Now length is: " << list->getLength() << std::endl;
    } else {
        std::cout << "Can't delete element in index " << index << std::endl;
    }

    /* Get element by index */
    index = -1;
    while (index < 1) {
        index = getInteger("Enter index to get element(> 0): ");
    }
    std::cout << "Element is: " << list->getElement(index - 1) << std::endl;

    /* Clear the list all elements */
    std::cout << "******* Now clear the list *******" << std::endl;
    list->empty();
    std::cout << "Is empty the list? ";
    if (list->isEmpty()) {
        std::cout << "Yes, list is empty!" << std::endl;
    } else {
        std::cout << "List isn't empty!" << std::endl;
    }

    /* Delete used memory */
    delete list;
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