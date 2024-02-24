// 4. The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
// process print the result.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int  num[2],res,fd;

    fd = open("/tmp/sayeed_fifo",O_WRONLY);
    if(fd < 0)
    {
        perror(" open() failed !!\n");
        _exit(1);
    }
    
    printf("Enter 2 nos: ");
    scanf("%d%d",&num[0],&num[1]);

    write(fd,&num,sizeof(num));
    close(fd);

    fd = open("/tmp/sayeed_fifo1",O_RDONLY);
    if(fd < 0)
    {
        perror(" open() failed !!\n");
        _exit(1);
    }
    printf("waiting for data......\n");
    read(fd,&res,sizeof(res));
    printf("recieved...result = %d\n",res);
    close(fd);
    return 0;
}