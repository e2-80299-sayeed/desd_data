#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

//create a thread function 
void *thread_func(void *param)
{
    int i;
    for(i=1 ; i<=10; i++)
    {
        printf("thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    int i, ret;
    pthread_t th;

    ret = pthread_create(&th, NULL, thread_func, NULL);
    if(ret < 0)
    {
        perror("pthread_create() failed\n");
        _exit(1);
    }
    for(i=1 ; i<=10; i++)
    {
        printf("main: %d\n", i);
        sleep(1);
    }

}