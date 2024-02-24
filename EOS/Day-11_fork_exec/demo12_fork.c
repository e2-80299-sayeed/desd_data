#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, count = 0;

    while(1) {
        ret = fork();
        if(ret == -1)
            break;
        else if(ret == 0) {
            // child process
            sleep(5);
            _exit(0);
        }
        else {
            // parent process
            count++;
        }
    }
    // TODO cleanup all child processes
    while(ret > 0)
    {
    	wait(NULL);
   }
    printf("parent : %d\n",getpid());
    printf("max child count: %d\n", count);
    return 0;
}
