#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

// Struct for more threading arguments
typedef struct
{
    int32_t num1;
    int32_t num2;
    int32_t result;
} argsStruct;

void* functionOneArg(void *args)
{
    const int32_t input = *((int32_t*)args);

    printf("Argument: %d\n", input);

    // dynamic reserved at heap because if is static reserved the
    // variable won't exist after leaving the function
    int *result = (int *)malloc(sizeof(int));
    *result = input * 2;

    pthread_exit((void *)(result));
}

void* functionMoreArgs(void *args)
{
    argsStruct myStruct = *((argsStruct*)args);

    printf("Argument 1: %d, Argument 2: %d\n", myStruct.num1, myStruct.num2);

    argsStruct *result = (argsStruct *)malloc(sizeof(argsStruct));

    printf("--> %d\n", myStruct.num1 * myStruct.num2);
    result->result = myStruct.num1 * myStruct.num2;

    pthread_exit((void *)result);
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    int32_t *result1;
    int32_t *result2;
    argsStruct *result3;

    int32_t input1 = 1;
    int32_t input2 = 2;
    argsStruct myStruct = {2, 3};

    pthread_create(&thread1, NULL, &functionOneArg, (void *)&input1);
    pthread_create(&thread2, NULL, &functionOneArg, (void *)&input2);
    // Argument struct for more arguments
    pthread_create(&thread3, NULL, &functionMoreArgs, (void *)&myStruct);

    pthread_join(thread1, (void *)(&result1));
    pthread_join(thread2, (void *)(&result2));
    pthread_join(thread3, (void *)(&result3));

    printf("Result 1: %d\n", *result1);
    printf("Result 2: %d\n", *result2);
    printf("Result 3: %d\n", result3->result);

    return 0;
}
