#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RED "\x1b[31m"    // para errores
#define GREEN "\x1b[32m"  // para datos devueltos por la app
#define YELLOW "\x1b[33m" // para datos ingresados por el usuario
#define BLUE "\x1b[34m"   // para pedidos de la app
#define RESET "\x1b[0m"   // volver al defecto

//==================================================== FUNCIONES GENERALES ===========================================================//
void pedirNumero(int *numero)
{
    int resultado;

    // Bucle hasta que se ingrese un numero valido
    do
    {
        printf(YELLOW);
        resultado = scanf(" %d", numero);
        printf(RESET);

        if (resultado != 1)
        {
            printf(RED "Entrada no valida. Por favor, ingresa un numero.\n" RESET);

            // Limpiar el buffer de entrada
            while (getchar() != '\n');
        }

    } while (resultado != 1);

    // Limpiar el buffer de entrada (por si queda un '\n')
    while (getchar() != '\n');
}
//==================================================== FUNCIONES CAMBIO DE BASE ===========================================================//

int binarioDecimal(int decimal)
{
    int sumador = 0, asignado = decimal, numero = 0;
    while (decimal != 1)
    {
        if (decimal % 10 == 1)
        {
            numero += pow(2, sumador);
        }
        sumador++;
        decimal = decimal / 10;
    }
    numero += pow(2, sumador);
    return printf("El numero binario %d en decimal es : %d \n", asignado, numero);
}

int octalDecimal(int decimal)
{
    int sumador = 0, asignado = decimal, numero = 0;
    while (decimal != 1)
    {
        if (decimal % 10 == 1)
        {
            numero += pow(8, sumador);
        }
        sumador++;
        decimal = decimal / 10;
    }
    numero += pow(2, sumador);
    return printf("El numero octal %d en decimal es : %d \n", asignado, numero);
}

int binario(int num)
{
    int sumador = 0, asignador = num;
    while (asignador > 0)
    {
        sumador++;
        asignador = asignador / 2;
    }
    int size[sumador];

    for (int it = sumador - 1; it >= 0; it--)
    {
        size[it] = num % 2;
        num = num / 2;
    }

    printf("El numero en binario es: ");
    for (int iter = 0; iter < sumador; iter++)
    {
        printf("%d", size[iter]);
    }
    printf("\n");
}

int octal(int num)
{
    int sumador = 0, asignador = num;
    while (asignador > 0)
    {
        sumador++;
        asignador = asignador / 8;
    }
    int size[sumador];

    for (int it = sumador - 1; it >= 0; it--)
    {
        size[it] = num % 8;
        num = num / 8;
    }

    printf("El numero en octal es: ");
    for (int iter = 0; iter < sumador; iter++)
    {
        printf("%d", size[iter]);
    }
    printf("\n");
}

int hexadecimal(int num)
{
    int sumador = 0, asignador = num;
    while (asignador > 0)
    {
        sumador++;
        asignador = asignador / 16;
    }
    int size[sumador];

    for (int it = sumador - 1; it >= 0; it--)
    {
        size[it] = num % 16;
        num = num / 16;
    }

    printf("El numero en hexadecimal es: ");
    for (int iter = 0; iter < sumador; iter++)
    {
        if (9 < size[iter])
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
        }
        else
        {
            printf("%d", size[iter]);
        }
    }
    printf("\n");
}

int hexaDecimalaDecimal(int decimal)
{
    int sumador = 0, asignado = decimal, numero = 0;
    while (decimal != 1)
    {
        if (decimal % 10 == 1)
        {
            numero += pow(16, sumador);
        }
        sumador++;
        decimal = decimal / 10;
    }
    numero += pow(16, sumador);
    return printf("El numero hexadecimal %d en decimal es : %d \n", asignado, numero);
}

