#include <stdio.h>
#include <stdlib.h>

int** createMatrix(unsigned int num_rows, unsigned int num_cols, int value);
int* createArray(unsigned int length, int value);
int* freeArray(int* ptrArray);

int main()
{
    unsigned int length = 5;

    int *ptrArray = createArray(length, 0);

    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d ", ptrArray[i]);
    }
    printf("\n");

    freeArray(ptrArray);

    const int ROWS = 2;
    const int COLS = 3;
    const int INIT_VAL = 1;

    int **matrix = createMatrix(ROWS, COLS, INIT_VAL);

    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLS; j++)
            printf("%d\n", matrix[i][j]);
    }

    return 0;
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

int* createArray(unsigned int length, int value)
{
    int *ptrArray = (int *)malloc(length * sizeof(int));

    if (ptrArray == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < length; i++)
    {
        ptrArray[i] = value;
    }

    return ptrArray;
}

int* freeArray(int* ptrArray)
{
    if (ptrArray != 0)
        free(ptrArray);

    return NULL;
}
