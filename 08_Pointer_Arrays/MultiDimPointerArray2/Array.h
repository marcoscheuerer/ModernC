#ifndef __ARRAY_H
#define __ARRAY_H

/**
 * @brief
 *
 * @param array
 * @param length
 */
void printArray(int *array, unsigned int length);

/**
 * @brief Create a Array object
 *
 * @param length
 * @param value
 * @return int*
 */
int* createArray(unsigned int length, int value);

/**
 * @brief
 *
 * @param ptrArray
 * @return int*
 */
int* freeArray(int* ptrArray);

#endif
