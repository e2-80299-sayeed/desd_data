#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t m; // declare mutex
int count = 0;

void* inc_count(void *param) {
    int i;
    for(i=1; i<=100000; i++) {
        pthread_mutex_lock(&m); // lock mutex
        count++;
        printf("incr count: %d\n", count);
        pthread_mutex_unlock(&m); // unlock mutex
        //sleep(1);
    }
    return NULL;
}

void* dec_count(void *param) {
    int i;
    for(i=1; i<=100000; i++) {
        pthread_mutex_lock(&m); // lock mutex
        count--;
        printf("decr count: %d\n", count);
        pthread_mutex_unlock(&m); // unlock mutex
        //sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t it, dt;
    int ret;
    pthread_mutex_init(&m, NULL); // init mutex
    ret = pthread_create(&it, NULL, inc_count, NULL);
    ret = pthread_create(&dt, NULL, dec_count, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", count);
    pthread_mutex_destroy(&m); // destroy mutex
    return 0;
}

