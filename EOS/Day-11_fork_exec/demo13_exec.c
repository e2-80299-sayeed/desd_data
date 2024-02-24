#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, err, s;
    printf("parent started!\n");
    ret = fork();
    if(ret == 0) {
        //err = execl("/usr/bin/firefox", "firefox", "http://sunbeaminfo.in", NULL);
        //err = execl("/usr/bin/ls", "ls", "-l", "-a", "/home", NULL);
        //err = execlp("ls", "ls", "-l", "-a", "/home", NULL);
        char *args[] = { "ls", "-l", "-a", "/home", NULL };
        err = execv("/usr/bin/ls", args);
        if(err < 0) {
            perror("exec() failed");
            _exit(1);
        }
    }
    else {
        wait(&s);
        printf("child exit status: %d\n", WEXITSTATUS(s));
    }
    printf("parent completed!\n");
    return 0;
}