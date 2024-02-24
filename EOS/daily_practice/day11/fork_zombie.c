#include<stdio.h>
#include<unistd.h>

int main()
{
    int ret, i;
    printf("program started !\n");
    ret = fork();
    if(ret == 0)
     {
        //child
        for(i=1; i<=5; i++)
        {
            printf("child : %d\n",i);
            sleep(1);
        }
     }      
    else
    {
        for(i=1; i<=10; i++)
        {
            printf("parent : %d\n",i);
            sleep(1);
        }
    }
    printf("program completed!\n");
    return 0;
}
