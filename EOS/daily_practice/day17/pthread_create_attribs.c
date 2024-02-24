#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void* thread_func(void * param)
{
    int i;
    for(i = 1; i<= 10; i++)
    {
        printf("thread: %d\n",i);
        sleep(5);
    }
    return 0;
}



int main()
{
    int i, ret;
    pthread_t th;
    pthread_attr_t th_attr;
    
    pthread_attr_init(&th_attr);

    pthread_attr_setstacksize(&th_attr, 100 *1024);

    pthread_attr_setguardsize(&th_attr, 8 * 1024 );

    ret = pthread_create(&th, &th_attr, thread_func, NULL);
    if(ret < 0)
    {
        perror("pthread_create() failed\n");
        _exit(1);
    }

    for(i = 1; i<=12; i++)
    {
        printf("main: %d\n",i);
        sleep(5);
    }
    pthread_attr_destroy(&th_attr);
    return 0;
}