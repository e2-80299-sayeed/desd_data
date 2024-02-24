// 1. Execute "wc" command from your program (using fork() + exec()). The command should read data from the ﬁle "in.txt" (instead of terminal) and output
// should be displayed on terminal.

#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
    //child
        
    int ret, err, fd, s;

    ret = fork();
    if(ret == 0)
    {    fd = open("in.txt",O_RDONLY,0664);
        dup2(fd,0);
        close(fd);

        err = execlp("wc","wc",NULL);
        if(err < 0)
        {
            perror("exec() failed !!");
            _exit(1);
        }
    }
    else 
    waitpid(ret, &s, 0);

    printf("program completed.\n");

    return 0;
}