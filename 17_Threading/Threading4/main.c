#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

#define NUM_THREADS 3

void* function(void *args)
{
    const pthread_t this_thread = pthread_self();

    printf("Called from thread %u\n", (uint32_t)this_thread);

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int32_t inputs[NUM_THREADS];

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        inputs[i] = i;
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, (void *)(&inputs[i]), NULL);
    }

    pthread_t thread1;
    pthread_t thread2;

    int32_t num1 = 2;
    int32_t num2 = 3;

    pthread_create(&thread1, NULL, &function, NULL);
    pthread_create(&thread2, NULL, &function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
