#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/shm.h>

//step1: Create a key.
#define SHM_KEY 0x00001234

typedef struct shm
{
	int count;
}shm_t;

int main()
{

	shm_t *ptr;
	int shmid, i, ret, s, temp;
	
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
		{
			ptr->count ++;
			printf("child: %d\n",ptr->count);
			sleep(1); 
		}
	}
	else
	{
		for(i = 1; i <=10; i++)
		{
			ptr->count--;
			printf("parent: %d\n",ptr->count);
			sleep(1);
		}
		waitpid(-1,&s,0);
		printf("final count: %d\n",ptr->count);
	}
	//step 6: detach the shm region from the process as it is already marked to destroy.	
	shmdt(ptr);	
	return 0;
}
