#include "matrix.h"
#include <sstream>
#include <cmath>

/* Get integer number for row or column, great then 0 */
int getInteger(std::string key) {
    int n = 0;
    std::cout << key;
    std::cin >> n;

    while (std::cin.fail() || n <= 0) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only integer number, great then 0!!!" << std::endl;
        std::cout << key;
        std::cin >> n;
    }

    return n;
}

bool isNotValid(int n) {
    if (0 == n || 1 == n) {
        return true;
    }

    if (0 == (n & (n - 1))) {
        return false;
    }

    return true;
}

int getSize() {
    int n = 0;
    std::cout << "Row & Column: ";
    std::cin >> n;

    while (std::cin.fail() || n <= 0 || isNotValid(n)) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cerr << "Warning:" << std::endl;
        std::cerr << "1. Enter only integer number !" << std::endl;
        std::cerr << "2. Number must be great then 0 !" << std::endl;
        std::cerr << "3. Number must be power of 2 !" << std::endl;
        std::cout << "Row & Column: ";
        std::cin >> n;
    }

    return n;
}

/* Create matrix with n rows and m columns */
int** createMatrix(int n) {
    /* Create matrix */
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }

    return a;
}

/* Initialize matrix with n rows and m columns */
void initMatrix(int** a, int n) {
    /* Initialize matrix */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::stringstream convert;
            convert << (i + 1);
            std::string index1 = convert.str();
            convert.str("");
            convert << (j + 1);
            std::string index2 = convert.str();
            std::string key = "[" + index1 + " " + index2 + "]: ";
            a[i][j] = getInteger(key);
        }
    }
}

/* Print the matrix pretty */
void showMatrix(int** a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* free matrix memory by name and size */
void deleteMatrix(int** a, int n) {
    for (int i = 0; i < n; ++i) {
        delete [] a[i];
    }

    delete [] a;
}

/* Multiply two matrices */
int** getMul(int** x, int** y, int** z, int n) {
    if (n != 2) {
        int size = n / 2;
        int** a1 = createMatrix(size);
        int** b1 = createMatrix(size);
        int** c1 = createMatrix(size);
        int** d1 = createMatrix(size);

        int** a2 = createMatrix(size);
        int** b2 = createMatrix(size);
        int** c2 = createMatrix(size);
        int** d2 = createMatrix(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                a1[i][j] = x[i][j];
                a2[i][j] = y[i][j];
                b1[i][j] = x[i][size + j];
                b2[i][j] = y[i][size + j];
                c1[i][j] = x[size + i][j];
                c2[i][j] = y[size + i][j];
                d1[i][j] = x[size + i][size + j];
                d2[i][j] = y[size + i][size + j];
            }
        }

        int** z1 = createMatrix(size);
        z1 = getMul(a1, a2, z1, size);
        int** z2 = createMatrix(size);
        z2 = getMul(b1, b2, z2, size);
        int** z3 = createMatrix(size);
        z3 = getMul(c1, c2, z3, size);
        int** z4 = createMatrix(size);
        z4 = getMul(d1, d2, z4, size);

        z = createMatrix(n);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                z[i][j] = z1[i][j];
                z[i + size][j] = z3[i][j];
                z[i][j + size] = z2[i][j];
                z[i + size][j + size] = z4[i][j];
            }
        }

        return z;
    } else {
        int p1 = (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
        int p2 = (x[1][0] + x[1][1]) * y[0][0];

        int p3 = x[0][0] * (y[0][1] - y[1][1]);
        int p4 = x[1][1] * (y[1][0] - y[0][0]);

        int p5 = (x[0][0] + x[0][1]) * y[1][1];
        int p6 = (x[1][0] - x[0][0]) * (y[0][0] + y[0][1]);

        int p7 = (x[0][1] - x[1][1]) * (y[1][0] + y[1][1]);

        z[0][0] = p1 + p4 - p5 + p7;
        z[1][0] = p2 + p4;
        z[0][1] = p3 + p5;
        z[1][1] = p1 - p2 + p3 + p6;

        return z;
    }
}