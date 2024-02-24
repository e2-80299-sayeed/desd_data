// 1. The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
// The child process print the result and exit. The parent process wait for completion of the child and then exit.

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY 0x00009860

typedef struct message_queue
{
    long type;
    int num1;
    int num2;
    int sum;
}msg_t;


int main()
{
    int ret,s,mqid;
    
    mqid = msgget(MQ_KEY, IPC_CREAT|0600);
    if(mqid < 0)
    {
        perror("msget() failed\n");
        _exit(1);
    }
    ret = fork();
    if(ret == 0)
    {
        // CHILD process 
        msg_t m1;
        printf("child : Enter two numbers :");
        scanf("%d%d",&m1.num1,&m1.num2);
        
        m1.type = 88;
        msgsnd(mqid, &m1, sizeof(m1),0);
        
        printf("\n child : waiting for data from parent...\n");
        msgrcv(mqid,&m1,sizeof(m1),33,0);
        printf("Child received : sum = %d\n",m1.sum);
        _exit(0);
    }
    else
    {
        msg_t m2;
        printf("\n parent : waiting for data from child...\n");
        msgrcv(mqid,&m2,sizeof(m2),88,0);
        printf("Parent recived : %d  %d\n",m2.num1, m2.num2);
        m2.sum = m2.num1 + m2.num2;

        m2.type = 33;
        msgsnd(mqid,&m2,sizeof(m2),0);
        
        waitpid(-1,&s,0);

        msgctl(mqid, IPC_RMID,NULL); 
        
    }   
    
    return 0;
}