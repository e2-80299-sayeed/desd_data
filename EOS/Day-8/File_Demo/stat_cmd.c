#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	char path[128];
	struct stat st;
	int ret;
	// input file/dir path from user
	printf("enter file/directory path: ");
	scanf("%[^\n]", path);

	// get info about file/dir
	ret = stat(path, &st);
	if(ret < 0) {
		perror("stat() failed");
		exit(1);
	}

	// display file metadata
	printf("file inode: %lu\n", st.st_ino);
	printf("file size: %lu\n", st.st_size);
	printf("file mode: %o\n", st.st_mode);
	printf("file links: %lu\n", st.st_nlink);
	printf("file user/group: %u/%u\n", st.st_uid, st.st_gid);	
	printf("file block size: %ld\n", st.st_blksize);
	printf("file blocks (512b): %ld\n", st.st_blocks);

	return 0;
}

