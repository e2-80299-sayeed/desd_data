#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long size = 20L * 1024;
    char *ptr;
    int i;
    printf("allocating memory of size: %.3lf MB\n", size/1024.0/1024.0);
    for(i=1; i<=20; i++) {
        ptr = (char*)malloc(size);
        printf("malloc() returned: %p\n", ptr);
        getchar();
    }
    free(ptr);
    return 0;
}