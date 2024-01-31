#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include "pchar.h"

int main() {
	int fd;
	long ret;
	char str[32];
	info_t info;
	unsigned long newsize = 64;

	fd = open("/dev/pchar0", O_RDWR);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: size=%d, length=%d, avail=%d\n", info.size, info.len, info.avail); // size=32, length=0, avail=32

	strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ret = write(fd, str, 26);
	printf("write() returned: %d\n", ret); // 26

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: size=%d, length=%d, avail=%d\n", info.size, info.len, info.avail); // size=32, length=26, avail=6

	ret = ioctl(fd, FIFO_CLEAR, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer cleared.\n");

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: size=%d, length=%d, avail=%d\n", info.size, info.len, info.avail); // size=32, length=0, avail=32

	strcpy(str, "0123456789");
	ret = write(fd, str, 10);
	printf("write() returned: %d\n", ret); // 10

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: size=%d, length=%d, avail=%d\n", info.size, info.len, info.avail); // size=32, length=10, avail=22

	memset(str, 0, 32);
	ret = read(fd, str, 32);
	printf("read() returned: %d = %s\n", ret, str); // 0...9

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: size=%d, length=%d, avail=%d\n", info.size, info.len, info.avail); // size=32, length=0, avail=32

	
	ret = ioctl(fd, FIFO_RESIZE, newsize);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: size=%d, length=%d, avail=%d\n", info.size, info.len, info.avail);
	
	
	close(fd);
	return 0;
}

