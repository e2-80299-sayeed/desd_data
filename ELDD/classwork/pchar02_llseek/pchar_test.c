#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd, ret;
    char str[33];

    fd = open("/dev/pchar0", O_RDWR);
    if(fd < 0)
    {
        perror("open() failed");
        _exit(1);
    }

    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345");
    ret = write(fd, str, 32);
    printf("write() returned: %d\n",ret);

    lseek(fd, 0, SEEK_SET);
    memset(str, 0, 32);
    ret = read(fd, str, 26);
    printf("read() retutrned : %d = %s\n", ret, str);

    lseek(fd, -5, SEEK_END);
    memset(str, 0, 32);
    ret = read(fd, str, 10);
    printf("read() retutrned : %d = %s\n", ret, str);

    lseek(fd, 26, SEEK_SET);
    lseek(fd, -3, SEEK_CUR);

    memset(str, 0, 32);
    ret = read(fd, str, 3);
    printf("read() retutrned : %d = %s\n", ret, str);
    
    close(fd);
    return 0;
}
