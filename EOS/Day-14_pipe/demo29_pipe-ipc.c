#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, fd[2], s;
    char str1[32], str2[32];

    ret = pipe(fd);
    if(ret < 0) {
        perror("pipe() failed");
        _exit(1);
    }

    ret = fork();

    if(ret == 0) {
        // child process -- writer
        close(fd[0]); // writer close read fd before start commn.
        printf("wr: enter a string - ");
        scanf("%s", str1);
        write(fd[1], str1, sizeof(str1));
        close(fd[1]); // writer close write fd after the commn.
    }
    else {
        // parent process -- reader
        close(fd[1]); // reader close write fd before start commn.
        read(fd[0], str2, sizeof(str2));
        printf("rd: data read - %s\n", str2);
        close(fd[0]); // reader close read fd after the commn.
        waitpid(-1, &s, 0);
    }
    return 0;
}