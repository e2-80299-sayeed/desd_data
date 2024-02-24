#include <stdio.h>
#include <unistd.h>

int main() {
    int ret, fd[2];
    char str1[32], str2[32];

    ret = pipe(fd);
    if(ret < 0) {
        perror("pipe() failed");
        _exit(1);
    }

    printf("wr: enter a string - ");
    scanf("%s", str1);
    write(fd[1], str1, sizeof(str1));

    read(fd[0], str2, sizeof(str2));
    printf("rd: data read - %s\n", str2);

    close(fd[1]);
    close(fd[0]);
    return 0;
}