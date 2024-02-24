#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>

void sigint_handler(int sig)
{
    int s;
    // waitpid(-1,&s,0);
    printf("signal caught: %d\n",sig);
}

int main()
{
    char *ptr, cmd[50], *args[32];
    int i, ret, err, s;
    signal(2,sigint_handler);
    
    printf("Welcome to my Shell :)\n");
    while(1)
    {
        printf("cmd> ");
        scanf("%*c%[^\n]s",cmd);    
        i=0;
        ptr = strtok(cmd," ");
        args[i] = ptr;
        do{
            ptr = strtok(NULL," ");
            args[++i] = ptr;
        }while(ptr != NULL);

        if(strcmp(args[0],"exit") == 0)
            _exit(0);
        else if( strcmp(args[0],"cd") == 0)
            chdir(args[1]);
        else 
        {
            ret = fork();
            if(ret == 0)
            {
                err=execvp(args[0], args);
                if(err <0 ){
                    perror("bad command\n");
                    _exit(1);
                }
            }
            else
                waitpid(-1, &s ,0);
        }
    }
    return 0;

}
