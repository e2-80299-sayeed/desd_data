#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// in this demo, SIGINT and SIGTERM signals are masked,
// so their handler (default) will not be executed.
// this process cannot be terminated using SIGINT or SIGTERM.

int main() {
    int i=0, ret;
    sigset_t set;

    sigemptyset(&set);          // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    sigaddset(&set, SIGINT);    // 01000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    sigaddset(&set, SIGTERM);   // 01000000 00000010 00000000 00000000 00000000 00000000 00000000 00000000
    ret = sigprocmask(SIG_SETMASK, &set, NULL);
    if(ret < 0) {
        perror("sigprocmask() failed");
        _exit(1);
    }

    while(1) {
        printf("running (%d): %d\n", getpid(), ++i);
        sleep(1);
    }
    return 0;
}