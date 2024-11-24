#include <stdio.h>
#include <time.h>

int main() {
    long int seconds_since_epoch;
    struct tm current_time, *time_ptr;
    int hour, minute, second, day, month, year;

    seconds_since_epoch = time(0); // Obtener el tiempo actual en segundos desde el epoch.
    printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);

    time_ptr = &current_time; // Apuntar a la dirección de la estructura current_time.
    localtime_r(&seconds_since_epoch, time_ptr);

    // Tres maneras diferentes de acceder a los elementos de la estructura:
    hour = current_time.tm_hour;    // Acceso directo.
    minute = time_ptr->tm_min;      // Acceso a través de un puntero.
    second = *((int *) time_ptr);   // Acceso "hacky" usando un puntero.

    printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);

    return 0;
}

