#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

std::string encryptOrDecryptLine(int, std::string, char *);
int normalizeKey(char*);
bool isInvalidArgs(int, char**);

/* Get 3 arguments key, one of {encrypt, decrypt}, file name */
int main(int argc, char* argv[]) {
    if (isInvalidArgs(argc, argv)) {
        return -1;
    }
    std::remove("newFile");

    int key = normalizeKey(argv[1]);
    /* Open file in read mode */
    std::ifstream file;
    file.open(argv[3], std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Can't open the file" << std::endl;
        return -1;
    }

    /* Open file in write mode */
    std::ofstream newFile;
    newFile.open("newFile", std::ios::out);

    std::string buffer = "";
    while (getline(file, buffer)) {
        newFile << encryptOrDecryptLine(key, buffer, argv[2]) << std::endl;
    }
    return 0;
}

std::string encryptOrDecryptLine(int key, std::string buffer, char *what) {
    int size = buffer.length();
    if (0 == strcmp(what, "decrypt")) {
        key *= -1;
    }
    for (int i = 0; i < size; ++i) {
        buffer[i] = buffer[i] + key;
    }

    return buffer;
}

/* Get key from 0 to 25 */
int normalizeKey(char* k) {
    /* Cast string to integer number */
    int key = atoi(k);
    if (key > 25) {
        int temp = key / 25;
        key = key - temp * 25;
    } else if (key < 0) {
        int temp = key / 25;
        key = - (key + 25);
    }

    return key;
}

/* Check is main arguments valid */
bool isInvalidArgs(int count, char* arguments[]) {
    if (4 != count || (0 != strcmp(arguments[2], "encrypt") && 0 != strcmp(arguments[2], "decrypt"))) {
        std::cerr << "Not valid arguments!" << std::endl;
        return true;
    }
    return false;
}