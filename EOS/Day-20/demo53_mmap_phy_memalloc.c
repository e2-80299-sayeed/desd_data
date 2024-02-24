#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    unsigned long size = 4L * 1024 * 1024 * 1024;
    int page_size = sysconf(_SC_PAGE_SIZE); // 4096
    char *ptr, *p;
    ptr = (char*)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if(ptr != MAP_FAILED) {
		for(p = ptr; p < ptr+size; p+=page_size)
       		*p = 'A';
    	printf("physical memory allocated: virtual addr = %p\n", ptr);
    	getchar();
    	munmap(ptr, size);
	}
	else
		printf("mmap() failed.\n");
    return 0;
}