int binarioaOctal(int binario)
{

    int sumador = 0, asignado = binario, numero = 0;
    while (binario != 1)
    {
        if (binario % 10 == 1)
        {
            numero += pow(2, sumador);
        }
        sumador++;
        binario = binario / 10;
    }
    numero += pow(2, sumador);
    octal(numero);
}

int binarioaHexa(int binario)
{
    int sumador = 0, asignado = binario, numero = 0;
    while (binario != 1)
    {
        if (binario % 10 == 1)
        {
            numero += pow(2, sumador);
        }
        sumador++;
        binario = binario / 10;
    }
    numero += pow(2, sumador);
    hexadecimal(numero);
}

int octalaBinario(int decimal)
{
    int sumador = 0, asignado = decimal, numero = 0;
    while (decimal != 1)
    {
        if (decimal % 10 == 1)
        {
            numero += pow(8, sumador);
        }
        sumador++;
        decimal = decimal / 10;
    }
    numero += pow(2, sumador);
    binario(numero);
}

int octalaHexa(int decimal)
{
    int sumador = 0, asignado = decimal, numero = 0;
    while (decimal != 1)
    {
        if (decimal % 10 == 1)
        {
            numero += pow(8, sumador);
        }
        sumador++;
        decimal = decimal / 10;
    }
    numero += pow(2, sumador);
    hexadecimal(numero);
}

// ======================================================== FUNCIONES PARA MATRICES ========================================================//
// Funcion para cargar la matriz
void RecorrerMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf(BLUE "Ingrese el numero de la fila %d columna %d de la matriz: " RESET, i + 1, j + 1);
            pedirNumero(&matriz[i][j]);
        }
    }
}
// Función para mostrar la matriz
void MostrarMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf(GREEN "%d " RESET, matriz[i][j]);
        }
        printf("\n");
    }
}
// Funcion para sumar la matriz
void sumaMatriz(int filas, int columnas, int matriz_1[filas][columnas], int matriz_2[filas][columnas], int matriz_final[filas][columnas])
{

    for (int i = 0; i < filas; i++)
    {
        for (int it = 0; it < columnas; it++)
        {
            matriz_final[i][it] = matriz_1[i][it] + matriz_2[i][it];
        }
    }
};
// Funcion para restar la matriz
void restarMatriz(int filas, int columnas, int matriz_1[filas][columnas], int matriz_2[filas][columnas], int matriz_final[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int it = 0; it < columnas; it++)
        {
            matriz_final[i][it] = matriz_1[i][it] - matriz_2[i][it];
        }
    }
};
// Funcion para multiplicar las matrices.
void multiplicarMatrices(int filas, int columnas, int matriz_1[filas][columnas], int matriz_2[filas][columnas], int matriz_final[filas][columnas])
{ // Inicialización de la matriz final en 0
/*    for (int i = 0; i < filas_1; i++) {
        for (int j = 0; j < columnas_2; j++) {
            matriz_final[i][j] = 0;
        }
    }

    // Multiplicación de matrices
    for (int i = 0; i < filas_1; i++) {
        for (int j = 0; j < columnas_2; j++) {
            for (int k = 0; k < columnas_1; k++) {
                matriz_final[i][j] += matriz_1[i][k] * matriz_2[k][j];}}}*/}
// Funcion para sacar la transpuesta.
void transpuestaMatriz(int filas, int columnas, int matriz[filas][columnas], int matriz_final[columnas][filas])
{
    for (int i = 0; i < columnas; i++)
    {
        for (int it = 0; it < filas; it++)
        {
            matriz_final[it][i] = matriz[i][it];
        }
    }
}
//======================================================= FIN FUNCIONES PARA MATRICES ==========================================================//

