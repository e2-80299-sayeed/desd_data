#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// step 1. create a thread function (i.e. function to be executed by the thread)
void* thread_func(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i, ret;
    pthread_t th;
    // step 2. create a thread
    ret = pthread_create(&th, // POSIX Thread ID -- Out param
                    NULL, // Thread Attrs -- stack size, priority, sched algo, etc
                    thread_func, // Addr of fn to be executed by thread
                    NULL); // Arg to the thread fn.   
    if(ret < 0) {
        perror("pthread_create() failed");
        _exit(1);
    }
    for(i=1; i<=10; i++) {
        printf("main: %d\n", i);
        sleep(1);
    }
    return 0;
}


