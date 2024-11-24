#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if (argc < 2) { 
        mem_size = 50; 
    } else {
        mem_size = atoi(argv[1]);
        if (mem_size <= 0) {
            fprintf(stderr, "Error: invalid memory size provided.\n");
            exit(-1);
        }
    }

    printf("\t[+] Allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) malloc(mem_size);
    if (char_ptr == NULL) {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(-1);
    }

    if (mem_size < strlen("This is memory is located on the heap.") + 1) {
        fprintf(stderr, "Error: insufficient memory allocated for char_ptr.\n");
        free(char_ptr);
        exit(-1);
    }

    strncpy(char_ptr, "This is memory is located on the heap.", mem_size - 1);
    char_ptr[mem_size - 1] = '\0';
    printf("char_ptr (%p) --> '%s'\n", (void *)char_ptr, char_ptr);

    printf("\t[+] Allocating 12 bytes of memory on the heap for int_ptr\n");
    int_ptr = (int *) malloc(12);
    if (int_ptr == NULL) {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        free(char_ptr);
        exit(-1);
    }

    *int_ptr = 31337;
    printf("int_ptr (%p) --> %d\n", (void *)int_ptr, *int_ptr);

    printf("\t[-] Freeing char_ptr's heap memory...\n");
    free(char_ptr);

    printf("\t[+] Allocating another 15 bytes for char_ptr\n");
    char_ptr = (char *) malloc(15);
    if (char_ptr == NULL) {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        free(int_ptr);
        exit(-1);
    }

    strncpy(char_ptr, "new memory", 15 - 1);
    char_ptr[15 - 1] = '\0';
    printf("char_ptr (%p) --> '%s'\n", (void *)char_ptr, char_ptr);

    printf("\t[-] Freeing int_ptr's heap memory...\n");
    free(int_ptr);

    printf("\t[-] Freeing char_ptr's heap memory...\n");
    free(char_ptr);

    return 0;
}

