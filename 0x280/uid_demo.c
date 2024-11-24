#include <stdio.h>
#include <unistd.h>  // Include the header for getuid() and geteuid()

int main() {
    printf("real uid: %d\n", getuid());     // Print the real user ID
    printf("effective uid: %d\n", geteuid()); // Print the effective user ID
    return 0;
}

