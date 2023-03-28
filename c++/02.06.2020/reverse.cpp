#include <iostream>

/* Definition of functions */
char* reverse(char*, int);
void swap(char&, char&);

int main() {
    /* Initialize string */
    char string[1000];
    std::cout << "Enter the string to reverse: ";
    std::cin.getline(string, 1000);

    /* Get length of string */
    int length = 0;
    int i = 0;
    while (string[i] != '\0') {
        length = i;
        ++i;
    }

    /* Show old and new versions of strings */
    std::cout << "Old string is: " << string << std::endl;
    std::cout << "New string is: " << reverse(string, length) << std::endl;
}

/* Put first variable value to second, and vice versa  */
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

/*
    Get and reverse the string
    Arguments:
        string - string will be reversed
        size - length of string
    return:
        new string
*/
char* reverse(char* string, int size) {
    for (int i = 0, j = size - 1; i < size / 2; ++i, --j) {
        swap(string[i], string[j]);
    }

    return string;
}
