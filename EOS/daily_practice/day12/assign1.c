#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    int i = 1,sign;
    pid_t pid; 
    printf("Enter the signal number :");
    scanf("%d",&sign);
    printf("Enter the pid : ");
    scanf("%d",&pid);
    kill(pid,sign);
    
    while(1)
    {
        printf("running:%d\n",i++);
        sleep(1);
    }
    return 0;
}