#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// child and parent processes are executing concurrently.
// child process is terminated before the parent process.

// child process's resources are released and its exit status is written in its PCB.
// since parent process is not reading exit status of the child, its PCB is not released.
// this state is called Zombie state.

// The parent process should read the exit status of the child process using wait() syscall.
// wait() syscall does following
    //1. pause parent process until termination of one of the child process.
    //2. read exit status of the child into wait()'s out parameter
    //3. release PCB of the child
    //returns pid of the child process on success.

// The exit value collected in wait()'s out parameters contains information
    //1. child exit status (8 bit: 0 for success, non-zero for failure)
    //2. reason of termintation
    //3. signal number of termination (if any)
// WEXITSTATUS(s) --> returns child exit status (8-bit)
// WTERMSIGNAL(s) --> returns signal number due to which child is terminated

// terminal_1> tty
//  o/p: pts/2
// terminal_1> ./demo.out
// terminal_2> ps -t pts/2 -o pid,ppid,state,cmd

int main() {
    int i, ret, s;
    printf("program started!\n");
    ret = fork();
    if(ret == 0) { // child process
        for(i=1; i<=5; i++) {
            printf("child: %d\n", i);
            sleep(1);
        }
        _exit(3); // child is terminated with exit status=3
    }
    else { // parent process
        for(i=1; i<=10; i++) {
            printf("parent: %d\n", i);
            sleep(1);
            if(i == 5) {
                wait(&s);
                printf("parent: child's exit status: %d\n", WEXITSTATUS(s));
            }
        }
    }
    printf("program completed!\n");
    return 0;
}

