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
    pthread_attr_t th_attr;
    pthread_attr_init(&th_attr); // initialize all thread attrs to default values.
    pthread_attr_setstacksize(&th_attr, 100 * 1024); // stack of 100 kb
    pthread_attr_setguardsize(&th_attr, 8 * 1024); // stack guard of 8 kb
    // step 2. create a thread
    ret = pthread_create(&th, &th_attr, thread_func, NULL);    
    if(ret < 0) {
        perror("pthread_create() failed");
        _exit(1);
    }
    for(i=1; i<=12; i++) {
        printf("main: %d\n", i);
        sleep(1);
    }
    pthread_attr_destroy(&th_attr); // destroy thread attrs
    return 0;
}


