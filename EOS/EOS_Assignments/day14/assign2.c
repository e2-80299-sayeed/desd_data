// The child process send two numbers to the parent process via pipe. The parent process calculate the sum and return via another pipe. The child process
// print the result and exit. The parent process wait for completion of the child and then exit.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

typedef struct numbers
{
    int num1;
    int num2;
}num_t;

typedef struct sum
{
    int sum;
}sum_t;



int main()
{
    int ret,s, fd[2], fd1[2];
    num_t n;
    sum_t sum;
    
    ret = pipe(fd);
    if(ret < 0)
    {
        perror("pipe() failed !!");
        _exit(0);
    }

    ret = pipe(fd1);
    if(ret < 0)
    {
        perror("pipe() failed !!");
        _exit(0);
    }

    ret = fork();
    if(ret == 0)
    {
    //child -- writer
    
    close(fd[0]);
    printf("Enter two numbers: ");
    scanf("%d%d",&n.num1,&n.num2);

    write(fd[1],&n,sizeof(n));
    close(fd[1]);
    
    close(fd1[1]);
    read(fd1[0],&sum,sizeof(sum));
    printf("Received: Sum = %d\n",sum.sum);
    close(fd1[0]);

    _exit(1);

    }
    else{
        close(fd[1]);
        read(fd[0],&n,sizeof(n));
        close(fd[0]);
        printf("Numbers received: %d  %d\n",n.num1,n.num2);
        sum.sum = n.num1 + n.num2;

        close(fd1[0]);
        write(fd1[1],&sum,sizeof(sum));
        close(fd1[1]);
        waitpid(-1,&s,0);
    }
    return 0;
}