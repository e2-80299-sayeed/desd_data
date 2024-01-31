#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fd, ret;
	char str[33];

	fd = open("/dev/pchar0", O_RDWR);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}
	
	strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345");
	ret = write(fd, str, 36);
	printf("write() returned: %d\n", ret); // 32

	lseek(fd, 0, SEEK_SET); // take file pos to start of file
	memset(str, 0, 32);
	ret = read(fd, str, 26);
	printf("read() returned: %d = %s\n", ret, str); // 26 = A...Z

	lseek(fd, -5, SEEK_END); // take file pos 5 bytes behind end of file
	memset(str, 0, 32);
	ret = read(fd, str, 10);
	printf("read() returned: %d = %s\n", ret, str); // 5 = 1...5

	lseek(fd, 26, SEEK_SET); // take file pos to 26
	lseek(fd, -3, SEEK_CUR); // take file pos 3 bytes behind current pos
	memset(str, 0, 32);
	ret = read(fd, str, 3);
	printf("read() returned: %d = %s\n", ret, str); // 3 = XYZ

	close(fd);
	return 0;
}

