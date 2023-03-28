#ifndef ARRAY_H
#define ARRAY_H

/**
 * @file array.h - Array class description file (header file)
 * @mainpage Arrays — this is a project about array, and how to print it
 * @version 1.1.5v
 * @author Mane Antonyan
 * @note for instigate mobile
 **/

#include <iostream>
/**
 * @class Array - has only function member
 * @todo Add to class another function that will be print array sorted
 * @todo Add to class another function that will be print array every element in new line
*/
class Array {
    public:
        /**
         * @brief Show array petty
         * @param array - array that will be printed
         * @param length - size of array
         * @return true if array size is great then 0, else return false
         * @todo Add to function case- if array doesn't have elements then print about
         * @throw ShowArray - throw error when size less then 0
         * @exception throw error when size less then 0
         * @warning — If you uses this function, you must be use try-catch !!!
        */
        bool showArray(int* array, int length);

        /**
         * @brief Show array petty if it possible
         * @param array - array that will be printed
         * @param length - size of array
         * @deprecated ShowArray - old version. Be careful in use
        */
        void showArrayOld(int* array, int length);

        /**
         * @private size element don't show in documentation
         **/
        int size;
};

#endif