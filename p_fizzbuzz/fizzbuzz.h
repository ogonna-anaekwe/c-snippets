#ifndef __fizzbuzz_h__
#define __fizzbuzz_h__

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MICROSECS 1000000 /* Number of microsecs in a sec */
#define THREAD_LIMIT 2000 /* Max number of threads per process. Why do larger numbers cause errors w/ duplicate thread ids? */

void *fizzbuzz(void *arg);

time_t timer(struct timeval *tp);

#endif // __fizzbuzz_h__