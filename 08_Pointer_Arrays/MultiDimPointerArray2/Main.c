#include <stdio.h>
#include <stdlib.h>

#include "Array.h"
#include "Matrix.h"

int main()
{
    unsigned int length = 5;

    int *ptrArray = createArray(length, 0);

    printArray(ptrArray, length);
    printf("\n");

    freeArray(ptrArray);

    const int ROWS = 6;
    const int COLS = 5;
    const int INIT_VAL = 1;

    int **matrix = createMatrix(ROWS, COLS, INIT_VAL);

    printMatrix(matrix, ROWS, COLS);
    printf("\n");

    return 0;
}

