#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>

#define SHM_KEY 0x00001234
#define SEM_KEY 0x00009000

typedef struct shm
{
    double SI;
    pthread_mutex_t m;
    sem_t  sem;    
}shm_t;

shm_t *ptr = NULL;


void *simple_intrest(void * param)
{
    double SI, P, R, T;
    printf("Enter Principle :");
    scanf("%lf",&P);
    printf("Enter Rate :");
    scanf("%lf",&R);
    printf("Enter Time period :");
    scanf("%lf",&T);
    SI = (P*R*T)/100;
    
    return &SI;
}

int main()
{

    int i, ch_id1,ch_id2, s1, s2, shmid;

    shmid = shmget(SHM_KEY, sizeof(shm_t),IPC_CREAT | 0600);
    if(shmid < 0)
    {
        perror("shmget() failed !!\n");
        _exit(1);
    }

    ptr = (shm_t*)shmat(shmid, NULL, 0);
    if(ptr == (void *)-1)
    {
        perror("shmat() failed !!\n");
        shmctl(shmid,IPC_RMID, NULL);
        _exit(2);
    }

    sem_init(&ptr->sem, SEM_KEY);

    ch_id1 = fork();
    if(ch_id1 == 0)
    {//child_1
    int ret;
    pthread_t th;
    ret = pthread_create(&th,NULL,simple_intrest,NULL);
    if(ret < 0)
    {
        perror("pthread_create() failed !!");
       _exit(1); 
    }
    pthread_join(th,NULL);

       _exit(0);     
    }
    
    ch_id2 = fork();
    if(ch_id2 == 0)
    {
    
    //child_2

        _exit(0);
    }

    waitpid(ch_id1,s1,0);
    waitpid(ch_id2,s2,0);

    return 0;
}