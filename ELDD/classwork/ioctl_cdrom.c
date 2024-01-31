#include<unistd.h>
#include<stdio.h>
#include<linux/cdrom.h>
#include<fcntl.h>
#include<sys/ioctl.h>

int main()
{
    int fd;

    fd = open("/dev/sr0", O_RDWR | O_NONBLOCK );
    
    ioctl(fd, CDROMEJECT, 0);

    close(fd);
    return 0;
}