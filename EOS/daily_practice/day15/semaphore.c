//As shm does not have its own waiting queue,so there is a problem of Race condition which leads to 
//unexpected output to overcome it we have semaphore which provides us its waiting queue so that we can 
//achive multi processing and desired output.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/sem.h>

//step1: Create a key for shm.
#define SHM_KEY 0x00001234

//step2: create a key for semaphore.
#define SEM_KEY 0x00009876

typedef struct shm
{
	int count;
}shm_t;

//step3 : create a union for semaphore.
typedef union semun {
	//Value for SETVAL
	int val;
	
	//Buffer for IPC_STAT, IPC_SET
	struct semid_ds *buf;
	
	//Array for GETALL, SETALL
	unsigned short *array;

	//Buffer for IPC_INFO (Linux- specific)
	struct seminfo *__buf;
}semun_t;

int main()
{

	shm_t *ptr;
	int shmid, i, ret, s, semid;
	
	semun_t su;
	struct sembuf ops[1];
	
	//create a semaphore counter
	semid = semget(SEM_KEY, 1, IPC_CREAT|0600);
	
	//intialize semaphore to 1
	su.val  = 1;
	semctl(semid, 0, SETVAL, su); 

	//step2: create a shm object and init with default values in kernel space.
	shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT|0600);
	if(shmid < 0)
	{
		perror("shmget() failed !\n");
		_exit(1);
	}
	
	//step3: attach the shm region to the process.
	ptr = (shm_t*)shmat(shmid,NULL,0);
	if(ptr == (void*)-1)
	{
		perror("shmat() failed !\n");
		_exit(2);
	}

	//step4: mark shm for desturction.
	shmctl(shmid, IPC_RMID,NULL);
	
	ptr->count = 0;
	
	//step 5: another process for IPC.
	ret = fork();
	if(ret == 0)
	{
		for(i = 1; i <=10; i++)
		{	// P(sem)
			ops[0].sem_num = 0;
			ops[0].sem_op = -1;
			ops[0].sem_flg = 0;
			ret = semop(semid, ops, 1);
			
			ptr->count ++;
			printf("child: %d\n",ptr->count);
			
			//V(sem)
			ops[0].sem_num = 0;
			ops[0].sem_op  = +1;
			ops[0].sem_flg = 0;
			ret = semop(semid, ops, 1);
			
			sleep(1); 
		}
	}
	else
	{
		for(i = 1; i <=10; i++)
		{
				
			// P(sem)
			ops[0].sem_num = 0;
			ops[0].sem_op = -1;
			ops[0].sem_flg = 0;
			ret = semop(semid, ops, 1);
			
			ptr->count--;
			printf("parent: %d\n",ptr->count);
			//V(sem)
			ops[0].sem_num = 0;
			ops[0].sem_op  = +1;
			ops[0].sem_flg = 0;
			ret = semop(semid, ops, 1);
			
			sleep(1);
		}
		waitpid(-1,&s,0);
		printf("final count: %d\n",ptr->count);
	}
	//step 6: detach the shm region from the process as it is already marked to destroy.	
	shmdt(ptr);	
	return 0;
}
