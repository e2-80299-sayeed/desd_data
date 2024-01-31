#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

typedef struct info{
    char type[10];
    int buf_len;
    char device[10];
 
}info_t;

#define FIFO_GET_INFO _IOR('x', 2, info_t*)

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
	printf("device buffer: type=%s, buf_len=%d, device = %s\n", info.type, info.buf_len, info.device);

	strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ret = write(fd, str, 26);
	printf("write() returned: %d\n", ret); // 26

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: type=%s, buf_len=%d, device = %s\n", info.type, info.buf_len, info.device);

	strcpy(str, "0123456789");
	ret = write(fd, str, 10);
	printf("write() returned: %d\n", ret); // 10

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: type=%s, buf_len=%d, device = %s\n", info.type, info.buf_len, info.device);
	
	memset(str, 0, 32);
	ret = read(fd, str, 32);
	printf("read() returned: %d = %s\n", ret, str); // 0...9

	ret = ioctl(fd, FIFO_GET_INFO, &info);
	if(ret < 0) {
		perror("ioctl() failed");
		_exit(2);
	}
	printf("device buffer: type=%s, buf_len=%d, device = %s\n", info.type, info.buf_len, info.device);

	
		
	close(fd);
	return 0;
}

