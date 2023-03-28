#include "func.h"

int find(std::string str1, std::string str2, int i, int k) {
    int size1 = str1.length();
    int size2 = str2.length();

    while (k < size2 && str1[i] != str2[k]) {
        ++k;
    }

    if (k < size2 && str1[i] == str2[k]) {
        return k;
    }

    return -1;

}

std::string stringDiff(std::string str1, std::string str2) {
    if (0 == str1.compare(str2)) {
        return str1;
    }

    /* Get sizes for 2 strings */
    int size1 = str1.length();
    int size2 = str2.length();

    /* Index for first string */
    int i = 0;
    /* Index for second string */
    int k = 0;

    std::string newStr = "";
    while (i < size1 && k < size2) {
        if (str1[i] == str2[k]) {
            newStr += str1[i++];
            ++k;
        } else {
            int index = find(str1, str2, i, k);
            if (-1 != index) {
                while (k < size2 && k < index) {
                    newStr += "+";
                    newStr += str2[k++];
                }
                newStr += str1[i++];
            } else {
                if (i < size1) {
                    newStr += "-";
                    newStr += str1[i++];
                }

                while (k < size2 && str1[i] != str2[k]) {
                    newStr += "+";
                    newStr += str2[k++];
                }
            }
        }
    }

    while (i < size1) {
        newStr += "-";
        newStr += str1[i++];
    }

    while (k < size2) {
        newStr += "+";
        newStr += str2[k++];
    }

    return newStr;
}