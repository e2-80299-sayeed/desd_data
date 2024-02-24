#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>

void sig_handler(int sig)
{
    printf("signal received :%d\n",sig);
    switch(sig)
    {
        case SIGALRM :
                    printf("SIGALRM caught !!\n");
                    break;

        case SIGINT :
                    printf("SIGINT caught !!\n ");
                    break;

        case SIGTERM :
                    printf("SIGTERM caught !!\n");
                    break;       
    }
}

void sigsegv_handler(int sig)
{
    printf("SIGSEGV caught: %d !!\n",sig);
    _exit(0);
}

int main()
{
    int i=0, ret;

    struct sigaction sa;

    memset(&sa,0,sizeof(struct sigaction)); 
    sa.sa_handler = sig_handler;

    ret = sigaction(SIGINT,&sa,NULL);
    if(ret < 0)
    {
        perror("sigaction() failed");
        _exit(1);
    }

    ret = sigaction(SIGTERM, &sa, NULL);
    if(ret < 0)
    {
        perror("sigaction() failed");
        _exit(1);
    }

    ret = sigaction(SIGALRM, &sa, NULL);
    if(ret < 0)
    {
        perror("sigaction() failed");
        _exit(1);
    }

    memset(&sa,0,sizeof(struct sigaction));
    sa.sa_handler = sigsegv_handler;

    ret = sigaction(SIGSEGV, &sa, NULL);
    if(ret < 0)
    {
        perror("sigaction() failed");
        _exit(1);
    }

    alarm(8);

    while(i<20)
    {
        printf("running : %d\n",++i);
        sleep(1);
    }
    
    int *p = NULL;
    *p = 9860;

    printf("bye!!\n");
    return 0;
}