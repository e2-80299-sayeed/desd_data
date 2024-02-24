#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    unsigned long size = 4L * 1024 * 1024 * 1024;
    int page_size = sysconf(_SC_PAGE_SIZE); // 4096
    char *ptr, *p;
    ptr = (char*)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    printf("mmap() returned: %p\n", ptr);
    getchar();
    for(p = ptr; p < ptr+size; p+=page_size)
        *p = 'A';
    printf("physical memory allocated.\n");
    getchar();
    munmap(ptr, size);
    return 0;
}
