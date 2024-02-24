#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void sigint_handler(int sig) {
    int i;
    for(i=1; i<=5; i++) {
        printf("SIGINT signal: %d\n", i);
        sleep(1);
    }
}

int main() {
    int i=0, ret;
    struct sigaction sa;
    
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigint_handler;
    sigfillset(&sa.sa_mask); // temp mask to be used when signal handler is running.
    ret = sigaction(SIGINT, &sa, NULL);
    if(ret < 0) {
        perror("sigaction() failed");
        _exit(1);
    }

    while(i < 10) {
        printf("running: %d\n", ++i);
        sleep(1);
    }
    return 0;
}
