#include <iostream>
#include <stack>
#include <cmath>

int getPriority(char);
int getAnswer(int, int, char);
int getStringAnswer(char*, int);
bool isValid(char*, int);
bool isNumber(char);
char* deleteSpaces(char*, int);
int getStringSize(char*);

int main() {
    char* string = "1 + 2 - 5 * 2 - 2 ^ 3 / 2 + (1 + 2) * 2";
    int size = getStringSize(string);
    /* Normalize the string */
    string = deleteSpaces(string, size);
    /* Get new size of string after changes */
    size = getStringSize(string);

    /* If the string is not valid, finish work */
    if (!isValid(string, size)) {
        std::cerr << "Not valid string !!!" << std::endl;
        return -1;
    }

    /* Get arithmetic operations result and show */
    std::cout << string << " = " << getStringAnswer(string, size) << std::endl;
    delete [] string;
    return 0;
}

/*
* If the charecter is arithmetic operation, result is integer number priority
* If it doesn't operation -> result is 0(false)
*/
int getPriority(char op) {
    switch (op) {
    case '(':
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        return 0;
    }
}

/* Check is the charecter mark(0 - 9) */
bool isNumber(char a) {
    if (a  < '0' || a > '9') {
        return false;
    }
    return true;
}

/* Get answer for operation of 2 numbers */
int getAnswer(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
    }
}

/* Check is string valid */
bool isValid(char* string, int size) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (string[i] == '(') {
            ++count;
        } else if (string[i] == ')') {
            --count;
        }

        if (string[i] == ' ') {
            return false;
        }

        if (count < 0) {
            return 0;
        }
    }

    if (count != 0) {
        return false;
    }

    for (int i = 1; i < size; ++i) {
        if (getPriority(string[i]) > 1 && getPriority(string[i - 1]) > 1) {
            return false;
        }
    }

    int i = 1;
    while (i < size) {
        while (string[i] == '(' || string[i] == ')' && i < size) {
            ++i;
        }

        if (string[i - 1] == '(' && !isNumber(string[i])  && i < size) {
            return false;
        }

        if (string[i - 1] == ')'  && i < size && !getPriority(string[i])) {
            return false;
        }

        ++i;
    }

    return true;
}

/* Remove all spaces from string */
char* deleteSpaces(char* string, int size) {
    char* newString = new char[size];
    for (int i = 0, j = 0; i < size; ++i) {
        if (string[i] != ' ') {
            newString[j++] = string[i];
        }
    }

    return newString;
}

/* Calculate string charecter's count */
int getStringSize(char* string) {
    int size = 0;
    while (string[size] != '\0') {
        ++size;
    }
    return size;
}

int getStringAnswer(char* string, int size) {
    /* Stack for numbers */
    std::stack<int> num;
    /* Stack for operators */
    std::stack<char> oper;
    /* Arithmetic operations result */
    int answer = 0;

    /* While not end of the string */
    for (int i = 0; i < size; ++i) {
        /* If current charecter is numeric */
        if (isNumber(string[i])) {
            int number = 0;
            /* While next charecter is numeric, create new number */
            while (i < size && isNumber(string[i])) {
                number = (number * 10) + (string[i++] - (int)'0');
            }
            --i;
            num.push(number);
        /* If current charecter is operator and doesn't -> )*/
        } else if (getPriority(string[i]) && string[i] != ')') {
            /* If operator's stack is not empty, and new operator priority low/equal then/to previouse */
            if (!oper.empty() && getPriority(string[i]) <= getPriority(oper.top())) {
                /*
                * While number stack has at least 2 elements
                * and operator doesn't -> (
                * and operator priority low/equal then/to previouse
                */
                while (num.size() > 1 &&  oper.top() != '(' && getPriority(string[i]) <= getPriority(oper.top())) {
                    int number = num.top();
                    num.pop();
                    int answer = getAnswer(num.top(), number, oper.top());
                    oper.pop();
                    num.pop();
                    num.push(answer);
                }
                oper.push(string[i]);
            } else {
                oper.push(string[i]);
            }
        /* If current charecter is -> ) */
        } else if (string[i] == ')') {
            /* while operator doesn't -> (, do all operations, and push answer in number stack */
            while (oper.top() != '(' && !oper.empty() && num.size() > 1) {
                int number = num.top();
                num.pop();
                int answer = getAnswer(num.top(), number, oper.top());
                oper.pop();
                num.pop();
                num.push(answer);
            }
            oper.pop();
        }
    }

    /* Do all operations in stack */
    while (!oper.empty() && num.size() > 1) {
        int number = num.top();
        num.pop();
        int second = num.top();
        char op = oper.top();
        int answer = getAnswer(second, number, op);
        oper.pop();
        num.pop();
        num.push(answer);
    }

    return num.top();
    }