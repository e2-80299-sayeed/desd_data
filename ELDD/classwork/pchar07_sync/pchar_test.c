#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void sigint_handler(int sig)
{
    printf("signal caught!\n");
}

int main()
{
    int fd, ret;
    char str[32];

    signal(SIGINT, sigint_handler);

    fd = open("/dev/pchar0", O_WRONLY);
    if(fd < 0)
    {
        perror("open() failed");
        _exit(1);
    }

    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ret = write(fd, str, 26);
    printf("write() returned : %d \n",ret);

    strcpy(str, "123456");
    ret = write(fd, str, 6);
    printf("write() returned : %d \n",ret);

    strcpy(str, "good");
    ret = write(fd, str, 4);
    if(ret < 0)
        perror("write() failed");
    else
    printf("write() returned : %d \n",ret);

    close(fd);
    return 0;
}