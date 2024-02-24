#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Print File Descripter
//Read System Call Demo

int main() {
    // Specify the file path
    const char *file_path = "demo.txt";

    // Open the file in read-only mode
    int file_descriptor = open(file_path, O_RDONLY);

    // Check if the file was opened successfully
    if (file_descriptor == -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    // Read data from the file
    char buffer[100];  // Buffer to store the read data
    ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer));

    // Check if the read operation was successful
    if (bytes_read == -1) {
        perror("Error reading from the file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(file_descriptor);

    // Print the read data
    printf("Read from file: %s \n",buffer);
    printf("Read from file: %ld", bytes_read );

    return 0;
}
