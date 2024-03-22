#include <stdio.h>      // Standard input-output library
#include <stdlib.h>     // Standard library
#include <fcntl.h>      // File control options
#include <unistd.h>     // Symbolic constants and types

int main() {
    int file_descriptor;        // File descriptor for the file

    // Open a file named "example.txt" with read-write permissions
    // If the file doesn't exist, create it. If it exists, truncate it.
    file_descriptor = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    
    // Check if file opening was successful
    if (file_descriptor == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Write "Hello world" into the file
    if (write(file_descriptor, "Hello world", 11) == -1) {
        perror("Error writing to file");
        return EXIT_FAILURE;
    }

    // Move the file pointer to the beginning of the file
    if (lseek(file_descriptor, 0, SEEK_SET) == -1) {
        perror("Error seeking file");
        return EXIT_FAILURE;
    }

    char buffer[12];    // Buffer to hold the read data
    // Read data from the file into the buffer
    if (read(file_descriptor, buffer, 11) == -1) {
        perror("Error reading from file");
        return EXIT_FAILURE;
    }

    // Null-terminate the buffer to treat it as a string
    buffer[11] = '\0';

    // Print the read content
    printf("Content read from file: %s\n", buffer);

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

