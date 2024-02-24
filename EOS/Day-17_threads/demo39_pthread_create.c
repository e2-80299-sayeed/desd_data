#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* incr_thread_func(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("inc thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void* decr_thread_func(void *param) {
    int i;
    for(i=10; i>=1; i--) {
        printf("dec thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i, ret;
    pthread_t it, dt;
    ret = pthread_create(&it, NULL, incr_thread_func, NULL);
    ret = pthread_create(&dt, NULL, decr_thread_func, NULL);
    printf("main: press enter to exit...\n");
    getchar();
    return 0;
}


