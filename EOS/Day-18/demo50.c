#include <stdio.h>
#include <unistd.h>

int main() {
	int i;
	for(i=1; i<=20; i++) {
		printf("running: %d\n", i);
		sleep(1);
	}
	return 0;
}

