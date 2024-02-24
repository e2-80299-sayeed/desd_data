#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret, err, s;
    printf("parent started !\n");
    ret = fork();
    if(ret == 0)
    {
        err = execl("/usr/bin/firefox","firefox","https://google.com",NULL);
        if(err < 0)
        {
            perror("exec() failed\n");
            _exit(1);
        }
    }else{
        wait(&s);
        printf("child exit status: %d\n",WEXITSTATUS(s));
    }
    printf("parent completed!\n");
    return 0;
}