#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define UB (1 << 19)
#define NUM_THREADS (1 << 4)
#define THREAD_SAFE 1

struct count_t
{
    pthread_mutex_t lock;
    int count;
};

struct count_t counter = {.lock = PTHREAD_MUTEX_INITIALIZER, .count = 0};

void *inc_thread_safe(void *arg)
{
    int thread_num = *(int *)arg;
    for (int i = 0; i < UB; i++)
    {
        pthread_mutex_lock(&(counter.lock));
        printf("Counting from thread %d. Current count: %d\n", thread_num, counter.count);
        counter.count++; // sandwiched by mutex to sync threads and prevent race conditions.
        pthread_mutex_unlock(&(counter.lock));
    }

    return NULL;
}

void *inc(void *arg)
{
    for (int i = 0; i < UB; i++)
        counter.count++;

    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int return_value;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        if (THREAD_SAFE)
        {
            return_value = pthread_create(&threads[i], NULL, inc_thread_safe, &i); // no race conditions
        }
        else
        {
            return_value = pthread_create(&threads[i], NULL, inc, &i); // will result in race conditions
        }

        if (return_value != 0)
        {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        return_value = pthread_join(threads[i], NULL);
        if (return_value != 0)
        {
            fprintf(stderr, "Error waiting for thread %d\n", i);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d completed\n", i);
    }

    int expected_count = UB * NUM_THREADS;
    int actual_count = counter.count;
    printf("[Expected] %d - [Actual]%d: %d\n", expected_count, actual_count, expected_count - actual_count);
}