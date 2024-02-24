// 2. Implement producer consumer across two processes using POSIX semaphores and Mutexes. Hints for communication across the processes.
// Hint 1: Semaphore and Mutex must be in shared memory.
// Hint 2: Mutex pshared attribute should be set to PTHREAD_PROCESS_SHARED.
// Hint 3: Semaphore should be created with non-zero key (arg2 of sem_init()).
// Hint 4: Use signal handlers to properly cleanup shared memory and synchronization objects.

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<string.h>


#define MAX 5

#define SHM_KEY 0x00001234
#define SEM_KEY1 0x00009860
#define SEM_KEY2 0x00001982

typedef struct cirque
{
    int arr[MAX];
    int front, rear,count;
}cirque_t;


typedef struct shm
{
    cirque_t cq;
    int count;
    sem_t sf,se;
    pthread_mutex_t m;

}shm_t;

shm_t *ptr = NULL;
void cq_init(cirque_t *cq)
{
    cq->front = -1;
    cq->rear = -1;
    cq->count = 0;
    memset(cq->arr,0,sizeof(cq->arr));
}

void push(cirque_t *cq, int val)
{   
    cq->rear = (cq->rear + 1) % MAX;
    cq->arr[cq->rear] = val;
    cq->count++; 
}

int pop(cirque_t *cq)
{  
    int val;
    cq->front = (cq->front + 1) % MAX;
    val = cq->arr[cq->front];
    cq->count--;

    return val;
}

int is_cq_full(cirque_t *cq)
{
    return cq->count == MAX;
}

int is_cq_empty(cirque_t *cq)
{
    return cq->count == 0;
}

void sigint_handler(int sig)
{   
    printf("Signal caught %d: pid= %d",sig,getpid());
    int ret;
    
    pthread_mutex_destroy(&ptr->m);
    sem_destroy(&ptr->se);
    sem_destroy(&ptr->sf);
     
    ret = shmdt(ptr);// dettach shm region from both processes
    if(ret < 0)
    {
        perror("shmdt() failed !!\n");
        _exit(2);
    }
    printf("\n\n Bye :) \n");
    _exit(0);
}

int main()
{
    int ret, s1, shmid;
    
    signal(SIGINT,sigint_handler);
    
    shmid = shmget(SHM_KEY,sizeof(shm_t), IPC_CREAT|0600 );
    if(shmid < 0)
    {
        perror("shmget() failed !!\n");
        _exit(3);
    }

    ptr = (shm_t *)shmat(shmid,NULL, 0);// attach shm region to both processes
    if(ptr == (void*)-1)
    {
        perror("shmat() failed!!\n");
        shmctl(shmid, IPC_RMID, NULL);
        _exit(2);
    }

    ret = sem_init(&ptr->se,SEM_KEY1,MAX);// semaphore for queue filled 
    if(ret < 0)
    {
        perror("shmget() failed !!\n");
        _exit(3);
    }
    ret = sem_init(&ptr->sf,SEM_KEY2,0);//semaphore for queue empty
    if(ret < 0)
    {
        perror("shmget() failed !!\n");
        _exit(3);
    }

    pthread_mutexattr_t mattr;
    pthread_mutexattr_init(&mattr);
    pthread_mutexattr_setpshared(&mattr,PTHREAD_PROCESS_SHARED);
    
    pthread_mutex_init(&ptr->m,&mattr);

    ret = shmctl(shmid, IPC_RMID, NULL);//mark shm for destruction
    if(ret < 0)
    {
        perror("shmctl() failed !!\n");
        _exit(1);
    }

    

    ptr->count = 0;

    ret = fork();
    if(ret == 0)
    {
    
        //child process--prodducer
        
        int val;
        while(1)
        {
        sem_wait(&ptr->se);//P(s);
        pthread_mutex_lock(&ptr->m);//lock(m)
        val = ptr->count++;
        push(&ptr->cq, val);
        printf("WR: %d\n",val);

        pthread_mutex_unlock(&ptr->m);//unlock(m);
        sem_post(&ptr->sf);//V(sf);
        
        }
    }
    else
    {   
        //parent process--consumer
        
        int val;
        while(1)
        {
            sem_wait(&ptr->sf);//P(sf);
            pthread_mutex_lock(&ptr->m);//lock(m);

            val = pop(&ptr->cq);
            printf("RD: %d\n",val);

            pthread_mutex_unlock(&ptr->m);//unlock(m);
            sem_post(&ptr->se);//V(se)
            sleep(1);
        }
        waitpid(ret, &s1, 0);
    }   

return 0;

}