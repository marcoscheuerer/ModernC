#include <stdio.h>
#include <pthread.h>

void* function(void *args)
{
    // use parameter dummy-like because of warning
    (void)args;

    // returns thread that called the function
    const pthread_t this_thread = pthread_self();

    printf("Called from thread: %u\n", (unsigned int)this_thread);

    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, &function, NULL);
    pthread_create(&thread2, NULL, &function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
