#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binario(int num){
int sumador = 0,asignador = num;
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
    printf("\n");}

int octal(int num){
int sumador = 0,asignador = num;
      while (asignador > 0)
    {sumador++;
     asignador = asignador / 8; } 
    int size[sumador];

    for (int it = sumador - 1; it >= 0; it--)
    {   size[it]= num % 8;
        num = num / 8; }

    printf("El numero en octal es: ");
    for (int iter = 0; iter < sumador; iter++) {
        printf("%d", size[iter]);
    }
    printf("\n");

}

int hexadecimal(int num){
int sumador = 0,asignador = num;
      while (asignador > 0)
    {sumador++;
     asignador = asignador / 16; } 
    int size[sumador];

    for (int it = sumador - 1; it >= 0; it--)
    {   size[it]= num % 16;
        num = num / 16; }

    printf("El numero en hexadecimal es: ");
    for (int iter = 0; iter < sumador; iter++) {
        if ( 9 < size[iter] )
        {
            switch (size[iter])
            {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
            break;
            case 12:
                printf("C");
            break;
            case 13:
                printf("D");
            break;
            case 14:
                printf("E");
            break;
            case 15:
                printf("F");
            break;
            default:
                break;
            }
        }else{printf("%d", size[iter]);}
        
        
    }
    printf("\n");

}

int binarioDecimal(int decimal){
    int sumador = 0,asignado = decimal,numero = 0;
    while (decimal != 1)
    {
       if (decimal % 10 == 1)
        { numero += pow(2,sumador);}
        sumador++;
        decimal = decimal / 10;
       
    }
    numero += pow(2,sumador);
    return printf("El numero binario %d en decimal es : %d \n",asignado,numero);
}

int octalDecimal( int decimal){
       int sumador = 0,asignado = decimal,numero = 0;
    while (decimal > 8)
    {
        asignado = decimal % 10;
         numero +=asignado * pow(8,sumador);
        sumador++;
        decimal = decimal / 10;
       
    }
    numero += decimal;
    return printf("El numero octal %d en decimal es : %d \n",asignado,numero);
}
int hexaDecimal(int decimal){
    int sumador = 0,asignado = decimal,numero = 0;
    while (decimal != 1)
    {
       if (decimal % 10 == 1)
        { numero += pow(16,sumador);}
        sumador++;
        decimal = decimal / 10;
       
    }
    numero += pow(16,sumador);
    return printf("El numero hexadecimal %d en decimal es : %d \n",asignado,numero);}

int binarioaOctal(int binario){

 int sumador = 0,asignado = binario,numero = 0;
    while (binario != 1)
    {
       if (binario % 10 == 1)
        { numero += pow(2,sumador);}
        sumador++;
        binario = binario / 10;
       
    }
    numero += pow(2,sumador);
    octal(numero);
}

int  binarioaHexa(int decimal){

     int sumador = 0,asignado = decimal,numero = 0;
    while (decimal != 1)
    {
       if (decimal % 10 == 1)
        { numero += pow(16,sumador);}
        sumador++;
        decimal = decimal / 10;
       
    }
    numero += pow(16,sumador);
    hexadecimal(numero);
}

int octalabinario(int decimal){
int sumador = 0,asignado = decimal,numero = 0;
    while (decimal != 1)
    {
       if (decimal % 10 == 1)
        { numero += pow(8,sumador);}
        sumador++;
        decimal = decimal / 10;
       
    }
    numero += pow(2,sumador);
    binario(numero);
}


int main() {
   int octale = 15 ;

    octalDecimal(octale);

    system("pause");
    return 0;
}