int main()
{
    // GENERAL.
    int tipo_calculadora;
    // PARA MATRICES.
    int filas, columnas, opcion, bien_ingresado;
    // PARA CAMBIO DE BASE.
    int numero;

    printf(BLUE "Bienvenido, soy una calculadora de matrices y un conversor de bases.\n" RESET);
    //-------------------------------------------------  MENU  --------------------------------------------------------------------//
    int terminar = 1;
    do
    {
        do
        {
            printf(BLUE "Elija que funcionalidad quiere usar:\n 1_calculadora de matrices.\n 2_cambio de base.\n Digite su eleccion: " RESET);
            pedirNumero(&tipo_calculadora);
            if (tipo_calculadora < 1 || tipo_calculadora > 2)
            {
                printf(RED "Error, ingrese una opcion valida. " RESET);
            }
        } while (tipo_calculadora < 1 || tipo_calculadora > 2);

        if (tipo_calculadora == 1)
        {
            int salir = 1;
            do
            {
                do
                {
                    printf(BLUE "Opciones: \n 1_Suma de dos matrices \n 2_Resta de dos matrices. \n 3_Multiplicacion de matricez.\n 4_Mostrar matriz transpuesta.\n 5_Mostrar matriz inversa. \n Digite su eleccion: " RESET);
                    pedirNumero(&opcion);
                    if (opcion < 1 || opcion > 5)
                    {
                        printf(RED "Error, ingrese una opcion valida.\n" RESET);
                    }
                } while (opcion < 1 || opcion > 5);

                //-------------------------------------------------  Salida de Opciones  --------------------------------------------------------------------//

                // Pedir dimensiones de la matriz
                printf(BLUE "Ingrese la cantidad de filas de la matriz: " RESET);
                do
                {
                    pedirNumero(&filas);
                    if (filas <= 1)
                    {
                        printf(RED "Error, ingrese una cantidad de filas valida.");
                        printf("Ingrese un numero positivo mayor a 1\n" RESET);
                    }

                } while (filas <= 1);

                printf(BLUE "Ingrese la cantidad de columnas de la matriz: " RESET);
                do
                {
                    pedirNumero(&columnas);
                    if (columnas <= 1)
                    {
                        printf(RED "Error, ingrese una cantidad de columnas valida.");
                        printf("Ingrese un numero positivo mayor a 1\n" RESET);
                    }
                } while (columnas <= 1);

                int matriz_1[filas][columnas], matriz_2[filas][columnas], matriz_final[filas][columnas];

                // Validar si necesita 1 0 2 matrices.

                if (opcion > 3)
                {
                    do
                    {
                        printf(GREEN "Primer matriz.\n" RESET);
                        RecorrerMatriz(filas, columnas, matriz_1);
                        printf(GREEN "Matriz ingresada:\n");
                        MostrarMatriz(filas, columnas, matriz_1);
                        printf(RESET);
                        printf(BLUE "Ingresado correctamente 1_Si 2_No: " RESET);
                        do
                        {
                            pedirNumero(&bien_ingresado);
                            if (bien_ingresado != 1 && bien_ingresado != 2)
                            {
                                printf(RED "No ah ingresado ninguna de las opciones validas, Ingrese 1 o 2:\n" RESET);
                            }
                        } while (bien_ingresado != 1 && bien_ingresado != 2);
                        if (bien_ingresado == 2)
                        {
                            printf(BLUE "Reiniciamos la matriz,ya puede ingresarla nuevamente.\n" RESET);
                        }
                    } while (bien_ingresado == 2);
                }
                else
                {
                    do
                    {
                        printf(GREEN "Primer matriz.\n" RESET);
                        RecorrerMatriz(filas, columnas, matriz_1);
                        printf(GREEN "Matriz ingresada:\n");
                        MostrarMatriz(filas, columnas, matriz_1);
                        printf(RESET);
                        printf(BLUE "Ingresado correctamente 1_Si 2_No: " RESET);
                        do
                        {
                            pedirNumero(&bien_ingresado);
                            if (bien_ingresado != 1 && bien_ingresado != 2)
                            {
                                printf(RED "No ah ingresado ninguna de las opciones validas, Ingrese 1 o 2:\n" RESET);
                            }
                        } while (bien_ingresado != 1 && bien_ingresado != 2);
                        if (bien_ingresado == 2)
                        {
                            printf(BLUE "Reiniciamos la matriz,ya puede ingresarla nuevamente.\n" RESET);
                        }
                    } while (bien_ingresado == 2);

                    do
                    {
                        printf(GREEN "Segunda matriz.\n" RESET);
                        RecorrerMatriz(filas, columnas, matriz_2);
                        printf(GREEN "Matriz ingresada:\n");
                        MostrarMatriz(filas, columnas, matriz_2);
                        printf(RESET);
                        printf(BLUE "Ingresado correctamente 1_Si 2_No: " RESET);
                        do
                        {
                            pedirNumero(&bien_ingresado);
                            if (bien_ingresado != 1 && bien_ingresado != 2)
                            {
                                printf(RED "No ah ingresado ninguna de las opciones validas, Ingrese 1 o 2:\n" RESET);
                            }
                        } while (bien_ingresado != 1 && bien_ingresado != 2);
                        if (bien_ingresado == 2)
                        {
                            printf(BLUE "Reiniciamos la matriz,ya puede ingresarla nuevamente.\n" RESET);
                        }
                    } while (bien_ingresado == 2);
                }

                switch (opcion)
                {
                case 1:
                    sumaMatriz(filas, columnas, matriz_1, matriz_2, matriz_final);
                    printf(GREEN "Matriz resultante:\n");
                    MostrarMatriz(filas, columnas, matriz_final);
                    printf(RESET);
                    break;
                case 2:
                    restarMatriz(filas, columnas, matriz_1, matriz_2, matriz_final);
                    printf(GREEN "Matriz resultante:\n");
                    MostrarMatriz(filas, columnas, matriz_final);
                    printf(RESET);
                    break;
                case 3:
                    multiplicarMatrices(filas, columnas, matriz_1, matriz_2, matriz_final);
                    printf("Matriz resultante");
                    MostrarMatriz(filas, columnas, matriz_final);
                case 4:
                    transpuestaMatriz(filas, columnas, matriz_1, matriz_final);
                    MostrarMatriz(filas, columnas, matriz_final);
                    break;
                default:

                    break;
                }
                printf(BLUE "desea salir de la calculadora de matrizes? si= 0 no= 'ingrese cualquier numero': " RESET);
                pedirNumero(&salir);
            } while (salir != 0);
        }
        else
        {
            int salirBases = 1;
            do
            {
                printf(BLUE "Bienvenido al conversor de bases." RESET);

                printf(BLUE "Que quieres convertir \n 1_Binario.\n 2_Octal\n 3_Decimal\n 4_Hexadecimal\n Digite su eleccion: " RESET);
                pedirNumero(&opcion);
                printf(BLUE "Ingrese el numero : " RESET);
                pedirNumero(&numero);
                switch (opcion)
                {
                case 1:
                    printf(GREEN);
                    binarioDecimal(numero);
                    binarioaOctal(numero);
                    binarioaHexa(numero);
                    printf(RESET);
                    break;
                case 2:
                    printf(GREEN);
                    octalDecimal(numero);
                    octalaBinario(numero);
                    octalaHexa(numero);
                    printf(RESET);
                    break;
                case 3:
                    printf(GREEN);
                    binario(numero);
                    octal(numero);
                    hexadecimal(numero);
                    printf(RESET);
                    break;
                case 4:
                    printf(GREEN);
                    hexaDecimalaDecimal(numero);
                    printf(RESET);
                    break;
                default:
                    break;
                }
                printf(BLUE "desea salir del convertidor de bases?\n si= 0 no= 'ingrese cualquier numero': " RESET);
                pedirNumero(&salirBases);
            } while (salirBases != 0);
        }
        printf(BLUE "Quiere salir del programa?\n si=0 no='ingrese cualquier numero': " RESET);
        pedirNumero(&terminar);
    } while (terminar != 0);

    system("pause");
    return 0;
}