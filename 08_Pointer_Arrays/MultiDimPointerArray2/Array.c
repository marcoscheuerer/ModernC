#include "Array.h"

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, unsigned int length)
{
    if (array == NULL)
        return;

    printf("[ ");
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d", array[i]);

        if (i < length - 1)
            printf(", ");
    }
    printf(" ]");
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
