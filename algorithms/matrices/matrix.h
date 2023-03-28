#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>

/* Functions prototypes */
int getInteger(std::string);
int** createMatrix(int);
void showMatrix(int**, int);
int** getMul(int**, int**, int**, int);
void deleteMatrix(int**, int);
void initMatrix(int**, int);
int getSize();

#endif