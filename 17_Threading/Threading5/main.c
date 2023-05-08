#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <assert.h>

#define NUM_THREADS 10
#define NUM_ITERATIONS 100000
#define USE_MUTEX
#define EXPECTED_RESULT (NUM_THREADS * NUM_ITERATIONS)

int32_t global_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* function(void* args)
{
    const int32_t arg_i32 = *((int32_t*)args);

    printf("Argument: %d\n", arg_i32);

    int32_t *result = (int32_t *)malloc(sizeof(int32_t));
    *result = arg_i32 * 2;

    for (int32_t i = 0; i < NUM_ITERATIONS; i++)
    {
#ifdef USE_MUTEX
        pthread_mutex_lock(&mutex);
        // critical section
        global_counter++;
        pthread_mutex_unlock(&mutex);
#else
        global_counter++;
#endif
    }

    pthread_exit((void *)result);
}


int main()
{
    pthread_t threads[NUM_THREADS];
    int32_t inputs[NUM_THREADS];
    int32_t *results[NUM_THREADS];

    for (int32_t i = 0; i < NUM_THREADS; i++)
        inputs[i] = i;

    for (int32_t i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, &function, (void *)&inputs[i]);

    for (int32_t i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], (void *)&results[i]);

    for (int32_t i = 0; i < NUM_THREADS; i++)
        printf("Result: %d\n", *results[i]);

    printf("\nAnalysis:\n");
    printf("Counter should be: %d\n", EXPECTED_RESULT);
    printf("Counted          : %d\n", global_counter);
    printf("Parallel Counting: %d\n", EXPECTED_RESULT - global_counter);

    assert(EXPECTED_RESULT == global_counter);

    return 0;
}
