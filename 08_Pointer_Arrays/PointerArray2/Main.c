#include <stdio.h>
#include <stdlib.h>

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

int* freeArray(int *array)
{
    if (array != NULL)
    {
        free(array);
    }

    return NULL;
}

int main()
{
    int length = 3;

    int *ptrArray = createArray(length, 0);

    for (unsigned int i = 0; i < length; i++)
        printf("%d\n", ptrArray[i]);

    ptrArray = freeArray(ptrArray);

    return 0;
}
