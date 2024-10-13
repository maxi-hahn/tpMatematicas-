
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hexa[99];

    // Leer la entrada del usuario
    scanf("%s", hexa);  // Limitar la entrada a 2 caracteres para evitar desbordamiento

    // Convertir la cadena hexadecimal a un valor decimal
    int valor_decimal = (int)strtol(hexa, NULL, 16);  // Convertir de hexadecimal a decimal

    // Imprimir el valor decimal
    printf("%d\n", valor_decimal);

    return 0;
}