#include "fizzbuzz.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int start = 0;
int end = 0;

/**
 * Computes the fizzbuzz test for a given number.
 * @param arg voidable. However, in this case, we pass the generic range of numbers each thread processes. This range is the same for all threads.
 * @return void*
 */
void *
fizzbuzz(void *arg)
{
    const int range = *(int *)arg;

    pthread_mutex_lock(&lock);
    start = 1 + (end - 1);
    end = start + range;

    bool div_by_3 = false,
         div_by_5 = false,
         div_by_3_5 = false;

    for (int i = start; i <= end; i++)
    {
        div_by_3 = i % 3 == 0;
        div_by_5 = i % 5 == 0;
        div_by_3_5 = (i % 3 == 0) && (i % 5 == 0);

        if (div_by_3_5)
        {
            printf("%d: %s\n", i, "FizzBuzz");
        }
        else if (div_by_3)
        {
            printf("%d: %s\n", i, "Fizz");
        }
        else if (div_by_5)
        {
            printf("%d: %s\n", i, "Buzz");
        }
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

/**
 * Computes/Returns the time in microsecs.
 * @param *tp Pointer to a timeval struct.
 * @return time_t - Time in microsecs.
 */
time_t timer(struct timeval *tp)
{
    gettimeofday(tp, NULL);
    return ((tp->tv_sec) * MICROSECS) + ((tp->tv_usec));
}