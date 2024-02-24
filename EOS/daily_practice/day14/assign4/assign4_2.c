// 4. The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
// process print the result.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

enum operations{ADD=1, SUB, MUL, DIV};

int main()
{
    int  num[2],res,fd,ch;

    fd = open("/tmp/sayeed_fifo",O_RDONLY);
    if(fd < 0)
    {
        perror(" open() failed !!\n");
        _exit(1);
    }
    
    
    
    printf("waiting for data......\n");
    read(fd,&num,sizeof(num));
    printf("recieved...%d  %d\n",num[0],num[1]);
    close(fd);
    
    fd = open("/tmp/sayeed_fifo1",O_WRONLY);
    if(fd < 0)
    {
        perror(" open() failed !!\n");
        _exit(1);
    }
	
	printf("0.Exit\n1.ADD\n2.SUB\n3.MUL\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case ADD:  res = num[0] + num[1];
            	   break;
        case SUB: res = num[0] - num[1];
                break;
        case MUL: res = num[0] * num[1];
        	break;
	case DIV: res = num[0] / num[1];
		break;
	default:
            	printf("Invalid choice!!");
		break;
        }
		write(fd,&res,sizeof(res));
    		close(fd);
    

    return 0;
}
