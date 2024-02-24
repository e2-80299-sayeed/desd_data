#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// parent A -> child B -> child C
int main() {
    int i, pidb, sb, pidc, sc;

    // parent a
    pidb = fork();
    if(pidb == 0) { 
        // child b
        pidc = fork();
        if(pidc == 0) {
            // child c
            for(i=1; i<=5; i++) {
                printf("C. sunbeam desd: %d\n", i);
                sleep(1);
            }
            _exit(0);
        }
        
        // child b
        for(i=1; i<=5; i++) {
            printf("B. sunbeam pune: %d\n", i);
            sleep(1);
        }
        waitpid(pidc, &sc, 0);
        _exit(0);
    }

    // parent a
    for(i=1; i<=5; i++) {
        printf("A. sunbeam: %d\n", i);
        sleep(1);
    }
    waitpid(pidb, &sb, 0);

    return 0;
}
