#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
    char *filepath = "/home/nilesh/sep-23/desd/eos/Day-20/demo51_mmap_virt_memalloc.c";
    int fd, i;
    struct stat st;
    char *ptr;
    fd = open(filepath, O_RDONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }
    fstat(fd, &st);

    ptr = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    for(i=0; i<st.st_size; i++)
        putchar(ptr[i]);
    
    munmap(ptr, st.st_size);
    close(fd);
    return 0;
}



