// 1. Create a server that accept multiple clients connected over UNIX sockets. Each client send two numbers, server do the addition and send the result back.
// The client connection should be closed immediately after sending response.

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/un.h>

int main()
{
    int serv_fd, cli_fd, ret, num1, num2, res;

    struct sockaddr_un serv_addr, cli_addr;
    socklen_t socklen ;
    
    serv_fd = socket(AF_UNIX, SOCK_STREAM,0);
    if(serv_fd < 0)
    {
        perror("failed to create listening socket");
        _exit(1);
    }

    memset(&serv_addr,0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "/tmp/desd_sock");

    ret = bind(serv_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    if(ret < 0)
    {
        perror("failed to bind address to server sockect\n");
        _exit(2);
    }

    listen(serv_fd,5);

   
    memset(&cli_addr,0,sizeof(cli_addr));
    socklen = sizeof(cli_addr);
    
    while(1)
    {
        cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr,&socklen);
        if(cli_fd < 0)
        {
            perror("failed to accept client connection\n");
            _exit(3);
        }
        
        read(cli_fd, &num1, sizeof(num1));
        read(cli_fd, &num2, sizeof(num2));
        printf("client : num1 = %d num2 = %d\n",num1,num2);

        res = num1 + num2;
        printf("Server : Result sent = %d\n",res);
        write(cli_fd, &res, sizeof(res));
        close(cli_fd);
    }

    
    shutdown(serv_fd, SHUT_RDWR);
    return 0;

}
