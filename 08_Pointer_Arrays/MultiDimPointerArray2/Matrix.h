#ifndef __MATRIX_H
#define __MATRIX_H

/**
 * @brief Create a Matrix object
 *
 * @param num_rows
 * @param num_cols
 * @param value
 * @return int**
 */
int** createMatrix(unsigned int num_rows, unsigned int num_cols, int value);

/**
 * @brief
 *
 * @param matrix
 * @param num_rows
 * @param num_cols
 */
void printMatrix(int **matrix, unsigned int num_rows, unsigned int num_cols);

/**
 * @brief
 *
 * @param matrix
 * @param num_rows
 * @return int**
 */
int **freeMatrix(int **matrix, unsigned int num_rows);

#endif
