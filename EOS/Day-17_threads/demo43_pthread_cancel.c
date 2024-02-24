#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
    ret = pthread_create(&th, NULL, thread_func, NULL);
    if(ret < 0) {
        perror("pthread_create() failed");
        _exit(1);
    }
    
    printf("main: press enter to cancel the thread...\n");
    getchar();
    pthread_cancel(th);

    printf("main: press enter to exit...");
    getchar();
    return 0;
}


