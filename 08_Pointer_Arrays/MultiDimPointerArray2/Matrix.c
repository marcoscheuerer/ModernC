#include "Matrix.h"
#include "Array.h"

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, unsigned int num_rows, unsigned int num_cols)
{
    if (matrix == NULL)
        return;

    printf("[ ");
    for (unsigned int i = 0; i < num_rows; i++)
    {
        printArray(matrix[i], num_cols);

        if (i < num_rows - 1)
            printf("\n  ");
    }
    printf(" ]");
}

int** createMatrix(unsigned int num_rows, unsigned int num_cols, int value)
{
    int **matrix = (int **)malloc(num_rows * sizeof(int *));

    for (unsigned int i = 0; i < num_rows; i++)
    {
        //r[i] = (int *)malloc(num_cols * sizeof(int));
        matrix[i] = createArray(num_cols, 0);
    }

    return matrix;
}

int **freeMatrix(int **matrix, unsigned int num_rows)
{
    // important: order of freeing memory, first pointer to cols, then pointer to rows
    for (unsigned int i = 0; i < num_rows; i++)
        matrix[i] = freeArray(matrix[i]);

    free(matrix);

    return NULL;
}
