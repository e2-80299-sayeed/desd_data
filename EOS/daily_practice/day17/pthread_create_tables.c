#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * print_table(void *param)
{
    long i, num = (long) param;
    for(i=1; i<=10; i++)
    {
        printf("%ld * %ld = %ld\n",num, i, num * i);
        sleep(1);
    }
    return NULL;

}


int main()
{
    pthread_t t1, t2, t3;
    int ret;
    long num;
    
    ret = pthread_create(&t1, NULL, print_table, (void*)5L);
    if(ret != 0)
    {
        perror("pthread_create() failed !!\n");
        _exit(1);
    }
    
    ret = pthread_create(&t2, NULL, print_table, (void*)6L);
    if(ret != 0)
    {
        perror("pthread_create() failed !!\n");
        _exit(1);
    }

    ret = pthread_create(&t3, NULL, print_table, (void*)8L);
    if(ret != 0)
    {
        perror("pthread_create() failed !!\n");
        _exit(1);
    }

    printf("main: press enter to exit......\n");
    getchar();
    return 0;   
}