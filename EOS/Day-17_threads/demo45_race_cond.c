#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void* inc_count(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        count++;
        printf("incr count: %d\n", count);
        sleep(1);
    }
    return NULL;
}

void* dec_count(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        count--;
        printf("decr count: %d\n", count);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t it, dt;
    int ret;
    ret = pthread_create(&it, NULL, inc_count, NULL);
    ret = pthread_create(&dt, NULL, dec_count, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", count);
    return 0;
}

