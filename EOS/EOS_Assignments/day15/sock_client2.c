// 1. Create a server that accept multiple clients connected over UNIX sockets. Each client send two numbers, server do the addition and send the result back.
// The client connection should be closed immediately after sending response.

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/un.h>

int main()
{
    int  cli_fd, ret, num1, num2, res;

    struct sockaddr_un serv_addr;
    
    cli_fd = socket(AF_UNIX, SOCK_STREAM,0);
    if(cli_fd < 0)
    {
        perror("failed to create listening socket");
        _exit(1);
    }

    memset(&serv_addr,0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "/tmp/desd_sock");

    ret = connect(cli_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    if(ret < 0)
    {
        perror("failed to bind address to server sockect\n");
        _exit(2);
    }

    
    int exit;
    do{
        printf("Ente two numbers: ");
        scanf("%d%d",&num1, &num2);
        printf("client 2 :Numbers sent : num1 = %d num2 = %d\n",num1,num2);

        write(cli_fd, &num1, sizeof(num1));
        write(cli_fd, &num2, sizeof(num2));
        
        
        read(cli_fd, &res, sizeof(res));
        printf("Server : Result received = %d\n",res);
        printf("Press 0 to Exit!!");
        scanf("%d",&exit);
    }while(exit != 0);

    close(cli_fd);
    
    return 0;

}
