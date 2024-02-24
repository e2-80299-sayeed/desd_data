#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// reader
int main() {
    char str2[32];
    int fd = open("/tmp/desd_fifo", O_RDONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    printf("waiting for data...\n");
    read(fd, str2, sizeof(str2));

    printf("received: %s\n", str2);
    close(fd);
    return 0;
}
