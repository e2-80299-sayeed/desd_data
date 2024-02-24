#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// terminal> ./05_filecopy.out <srcfile> <destfile>
int main(int argc, char *argv[]) {
    int fs, fd, cnt;
    char buf[512];

    if(argc != 3) {
        fprintf(stderr, "syntax: %s <src file path> <dest file path>\n", argv[0]);
        exit(1);
    }

    // open src file
    fs = open(argv[1], O_RDONLY);
    if(fs < 0) {
        perror("open() failed to open src file");
        exit(2);
    }
    // open dest file
    fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644); // rw- r-- r--
    if(fd < 0) {
        perror("open() failed to open dest file");
        close(fs);
        exit(3);
    }
    // read 512 bytes from src file
    while( (cnt = read(fs, buf, sizeof(buf))) > 0 ) {
        // write those bytes into dest file
        write(fd, buf, cnt);
    } // repeat until all bytes are read

    // close dest file
    close(fd);
    // close src file
    close(fs);

    printf("file copied.\n");
    return 0;
}

