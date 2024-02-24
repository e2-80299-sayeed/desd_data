#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 5

void* array_sum(void *param) {
    int *arr = (int*)param;
    int i, *sum;
    sum = (int*)malloc(sizeof(int));
    *sum = 0;
    for(i=0; i<SIZE; i++) {
        *sum = *sum + arr[i];
        printf("adding %d ...\n", arr[i]);
        sleep(1);
    }
    pthread_exit(sum);
    //return sum;
}

int main() {
    int ret, arr[SIZE] = { 11, 22, 33, 44, 55 };
    int *result;
    pthread_t th;
    ret = pthread_create(&th, NULL, array_sum, arr);
    printf("main: waiting for thread to complete...\n");
    pthread_join(th, (void**)&result); // calling threads waits for given thread
    printf("result: %d\n", *result);
    free(result);
    return 0;
}
