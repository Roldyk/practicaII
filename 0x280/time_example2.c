#include <stdio.h>
#include <time.h>

void dump_time_struct_bytes(struct tm *time_ptr, int size) {
    int i;
    unsigned char *raw_ptr;

    printf("Bytes of struct located at 0x%08lx\n", (unsigned long)time_ptr);
    raw_ptr = (unsigned char *)time_ptr;

    for (i = 0; i < size; i++) {
        printf("%02x ", raw_ptr[i]);
        if (i % 16 == 15)
            printf("\n"); // Print a newline every 16 bytes.
    }
    printf("\n");
}

int main() {
    long int seconds_since_epoch;
    struct tm current_time, *time_ptr;
    int hour, minute, second, i, *int_ptr;

    seconds_since_epoch = time(0); // Get the current time in seconds since epoch.
    printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);

    time_ptr = &current_time; // Set time_ptr to the address of the current_time struct.
    localtime_r(&seconds_since_epoch, time_ptr);

    // Three different ways to access struct elements:
    hour = current_time.tm_hour;    // Direct access.
    minute = time_ptr->tm_min;      // Access via pointer.
    second = *((int *)time_ptr);    // Hacky pointer access.

    printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);

    dump_time_struct_bytes(time_ptr, sizeof(struct tm));

    minute = hour = 0; // Clear out minute and hour.

    int_ptr = (int *)time_ptr;
    for (i = 0; i < 3; i++) {
        printf("int_ptr @ 0x%08lx : %d\n", (unsigned long)int_ptr, *int_ptr);
        int_ptr++; // Adding 1 to int_ptr adds 4 to the address, as an int is 4 bytes in size.
    }

    return 0;
}

