#include<stdio.h>
#include<sys/mman.h>

int main() 
{
    unsigned long size = 4L * 1024 * 1024 * 1024;
    char *ptr;
    ptr = (char*)mmap(NULL,size,PROT_READ|PROT_WRITE, MAP_SHARED| MAP_ANONYMOUS, -1 ,0);

    printf("mmap() returened : %p",ptr);
    getchar();
    munmap(ptr,size);
    return 0;
}