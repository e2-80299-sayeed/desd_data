#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// writer
int main() {
    char str1[32];
    int fd = open("/tmp/desd_fifo", O_WRONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    printf("enter a string: ");
    scanf("%s", str1);

    write(fd, str1, sizeof(str1));

    close(fd);
    return 0;
}

// cmd> mkfifo /tmp/desd_fifo
// cmd> ls -l /tmp/desd_fifo