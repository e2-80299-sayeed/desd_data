#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void sigchld_handler(int sig) {
    int s;
    waitpid(-1, &s, 0);
    printf("SIGCHLD received -- child exit status: %d\n", WEXITSTATUS(s));
}

int main() {
    int i, pid1;
    signal(SIGCHLD, sigchld_handler);

    pid1 = fork();
    if(pid1 == 0) { // first child
        for(i=1; i<=3; i++) {
            printf("dac: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    for(i=1; i<=5; i++) {
        printf("sunbeam: %d\n", i);
        sleep(1);
    }
    return 0;
}



