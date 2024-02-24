#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("Signal handler %d executed in process %d.\n", sig, getpid());
}

int main() {
    int i=0, ret;
    signal(SIGINT, sigint_handler);
    while(i < 10) {
        printf("running (%d): %d\n", getpid(), ++i);
        sleep(1);
    }
    return 0;
}
