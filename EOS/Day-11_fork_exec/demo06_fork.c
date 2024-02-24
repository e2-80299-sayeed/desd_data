#include <stdio.h>
#include <unistd.h>

// child and parent processes are executing concurrently.
// child process is terminated before the parent process.

// child process's resources are released and its exit status is written in its PCB.
// since parent process is not reading exit status of the child, its PCB is not released.
// this state is called Zombie state.

// In "ps" command output, Zombie state is displayed as "Z" and
// The process is marked as "<defunct>".

// terminal_1> tty
//  o/p: pts/2
// terminal_1> ./demo.out
// terminal_2> ps -t pts/2 -o pid,ppid,state,cmd

int main() {
    int i, ret;
    printf("program started!\n");
    ret = fork();
    if(ret == 0) {
        // child process
        for(i=1; i<=5; i++) {
            printf("child: %d\n", i);
            sleep(1);
        }
    }
    else {
        // parent process
        for(i=1; i<=10; i++) {
            printf("parent: %d\n", i);
            sleep(1);
        }
    }
    printf("program completed!\n");
    return 0;
}

