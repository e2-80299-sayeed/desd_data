#define _GNU_SOURCE
#include <sched.h>
#include<unistd.h>
#include<stdio.h>   
#include<stdlib.h>

int thread_func(void *param)
{
 int i;
 for(i =1 ; i<=10; i++)
 {
    printf("thread: %d\n",i);
    sleep(1);
 }   
 return 0;
}

int main()
{
    int i, tid, stack_size;
    void *stack;

    stack_size = 100 * 1024;
    stack = malloc(stack_size);

    tid = clone(thread_func, stack + stack_size,CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND,NULL);
    if(tid < 0)
    {
        perror("clone () failed");
        _exit(1);
    }
    printf("child id : %d\n", tid);

    for(i =1 ; i<=10; i++)
 {
    printf("main: %d\n",i);
    sleep(1);
 }   
 
    return 0;   
}