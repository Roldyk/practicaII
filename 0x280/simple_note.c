#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h> // Para close()

void usage(char *prog_name, char *filename) {
    printf("Usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *message) {
    char error_message[100];
    snprintf(error_message, sizeof(error_message), "[!!] Fatal Error: %s", message);
    perror(error_message);
    exit(-1);
}

void *ec_malloc(unsigned int size) {
    void *ptr = malloc(size);
    if (ptr == NULL)
        fatal("in ec_malloc() on memory allocation");
    return ptr;
}

int main(int argc, char *argv[]) {
    int fd; // File descriptor
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);

    strncpy(datafile, "/tmp/notes", 19);
    datafile[19] = '\0'; // Asegurarse de que termine en '\0'

    if (argc < 2) // Si no hay argumentos en la línea de comandos
        usage(argv[0], datafile);

    if (strlen(argv[1]) >= 99) { // Validar tamaño del argumento
        fprintf(stderr, "Error: Input data is too large.\n");
        free(buffer);
        free(datafile);
        exit(-1);
    }

    strncpy(buffer, argv[1], 99);
    buffer[99] = '\0'; // Asegurarse de que termine en '\0'

    printf("[DEBUG] buffer @ %p: '%s'\n", (void *)buffer, buffer);
    printf("[DEBUG] datafile @ %p: '%s'\n", (void *)datafile, datafile);

    strncat(buffer, "\n", 99 - strlen(buffer)); // Añadir un salto de línea al final

    // Abrir archivo
    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");

    printf("[DEBUG] file descriptor is %d\n", fd);

    // Escribir datos en el archivo
    if (write(fd, buffer, strlen(buffer)) == -1)
        fatal("in main() while writing buffer to file");

    // Cerrar archivo
    if (close(fd) == -1)
        fatal("in main() while closing file");

    printf("Note has been saved.\n");

    // Liberar memoria
    free(buffer);
    free(datafile);

    return 0;
}

