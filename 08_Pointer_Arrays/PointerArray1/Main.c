#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length = 3;

    int *ptrArray = (int *)malloc(length * sizeof(int));

    for (unsigned int i = 0; i < length; i++)
    {
        ptrArray[i] = (int)(i);
    }

    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d\n", ptrArray[i]);
    }

    free(ptrArray);
    ptrArray = NULL;

    return 0;
}
