#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fd, ret;
	char str[32];

	fd = open("/dev/pchar0", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}
	
	strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ret = write(fd, str, 26);
	printf("write() returned: %d\n", ret); // 26

	strcpy(str, "0123456789");
	ret = write(fd, str, 10);
	printf("write() returned: %d\n", ret); // 6

	strcpy(str, "ogod");
	ret = write(fd, str, 4);
	if(ret < 0)
		perror("write() failed");
	else
		printf("write() returned: %d\n", ret); // 0

	close(fd);

	fd = open("/dev/pchar0", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}
	
	memset(str, 0, 32);
	ret = read(fd, str, 26);
	printf("read() returned: %d = %s\n", ret, str); // 26 = A...Z

	memset(str, 0, 32);
	ret = read(fd, str, 10);
	printf("read() returned: %d = %s\n", ret, str); // 6 = 0...5

	memset(str, 0, 32);
	ret = read(fd, str, 4);
	printf("read() returned: %d = %s\n", ret, str); // 0 = 

	close(fd);
	return 0;
}

