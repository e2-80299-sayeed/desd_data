#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct shm {
    int count;
} shm_t;

int main() {
    shm_t *ptr;
    int i, ret, s;

    ptr = (shm_t*) malloc(sizeof(shm_t)); 
    ptr->count = 0;
    ret = fork();
    if(ret == 0) {
        for(i=1; i<=10; i++) {
            ptr->count++;
            printf("child: %d\n", ptr->count);
            sleep(1);
        }
    } else {
        for(i=1; i<=10; i++) {
            ptr->count--;
            printf("parent: %d\n", ptr->count);
            sleep(1);
        }
        waitpid(-1, &s, 0);
        printf("final count: %d\n", ptr->count);
    }
    free(ptr);
    return 0;
}