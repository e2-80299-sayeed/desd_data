#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SERVER_IP   "172.18.4.214"
#define SERVER_PORT 2809

int main() {
    int cli_fd, ret;
    struct sockaddr_in serv_addr;
    char str[64];
    // create server socket
    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(cli_fd < 0) {
        perror("failed to create client socket");
        _exit(1);
    }

    // connect to server socket
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_aton(SERVER_IP, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(SERVER_PORT);
    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret < 0) {
        perror("failed to connect to server socket");
        _exit(2);
    }

    do {
        printf("client: ");
        gets(str);
        // write to server
        write(cli_fd, str, sizeof(str));

        // read from server
        read(cli_fd, str, sizeof(str));
        printf("server: %s\n", str);
    } while(strcmp(str, "bye") != 0);

    // close client connection
    close(cli_fd);
    return 0;
}
