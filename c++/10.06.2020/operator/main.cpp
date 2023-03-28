#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <bits/stdc++.h>

/* Functions prototypes */
int getAnswer(int, int, std::string);
int toInteger(std::string);

int main() {
    /* Open file in write mode, to put in that answers */
    std::ofstream answer;
    answer.open("answer", std::ios::out);

    /* Try to open first file to get first number */
    std::ifstream file1;
    file1.open("file1", std::ios::in);
    if (!file1.is_open()) {
        std::cerr << "Can't open the file for first number! " << std::endl;
        return -1;
    }

    /* Try to open first file to get operator */
    std::ifstream oper;
    oper.open("operator", std::ios::in);
    if (!oper.is_open()) {
        std::cerr << "Can't open file for operators! " << std::endl;
        return -1;
    }

    /* Try to open first file to get second number */
    std::ifstream file2;
    file2.open("file2", std::ios::in);
    if (!file2.is_open()) {
        std::cerr << "Can't open the file for second number! " << std::endl;
        return -1;
    }

    /* Buffers to read from 1st, 2nd and 3rd files */
    std::string buffer1 = "";
    std::string buffer2 = "";
    std::string buffer3 = "";
    while (getline(file1, buffer1)) {
        int number1 = toInteger(buffer1);
        while (getline(file2, buffer2)) {
            int number2 = toInteger(buffer2);
            while (getline(oper, buffer3)) {
                answer << number1  << " " << buffer3 << " " << number2 << " = "
                       << getAnswer(number1, number2, buffer3) << std::endl;
            }
            if (oper.is_open()) {
                oper.clear();
                oper.seekg(0, std::ios::beg);
            }
        }
        if (file2.is_open()) {
            file2.clear();
            file2
            .seekg(0, std::ios::beg);
        }
    }

    /* Close opened files */
    file1.close();
    file2.close();
    oper.close();

    return 0;
}

/* Cast string to integer number */
int toInteger(std::string buffer) {
    int length = buffer.length();
    char string[length + 1];
    strcpy(string, buffer.c_str());
    return atoi(string);
}

/*
 Function to get answer of mathematic operation
  return integer value of operation
  arguments:
   int a: first number
   int b: second number
   std::string operat: mathematic operator
*/
int getAnswer(int a, int b, std::string operat) {
    switch(operat[0]) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (0 == b) {
                return 0;
            }
            return a / b;
        default:
            return 0;
    }
}
