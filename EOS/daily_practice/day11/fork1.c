#include<stdio.h>
#include<unistd.h>

int main()
{	
	int i, ret;
	printf("program is started!\n");

	ret = fork();
	if(ret == 0)
	{
		//child process
		for(i=1; i<= 10; i++){
			printf("child: %d  pid = %d  ppid = %d\n",i, getpid(),getppid());
			sleep(1);
		}
	}		
	else
	{
		//parent process
		for(i = 1; i<= 10; i++){
			printf("parent: %d  pid = %d  ppid = %d\n",i, getpid(),getppid());
			sleep(1);	
		}
	}
	printf("program completed!\n");
	return 0;
}
