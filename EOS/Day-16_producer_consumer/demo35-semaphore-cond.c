#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>

#define SEM_KEY 0x00003333

typedef union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
}semun_t;

int main() {
    int i, ret, s, semid;
    semun_t su;
    struct sembuf ops[1];
    // create semaphore and init s=0
    semid = semget(SEM_KEY, 1, IPC_CREAT|0600);
    su.val = 0;
    ret = semctl(semid, 0, SETVAL, su);

    ret = fork();
    if(ret == 0) {
        char *str = "SUNBEAM ";
        for(i=0; str[i]!='\0'; i++) {
            putchar(str[i]);
            fflush(stdout);
            sleep(1);
        }
        // V(s);
        ops[0].sem_num = 0;
        ops[0].sem_op = +1;
        ops[0].sem_flg = 0;
        ret = semop(semid, ops, 1);
        // child -- further work.
    }
    else {
        char *str = "INFOTECH";
        // P(s);
        ops[0].sem_num = 0;
        ops[0].sem_op = -1;
        ops[0].sem_flg = 0;
        ret = semop(semid, ops, 1);

        for(i=0; str[i]!='\0'; i++) {
            putchar(str[i]);
            fflush(stdout);
            sleep(1);
        }
        waitpid(-1, &s, 0);
        // destroy semaphore
        ret = semctl(semid, 0, IPC_RMID);
    }
    printf("\n");
    return 0;
}