#include <stdio.h>
#include <unistd.h>

// child and parent processes are executing concurrently.
// terminal_1> tty
//  o/p: pts/2
// terminal_1> ./demo.out
// terminal_2> ps -t pts/2 -o pid,ppid,cmd

int main() {
    int i, ret;
    printf("program started!\n");
    ret = fork();
    if(ret == 0) {
        // child process
        for(i=1; i<=10; i++) {
            printf("child: %d -- pid=%d & parent pid=%d\n", i, getpid(), getppid());
            sleep(1);
        }
    }
    else {
        // parent process
        for(i=1; i<=10; i++) {
            printf("parent: %d -- pid=%d & parent pid=%d\n", i, getpid(), getppid());
            sleep(1);
        }
    }
    printf("program completed!\n");
    return 0;
}

