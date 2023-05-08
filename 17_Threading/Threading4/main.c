#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

#define NUM_THREADS 3

void* function(void *args)
{
    //const pthread_t this_thread = pthread_self();
    //printf("Called from thread %u\n", (uint32_t)this_thread);

    const int32_t arg_i32 = *((int *)args);

    printf("Argument: %d\n", arg_i32);

    int *result = (int *)malloc(sizeof(int));
    *result = arg_i32 * 2;

    pthread_exit((void *)result);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int32_t inputs[NUM_THREADS];
    int32_t *results[NUM_THREADS];

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        inputs[i] = i;
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, &function, (void *)(&inputs[i]));
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], (void *)&results[i]);
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        printf("Result %d: %d\n", i, *results[i]);
    }

    return 0;
}
