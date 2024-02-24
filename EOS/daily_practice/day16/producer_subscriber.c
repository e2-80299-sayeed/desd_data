#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5

typedef struct circque{
    int arr[MAX];
    int front, rear, count;
}circque_t;

void cq_init(circque_t *cq)
{
    cq->front = -1;
    cq->rear = -1;
    cq->count = 0;
    memset(cq->arr, 0, sizeof(cq->arr));
}

void cq_push(circque_t *cq, int val)
{
    cq->rear = (cq->rear + 1 ) % MAX;
    cq->arr[cq->rear] = val;
    cq->count++;

}

int cq_pop(circque_t *cq)
{
    int val;
    cq->front = (cq->front + 1) % MAX;
    val = cq->arr[cq->front];
    cq->count--;
    return val;
}

int cq_is_empty(circque_t *cq)
{
    return cq->count == 0;
}

int cq_is_full(circque_t *cq)
{
    return cq->count == MAX;
}

#define SHM_kEY 0x00002809
#define SEM_KEY 0x00001506 

circque_t *ptr;
int semid;

typedef union semun 
{
    int             val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
}semun_t;

enum semnum
{
    SM=0, SF=1, SE=2
};

void sigchld_handler(int sig)
{
    int s;
    waitpid(-1, &s, 0);
}

void sigint_handler(int sig)
{
    shmdt(ptr);
    semctl(semid, 0, IPC_RMID);
    printf("Bye!\n");
    _exit(0);
}

int main()
{
    int shmid, val , i, ret;
    struct sigaction sa;
    semun_t su;
    struct sembuf ops[2];

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigint_handler;

    ret = sigaction(SIGINT,&sa, NULL);
    if(ret < 0)
    {
        perror("sigaction() failed !!");
        _exit(1);
    }

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigchld_handler;

    ret = sigaction(SIGCHLD,&sa, NULL);
    if(ret < 0)
    {
        perror("sigaction() failed !!");
        _exit(1);
    }

    semid = semget(SEM_KEY, 3, IPC_CREAT|0600);
    if(semid < 0)
    {
        perror("semget() failed !!");
        _exit(1);
    }

    su.val = 1;
    ret = semctl(semid, SM, SETVAL, su);
    if(ret < 0)
    {
        perror("semctl() failed !!");
        _exit(1);
    }
    
    su.val = 0;
    ret = semctl(semid, SF, SETVAL, su);
    if(ret < 0)
    {
        perror("semctl() failed !!");
        _exit(1);
    }

    su.val = MAX;
    ret = semctl(semid, SE, SETVAL, su);
    if(ret < 0)
    {
        perror("semctl() failed !!");
        _exit(1);
    }

    shmid = shmget(SHM_kEY, sizeof(circque_t), IPC_CREAT|0600);
    if(shmid < 0)
    {
        perror("shmget() failed !!\n");
        _exit(2);
    }

    ptr = (circque_t*)shmat(shmid, NULL, 0);

    ret = shmctl(shmid, IPC_RMID, NULL);//mark for destruction
     if(ret < 0)
    {
        perror("shmctl() failed !!");
        _exit(3);
    }

    cq_init(ptr);

    ret= fork();
    if(ret == 0)
    {
        // child process -- producer
        while (1)
        {
            //P(SM,SE);
        ops[0].sem_num = SM;
        ops[0].sem_op = -1;
        ops[0].sem_flg = 0;

        ops[1].sem_num = SE;
        ops[1].sem_op = -1;
        ops[1].sem_flg = 0;

        ret = semop(semid, ops, 2);
        if(ret < 0)
        {
            perror("semop() failed !!\n");
            _exit(1);
        }
        val = rand() % 100;
        cq_push(ptr,val);

            printf("WR: %d\n",val);
        
        //V(SM,SF);

        ops[0].sem_num = SM;
        ops[0].sem_op = +1;
        ops[0].sem_flg = 0;

        ops[1].sem_num = SF;
        ops[1].sem_op = +1;
        ops[1].sem_flg = 0;

        ret = semop(semid, ops, 2);
        if(ret < 0)
        {
            perror("semop() failed !!\n");
            _exit(1);
        }
        sleep(1);

        }
        
    }
    else
    {
        //parent process -- consumer 
        while (1)
        {
            //P(SM,SF);
        ops[0].sem_num = SM;
        ops[0].sem_op = -1;
        ops[0].sem_flg = 0;

        ops[1].sem_num = SF;
        ops[1].sem_op = -1;
        ops[1].sem_flg = 0;

        ret = semop(semid, ops, 2);
        if(ret < 0)
        {
            perror("semop() failed !!\n");
            _exit(1);
        }
        val = cq_pop(ptr); 
        printf("RD: %d\n",val);

        sleep(1);

        //V(SM,SE);

        ops[0].sem_num = SM;
        ops[0].sem_op = +1;
        ops[0].sem_flg = 0;

        ops[1].sem_num = SE;
        ops[1].sem_op = +1;
        ops[1].sem_flg = 0;

        ret = semop(semid, ops, 2);
        if(ret < 0)
        {
            perror("semop() failed !!\n");
            _exit(1);
        }
        

        }
    }
    return 0;
}
