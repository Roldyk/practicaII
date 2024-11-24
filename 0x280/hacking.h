#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to display an error message and then exit
void fatal(const char *message) {
    char error_message[100];
    
    // Safely concatenate error message using snprintf
    snprintf(error_message, sizeof(error_message), "[!!] Fatal Error %s", message);
    
    // Print the error message to stderr
    fprintf(stderr, "%s\n", error_message);
    
    // Exit the program with a failure status
    exit(EXIT_FAILURE);
}

// An error-checked malloc() wrapper function
void *ec_malloc(unsigned int size) {
    void *ptr = malloc(size);
    
    // If memory allocation fails, call fatal() to report and exit
    if (ptr == NULL)
        fatal("in ec_malloc() on memory allocation");
    
    return ptr;
}

