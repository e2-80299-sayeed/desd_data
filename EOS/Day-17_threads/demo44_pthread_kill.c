#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("signal caught! sig=%d, pid=%d, tid=%d\n", sig, getpid(), gettid());
    if(gettid() != getpid())    // if current thread is not the main thread,
        pthread_exit(NULL);     // terminate the thread.
}

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
    struct sigaction sa;

    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigint_handler;
    ret = sigaction(SIGINT, &sa, NULL);

    ret = pthread_create(&th, NULL, thread_func, NULL);
    if(ret < 0) {
        perror("pthread_create() failed");
        _exit(1);
    }
    
    printf("main: press enter to send signal to the thread...\n");
    getchar();
    pthread_kill(th, SIGINT);

    printf("main: press enter to exit...\n");
    getchar();
    return 0;
}


