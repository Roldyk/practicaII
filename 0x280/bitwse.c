#include <stdio.h>

int main() {
    int i, bit_a, bit_b;

    // Imprime el resultado de la operación OR bit a bit
    printf("bitwise OR operator |\n");
    for(i = 0; i < 4; i++) {
        bit_a = (i & 2) / 2; // Obtiene el segundo bit.
        bit_b = (i & 1);     // Obtiene el primer bit.
        printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
    }

    // Imprime el resultado de la operación AND bit a bit
    printf("\nbitwise AND operator &\n");
    for(i = 0; i < 4; i++) {
        bit_a = (i & 2) / 2; // Obtiene el segundo bit.
        bit_b = (i & 1);     // Obtiene el primer bit.
        printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
    }

    return 0;
}

