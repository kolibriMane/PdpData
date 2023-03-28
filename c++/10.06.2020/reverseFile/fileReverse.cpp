#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <bits/stdc++.h>

/* Definition of functions */
char* reverse(char*, int);
void swap(char&, char&);

int main() {
    /* Open the file on read mode, that will be reverse */
    std::fstream file;
    file.open("reverse", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "File can't open, make the file 'reverse'!" << std::endl;
        return -1;
    }

    /* Remove old file, if it existing */
    std::remove("newFile");

    std::string buffer = "";
    while (!file.eof()) {
        /* Read 1 line from file */
        getline(file, buffer);

        /* Open usefull files */
        std::ofstream temp("temp");
        std::ifstream newFile("newFile");

        /* Cast string to char array */
        int length = buffer.length();
        char string[length + 1];
        strcpy(string, buffer.c_str());

        /* write one reversed line, and add newFile */
        temp << reverse(string, length) << std::endl;
        temp << newFile.rdbuf();

        /* Close opened files */
        temp.close();
        newFile.close();

        /* Move temp to newFile */
        std::remove("newFile");
        std::rename("temp","newFile");
    }

    return 0;
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