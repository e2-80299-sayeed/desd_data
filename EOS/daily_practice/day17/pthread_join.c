#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

#define SIZE 5

void* array_sum(void *param)
{
    int *arr = (int *)param;
    int i, *sum;
    
    sum = (int*)malloc(sizeof(int));
    if(sum == NULL )
    {
        perror("malloc() failed\n");
        _exit(1);
    }
    *sum = 0;
    for(i = 0; i < SIZE; i++)
    {
        *sum = *sum + arr[i];
        printf("adding %d....\n",arr[i]);
        sleep(1);
    }
    pthread_exit(sum);// this can be used to return values from thread functions.
    //return sum;
}


int main()
{
    int ret, arr[SIZE] = {11, 22 ,33, 44, 55};  
    int *result;
    pthread_t th;

    ret = pthread_create(&th, NULL, array_sum,arr);
    if(ret < 0)
    {
        perror("pthread_create() failed!!\n");
        _exit(1);
    }
    printf("main: waiting for thread to complete....\n");

    ret = pthread_join(th, (void **)&result);// calling threads waits for given thread
    if(ret != 0)
    {
        perror("pthread_join() failed!\n");
        _exit(1);
    }
    
    printf("result: %d\n", *result);
    free(result);

    return 0;
}