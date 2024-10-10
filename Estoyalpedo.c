#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 18,sumador = 0,asignador = num;

    while (asignador > 0)
    {sumador++;
     asignador = asignador / 2; } 
    int size[sumador];

    for (int it = sumador - 1; it >= 0; it--)
    {   size[it]= num % 2;
        num = num / 2; }

   printf("El numero en binario es: ");
    for (int iter = 0; iter < sumador; iter++) {
        printf("%d", size[iter]);
    }
    printf("\n");

    
    
    system("pause");
    return 0;
}

//asdsad