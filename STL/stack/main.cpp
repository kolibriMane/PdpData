#include <iostream>

#include "stack.cpp"
#include "node.cpp"

/* Functions prototypes */
int getInteger(std::string key, int number = 0);

int main() {
    /* Get size of stack */
    int size = 0;
    while (size < 1) {
        size = getInteger("Enter stack size(> 1): ");
    }

    /* Create stack by size and initialize it */
    Stack<int>* stack = new Stack<int>();
    for (int i = 0; i < size; ++i) {
        int value = getInteger("Enter element ", i + 1);
        stack->push(value);
    }

    /* initialize stack by copy constructor */
    Stack<int>* stack2 = stack;
    Stack<int>* stack3(stack);
    std::cout << "*** Now length is: " << stack->size() << std::endl;

    /* Delete last element */
    if (!stack->empty()) {
        stack->pop();
        std::cout << "New node removed!" << std::endl;
        std::cout << "*** Now length is: " << stack->size() << std::endl;
        std::cout << "*** last node is: " << stack->top() << std::endl;
    }

    /* Is stack clear? */
    std::cout << "*** Check is stack empty? " << std::endl;
    if (stack->empty()) {
        std::cout << "Yes, stack is empty!" << std::endl;
    } else {
        std::cout << "Stack isn't empty!" << std::endl;
    }

    /* Delete used memory */
    if (!stack->empty()) {
        delete stack;
    }

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