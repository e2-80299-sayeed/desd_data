#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x00004444
#define SEM_KEY 0x00002222

typedef struct shm {
    int count;
} shm_t;

typedef union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
}semun_t;

int main() {
    shm_t *ptr;
    int shmid, i, ret, s, temp, semid;
    semun_t su;
    struct sembuf ops[1];

    // create a semaphore counter
    semid = semget(SEM_KEY, 1, IPC_CREAT|0600);
    // initialize semaphore to 1
    su.val = 1;
    semctl(semid, 0, SETVAL, su);

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
        for(i=1; i<=100000; i++) {
            // P(sem);
            ops[0].sem_num = 0;
            ops[0].sem_op = -1;
            ops[0].sem_flg = 0;
            ret = semop(semid, ops, 1);

            temp = ptr->count + 1;
            ptr->count = temp;
            printf("child: %d\n", ptr->count);
            // V(sem);
            ops[0].sem_num = 0;
            ops[0].sem_op = +1;
            ops[0].sem_flg = 0;
            ret = semop(semid, ops, 1);

            //sleep(1);
        }
    } else {
        for(i=1; i<=100000; i++) {
            // P(sem);
            ops[0].sem_num = 0;
            ops[0].sem_op = -1;
            ops[0].sem_flg = 0;
            ret = semop(semid, ops, 1);

            temp = ptr->count - 1;
            ptr->count = temp;
            printf("parent: %d\n", ptr->count);

            // V(sem);
            ops[0].sem_num = 0;
            ops[0].sem_op = +1;
            ops[0].sem_flg = 0;
            ret = semop(semid, ops, 1);
            	//sleep(1);
        }
        waitpid(-1, &s, 0);
        printf("final count: %d\n", ptr->count);
    }
    shmdt(ptr);
    // destroy the semaphore
    semctl(semid, 0, IPC_RMID);
    return 0;
}
