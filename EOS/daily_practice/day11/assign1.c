#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child_process(int count) {
    for (int i = 1; i <= 5; i++) 
    {
    printf("Child %d (PID %d) \n", count, getpid());
    sleep(1);
    }
}

int main() {
    
    int pid;
    int i,s;
    // Create 5 child processes
    for (i = 1; i <= 5; ++i) {
        pid = fork();

        if (pid == 0) {
            child_process(i);
            exit(0);
        }
    }

    // Wait for all child processes to complete
    for (i = 1; i <= 10; ++i) {
        if (i <= 5)
        {
        waitpid(-1,&s,0);
        }
        else
        {
            printf("parent , pid : %d\n",getpid());
        }
        
    }

    return 0;
}
