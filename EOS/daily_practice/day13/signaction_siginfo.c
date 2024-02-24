#include<stdio.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int sig, siginfo_t *si, void *param)
{
    printf("signal %d received from process %d. \n",si->si_signo, si->si_pid);
}

int main()
{
    int i=0, ret;
    struct sigaction sa;

    memset(&sa,0, sizeof(struct sigaction));
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO;
    ret - sigaction(SIGINT, &sa, NULL);
    if(ret < 0)
    {
        perror("sigaction() failed");
        _exit(1);
    }
    while(i < 100)
    {
        printf("running: %d\n",++i);
        sleep(1);
    }
    return 0;
}