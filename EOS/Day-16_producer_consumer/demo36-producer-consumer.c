#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define MAX 5
typedef struct cirque {
    int arr[MAX];
    int front, rear, count;
} cirque_t;

void cq_init(cirque_t *cq) {
    cq->front = -1;
    cq->rear = -1;
    cq->count = 0;
    memset(cq->arr, 0, sizeof(cq->arr));
}

void cq_push(cirque_t *cq, int val) {
    cq->rear = (cq->rear + 1) % MAX;
    cq->arr[cq->rear] = val;
    cq->count++;
}

int cq_pop(cirque_t *cq) {
    int val;
    cq->front = (cq->front + 1) % MAX;
    val = cq->arr[cq->front];
    cq->count--;
    return val;
}

int cq_is_empty(cirque_t *cq) {
    return cq->count == 0;
}

int cq_is_full(cirque_t *cq) {
    return cq->count == MAX;
}

#define SHM_KEY     0x00002809
#define SEM_KEY     0x00001506
cirque_t *ptr;
int semid;

typedef union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
}semun_t;

enum semnum {
    SM=0, SF=1, SE=2
};

void sigchld_handler(int sig) {
    int s;
    waitpid(-1, &s, 0);
}

void sigint_handler(int sig) {
    shmdt(ptr);
    semctl(semid, 0, IPC_RMID);
    printf("bye!\n");
    _exit(0);
}

int main() {
    int shmid, val, i, ret;
    struct sigaction sa;
    semun_t su;
    struct sembuf ops[2];

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigint_handler;
    ret = sigaction(SIGINT, &sa, NULL);

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigchld_handler;
    ret = sigaction(SIGCHLD, &sa, NULL);

    semid = semget(SEM_KEY, 3, IPC_CREAT|0600);
    su.val = 1;
    ret = semctl(semid, SM, SETVAL, su);
    su.val = 0;
    ret = semctl(semid, SF, SETVAL, su);
    su.val = MAX;
    ret = semctl(semid, SE, SETVAL, su);

    shmid = shmget(SHM_KEY, sizeof(cirque_t), IPC_CREAT|0600);
    ptr = (cirque_t*) shmat(shmid, NULL, 0);
    
    shmctl(shmid, IPC_RMID, NULL); // mark for destruction
    cq_init(ptr);

    ret = fork();
    if(ret == 0) {
        // child process -- producer
        while(1) {
            //P(SM,SE);
            ops[0].sem_num = SM;
            ops[0].sem_op = -1;
            ops[0].sem_flg = 0;
            ops[1].sem_num = SE;
            ops[1].sem_op = -1;
            ops[1].sem_flg = 0;
            ret = semop(semid, ops, 2);
            
            val = rand() % 100;
            cq_push(ptr, val);
            printf("WR: %d\n", val);
            //V(SM,SF);
            ops[0].sem_num = SM;
            ops[0].sem_op = +1;
            ops[0].sem_flg = 0;
            ops[1].sem_num = SF;
            ops[1].sem_op = +1;
            ops[1].sem_flg = 0;
            ret = semop(semid, ops, 2);

            sleep(1);
        }
    }
    else {
        //parent process -- consumer
        while(1) {
            //P(SM,SF);
            ops[0].sem_num = SM;
            ops[0].sem_op = -1;
            ops[0].sem_flg = 0;
            ops[1].sem_num = SF;
            ops[1].sem_op = -1;
            ops[1].sem_flg = 0;
            ret = semop(semid, ops, 2);

            val = cq_pop(ptr);
            printf("RD: %d\n", val);
            sleep(1);

            //V(SM,SE);
            ops[0].sem_num = SM;
            ops[0].sem_op = +1;
            ops[0].sem_flg = 0;
            ops[1].sem_num = SE;
            ops[1].sem_op = +1;
            ops[1].sem_flg = 0;
            ret = semop(semid, ops, 2);
        }
    }
    return 0;
}

