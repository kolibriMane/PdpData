#include <iostream>

#include "list.cpp"
#include "node.cpp"

/* Functions prototypes */
template<typename T>
int getNumber(std::string key, int number = 0);

int main() {
    /* Get size of list with integer values */
    int size = 0;
    while (size < 1) {
        size = getNumber<int>("Enter integer-value list size(> 1): ");
    }

    /* Create list with integer values by size and initialize it */
    List<int>* intList = new List<int>();
    for (int i = 0; i < size; ++i) {
        int value = getNumber<int>("Enter integer element ", i + 1);
        intList->insertFirst(value);
    }

    /* Get size of list with double values */
    size = 0;
    while (size < 1) {
        size = getNumber<int>("Enter double-value list size(> 1): ");
    }

    /* Create list with double values by size and initialize it */
    List<double>* doubleList = new List<double>();
    for (int i = 0; i < size; ++i) {
        double value = getNumber<double>("Enter double element ", i + 1);
        doubleList->insertFirst(value);
    }

    /* Print created lists pretty */
    std::cout << "******* Integer list *******" << std::endl;
    intList->show();
    std::cout << "*** Now length is: " << intList->getLength() << std::endl;

    std::cout << "******* Double list *******" << std::endl;
    doubleList->show();
    std::cout << "*** Now length is: " << doubleList->getLength() << std::endl;

    /* Add element to int list*/
    int intValue = getNumber<int>("Enter value of element(int): ");
    intList->insertFirst(intValue);
    std::cout << "New node added!" << std::endl;
    std::cout << "******* Integer list *******" << std::endl;
    intList->show();
    std::cout << "*** Now length is: " << intList->getLength() << std::endl;

    /* Add element to int list*/
    double doubleValue = getNumber<double>("Enter value of element(double): ");
    doubleList->insertFirst(doubleValue);
    std::cout << "New node added!" << std::endl;
    std::cout << "******* Double list *******" << std::endl;
    std::cout << "*** Now length is: " << doubleList->getLength() << std::endl;

    /* Delete element from integer list */
    intList->removeFirst();
    std::cout << "New node deleted!" << std::endl;
    std::cout << "******* Integer list *******" << std::endl;
    intList->show();
    std::cout << "*** Now length is: " << intList->getLength() << std::endl;

    /* Delete element from double list */
    doubleList->removeFirst();
    std::cout << "New node deleted!" << std::endl;
    std::cout << "******* Double list *******" << std::endl;
    doubleList->show();
    std::cout << "*** Now length is: " << doubleList->getLength() << std::endl;

    /* Clear the integer list all elements */
    std::cout << "******* Now clear the integer list *******" << std::endl;
    intList->empty();
    std::cout << "Is empty the integer list? ";
    if (intList->isEmpty()) {
        std::cout << "Yes, integer list is empty!" << std::endl;
    } else {
        std::cout << "Integer list isn't empty!" << std::endl;
    }

    /* Clear the double list all elements */
    std::cout << "******* Now clear the double list *******" << std::endl;
    doubleList->empty();
    std::cout << "Is empty the double list? ";
    if (doubleList->isEmpty()) {
        std::cout << "Yes, double list is empty!" << std::endl;
    } else {
        std::cout << "double list isn't empty!" << std::endl;
    }


    /* Delete used memory */
    delete intList;
    delete doubleList;
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