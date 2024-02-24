#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Specify the file path
    const char *file_path = "demo.txt";

    // Open the file in write-only mode, creating it if it doesn't exist
    // The file permissions are set to 0666 (read and write ,exicute , for owner, group, and others)
    int file_descriptor = open(file_path, O_WRONLY | O_CREAT, 0777);

    printf("File Descripter : %u \n",file_descriptor);

    // Check if the file was opened successfully
    if (file_descriptor == -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    // Write a message to the file
    const char *message = "Hello, open() system call!\n";
    ssize_t bytes_written = write(file_descriptor, message, strlen(message));

    // Check if the write operation was successful
    if (bytes_written == -1) {
        perror("Error writing to the file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(file_descriptor);

    printf("File '%s' has been created and written to successfully.\n", file_path);

    return 0;
}
