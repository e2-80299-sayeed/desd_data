// 1. In ﬁrst thread, print "SUNBEAM" and in second thread print "INFOTECH". Use "semaphore" to ensure that INFOTECH is printed only after SUNBEAM.

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h> 

sem_t s;

void* sunbeam(void * ptr)
{   
    
    char* str = "SUNBEAM \n";
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
        fflush(stdout);
        sleep(1);
    }
    sem_post(&s);
    return NULL;
}

void* infotech(void * ptr)
{
    sem_wait(&s);
    char*str = "INFOTECH \n";
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}


int main()
{   
    pthread_t st , it;
    
    sem_init(&s,0,0);
    pthread_create(&st, NULL,sunbeam,NULL);
    pthread_create(&it, NULL,infotech,NULL);

    pthread_join(st,NULL);
    pthread_join(it,NULL);

    sem_destroy(&s);

    return 0;
}