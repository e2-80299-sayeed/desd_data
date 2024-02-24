#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHM_KEY 0x00004444

typedef struct shm {
    int count;
} shm_t;

int main() {
    shm_t *ptr;
    int shmid, i, ret, s, temp;
    shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT|0600);
    if(shmid < 0) {
        perror("shmget() failed");
        _exit(1);
    }

    ptr = (shm_t*) shmat(shmid, NULL, 0);
    if(ptr == (void*)-1) {
        perror("shmat() failed");
        shmctl(shmid, IPC_RMID, NULL);
        _exit(2);
    }

    shmctl(shmid, IPC_RMID, NULL); // mark shm for destruction  

    ptr->count = 0;
    ret = fork();
    if(ret == 0) {
        for(i=1; i<=10; i++) {
            temp = ptr->count + 1;
            ptr->count = temp;
            printf("child: %d\n", ptr->count);
            sleep(1);
        }
    } else {
        for(i=1; i<=10; i++) {
            temp = ptr->count - 1;
            ptr->count = temp;
            printf("parent: %d\n", ptr->count);
            sleep(1);
        }
        waitpid(-1, &s, 0);
        printf("final count: %d\n", ptr->count);
    }
    shmdt(ptr);
//  shmctl(shmid, IPC_RMID, NULL);
    return 0;
}