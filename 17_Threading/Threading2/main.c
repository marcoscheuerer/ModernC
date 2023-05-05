#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

// Struct for more threading arguments
typedef struct
{
    int32_t num1;
    int32_t num2;
} argsStruct;

void* functionOneArg(void *args)
{
    const int32_t input = *((int32_t*)args);

    printf("Argument: %d\n", input);

    return NULL;
}

void* functionMoreArgs(void *args)
{
    argsStruct myStruct = *((argsStruct*)args);

    printf("Argument 1: %d, Argument 2: %d\n", myStruct.num1, myStruct.num2);

    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    int32_t input1 = 1;
    int32_t input2 = 2;
    argsStruct myStruct = {21, 85};

    pthread_create(&thread1, NULL, &functionOneArg, (void *)&input1);
    pthread_create(&thread2, NULL, &functionOneArg, (void *)&input2);
    // Argument struct for more arguments
    pthread_create(&thread3, NULL, &functionMoreArgs, (void *)&myStruct);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
