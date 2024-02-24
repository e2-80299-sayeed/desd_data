#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void run_process(char process_name, int seconds) {
    printf("Process %c (PID %d) is running.\n", process_name, getpid());
    sleep(seconds);
    printf("Process %c (PID %d) is done.\n", process_name, getpid());
}

int main() {
    pid_t pidB, pidC, pidD;

    // Process A (parent)
    printf("Process A (PID %d) is running.\n", getpid());

    // Process B (child of A)
    pidB = fork();
    if (pidB < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pidB == 0) {
        // Child process B
        run_process('B', 5);

        // Process C (child of B)
        pidC = fork();
        if (pidC < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pidC == 0) {
            // Child process C
            run_process('C', 5);

            // Process D (child of C)
            pidD = fork();
            if (pidD < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pidD == 0) {
                // Child process D
                run_process('D', 5);
                exit(EXIT_SUCCESS);
            }

            // Wait for process D to complete
            wait(NULL);
            exit(EXIT_SUCCESS);
        }

        // Wait for process C to complete
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    // Wait for process B to complete
    wait(NULL);
    printf("All processes have completed.\n");

    return 0;
}
