#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("SIGINT received!\n");
}

int main() {
    int i=0, ret;
    sigset_t set;
    printf("program started!\n");
    signal(SIGINT, sigint_handler);

    sigfillset(&set);           // 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111  
    sigdelset(&set, SIGINT);    // 10111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111  
    sigdelset(&set, SIGTERM);   // 10111111 11111101 11111111 11111111 11111111 11111111 11111111 11111111  
    printf("waiting for SIGINT or SIGTERM signal...\n");
    sigsuspend(&set);
        // 1. take backup of current mask field (all signals allowed)
        // 2. set given mask field
        // 3. pause execution of the process until one of the unmasked signal is received
        // 4. resume process and set old (backup) mask field again
    
    printf("program running!\n");


    sigemptyset(&set);         // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    printf("waiting for any signal (all are unmasked)...\n");
    sigsuspend(&set);

    printf("program running again!\n");

    printf("waiting for any signal (all are unmasked)...\n");
    pause(); // waiting for any signal that will terminate the process
                // or will execute the implemented handler.

    printf("program completed!\n");
    return 0;
}








