		#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// child and parent processes are executing concurrently.
// child process is terminated before the parent process.

// child process's resources are released and its exit status is written in its PCB.
// since parent process is not reading exit status of the child, its PCB is not released.
// this state is called Zombie state.

// The parent process should read the exit status of the child process using wait() or waitpid() syscall.
// ret = waitpid(child_pid, &status, flags)
    // arg1: pid of the child for which the current process (parent) should wait
    //      -1 - any of the child
    // arg2: out param to collect child exit status
    // arg3: flags -- special value for some special operation.
    //          0 - no special behaviour required
    //    WNOHANG - if child is terminated, collect its exit status; if child is not terminated, do not wait for completion of the child and return error.
    // returns: pid of the child whose exit status is collected (on success).

// waitpid(-1, &s, 0) is equivalent to wait(&s).

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
                waitpid(ret, &s, 0);
                printf("parent: child's exit status: %d\n", WEXITSTATUS(s));
            }
        }
    }
    printf("program completed!\n");
    return 0;
}

