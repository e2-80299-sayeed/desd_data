#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
	DIR *dp;
	struct dirent *ent;
	
	dp = opendir("/home/sunbeam");
	if(dp == NULL) {
		perror("failed to open dir");
		exit(1);
	}

	while( (ent = readdir(dp)) != NULL ) {
		printf("%lu, %s\n", ent->d_ino, ent->d_name);
	}

	closedir(dp);
	return 0;
}

