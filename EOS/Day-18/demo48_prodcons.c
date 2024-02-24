#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 5
typedef struct cirque {
    int arr[MAX];
    int front, rear, count;
} cirque_t;

void cq_init(cirque_t *cq) {
    cq->front = -1;
    cq->rear = -1;
    cq->count = 0;
    memset(cq->arr, 0, sizeof(cq->arr));
}

void cq_push(cirque_t *cq, int val) {
    cq->rear = (cq->rear + 1) % MAX;
    cq->arr[cq->rear] = val;
    cq->count++;
}

int cq_pop(cirque_t *cq) {
    int val;
    cq->front = (cq->front + 1) % MAX;
    val = cq->arr[cq->front];
    cq->count--;
    return val;
}

int cq_is_empty(cirque_t *cq) {
    return cq->count == 0;
}

int cq_is_full(cirque_t *cq) {
    return cq->count == MAX;
}

cirque_t cq;
sem_t sf, se;
pthread_mutex_t m;

void* producer(void *param) {
    int val;
    //sleep(5);
    while(1) {
        sem_wait(&se);  // P(se);
        pthread_mutex_lock(&m); // lock(m);
        val = rand() % 100;
        cq_push(&cq, val);
        printf("WR: %d\n", val);
        pthread_mutex_unlock(&m); // unlock(m);
        sem_post(&sf); // V(sf);
        sleep(1);
    }
    return NULL;
}

void* consumer(void *param) {
    int val;
    //sleep(10);
    while(1) {
        sem_wait(&sf); // P(sf);
        pthread_mutex_lock(&m); // lock(m);
        val = cq_pop(&cq);
        printf("RD: %d\n", val);
        pthread_mutex_unlock(&m); // unlock(m);
        sem_post(&se); // V(se);
        sleep(1);
    }
    return NULL;    
}

int main() {
    pthread_t pt, ct;
    //sf=0, se=MAX, m=1
    pthread_mutex_init(&m, NULL);
    sem_init(&sf, 0, 0);
    sem_init(&se, 0, MAX);
    pthread_create(&pt, NULL, producer, NULL);
    pthread_create(&ct, NULL, consumer, NULL);
    printf("press enter to exit...\n");
    getchar();
    sem_destroy(&se);
    sem_destroy(&sf);
    pthread_mutex_destroy(&m);
    return 0;
}
