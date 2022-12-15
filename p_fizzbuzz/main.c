#include "fizzbuzz.h"

int main(int argc, char *argv[])
{
    struct timeval tp;
    time_t start_time = timer(&tp);

    if (argc != 3)
    {
        fprintf(stderr, "usage: ./fizzbuzz <num_threads> <nums_per_thread>. e.g. ./pfzbuzz 10 100000\n");
        exit(1);
    }

    int num_threads = atoi(argv[1]),
        nums_per_thread = atoi(argv[2]); /* How many numbers each thread computes fizzbuzz for. Tweak this number to make each thread handle more or less load */

    if (num_threads > THREAD_LIMIT)
    {
        fprintf(stderr, "Your thread choice %d exceeds the max number of threads available %d\n", num_threads, THREAD_LIMIT);
        exit(1);
    }

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, fizzbuzz, &nums_per_thread);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nrun time: %ldμs\n", timer(&tp) - start_time);

    return 0;
}