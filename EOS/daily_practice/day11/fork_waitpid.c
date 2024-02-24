#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int i, ret, s;
    printf("program started !!\n");
    ret = fork();
    if(ret == 0)
    {
        for(i=1; i<= 5; i++)
        {
            printf("child : %d\n",i);
            sleep(1);
        }
        _exit(3);
    }
    else
    {
        for(i=1; i<= 10; i++)
        {
            printf("parent : %d\n",i);
            sleep(1);
            if(i == 5)
            {
                waitpid(ret,&s,0);
                printf("child's exit status :%d\n",WEXITSTATUS(s));
            }
        }
    }
    printf("program completed\n");
    return 0;
}