#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, err, s, fd;
    printf("program started.\n");
    ret = fork();
    if(ret == 0) {
        // output redirection
        fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0664);
        // TODO error check
        close(1);
        dup(fd);
        close(fd);

        err = execlp("ls", "ls", "-l", "/home", NULL);
        if(err < 0) {
            perror("exec() failed");
            _exit(1);
        }
    }
    else
        waitpid(ret, &s, 0);
    printf("program completed.\n");
    return 0;
}

