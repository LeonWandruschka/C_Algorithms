#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <pthread.h>

void *ThreadFunction(void * args)
{
    (void)args;

    const pthread_t this_thread = pthread_self();

    printf("Thread: %d\n",(int)this_thread);

    return NULL;
}

int ThreadCall()
{
    pthread_t thread_one;
    pthread_t thread_two;

    pthread_create(&thread_one,NULL,&ThreadFunction,NULL);
    pthread_create(&thread_two,NULL,&ThreadFunction,NULL);

    pthread_join(thread_one,NULL);
    pthread_join(thread_two,NULL);



    return 0;
}
