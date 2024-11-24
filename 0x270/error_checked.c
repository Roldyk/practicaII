#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_malloc(unsigned int size);

int main(int argc, char *argv[]) {
    char *char_ptr; 
    int *int_ptr; 
    int mem_size;

    if (argc < 2) 
        mem_size = 50; 
    else
        mem_size = atoi(argv[1]);

    if (mem_size <= 0) {
        fprintf(stderr, "Error: Invalid memory size provided.\n");
        exit(-1);
    }

    printf("\t[+] Allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) errorchecked_malloc(mem_size);
    
    if (mem_size < strlen("This is memory is located on the heap.") + 1) {
        fprintf(stderr, "Error: Insufficient memory allocated for char_ptr.\n");
        free(char_ptr);
        exit(-1);
    }

    strncpy(char_ptr, "This is memory is located on the heap.", mem_size - 1);
    char_ptr[mem_size - 1] = '\0'; // Ensure null termination

    printf("char_ptr (%p) --> '%s'\n", (void *)char_ptr, char_ptr);

    printf("\t[+] Allocating 12 bytes of memory on the heap for int_ptr\n");
    int_ptr = (int *) errorchecked_malloc(12);
    *int_ptr = 31337;

    printf("int_ptr (%p) --> %d\n", (void *)int_ptr, *int_ptr);

    printf("\t[-] Freeing char_ptr's heap memory...\n");
    free(char_ptr);

    printf("\t[+] Allocating another 15 bytes for char_ptr\n");
    char_ptr = (char *) errorchecked_malloc(15);

    strncpy(char_ptr, "new memory", 15 - 1);
    char_ptr[15 - 1] = '\0'; // Ensure null termination

    printf("char_ptr (%p) --> '%s'\n", (void *)char_ptr, char_ptr);

    printf("\t[-] Freeing int_ptr's heap memory...\n");
    free(int_ptr);

    printf("\t[-] Freeing char_ptr's heap memory...\n");
    free(char_ptr);

    return 0;
}

void *errorchecked_malloc(unsigned int size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(-1);
    }
    return ptr;
}

