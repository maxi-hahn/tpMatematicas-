#include <stdio.h>
#include <stdlib.h>
#define RED     "\x1b[31m" //para errores
#define GREEN   "\x1b[32m" //para datos devueltos por la app
#define YELLOW  "\x1b[33m" //para datos ingresados por el usuario
#define BLUE    "\x1b[34m" //para pedidos de la app
#define RESET   "\x1b[0m"  //volver al defecto

// Funcion para cargar la matriz
void RecorrerMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf(BLUE"Ingrese el numero de la fila %d columna %d de la matriz: "RESET, i + 1, j + 1);
            printf(YELLOW);
            scanf("%d", &matriz[i][j]);
            printf(RESET);
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
            printf(GREEN"%d " RESET, matriz[i][j]);
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
    for (int i = 0; i < filas; i++)
    {
        for (int it = 0; it < columnas; it++)
        {
            matriz_final[it][i] = matriz[i][it];
        }
    }
}

int main()
{
    int filas, columnas, opcion, bien_ingresado;

    printf(BLUE"Bienvenido, soy una calculadora de matrices y un conversor de bases.\n"RESET);
    //-------------------------------------------------  MENU  --------------------------------------------------------------------//

    printf("Elija que funcionalidad quiere usar: 1_calculadora de matrices. 2_cambio de base.");

    do
    {   printf(BLUE"Opciones: \n 1_Suma de dos matrices \n 2_Resta de dos matrices. \n3_Multiplicacion de matricez.\n 4_Mostrar matriz transpuesta.\n 5_Mostrar matriz inversa. \n Digite su eleccion: "RESET);
        printf(YELLOW);
        scanf("%d", &opcion);
        printf(RESET);
        if (opcion < 1 || opcion > 5)
        {
            printf(RED"Error, ingrese una opcion valida.\n"RESET);
        }
    } while (opcion < 1 || opcion > 5);

    //-------------------------------------------------  Salida de Opciones  --------------------------------------------------------------------//

    // Pedir dimensiones de la matriz
    printf(BLUE"Ingrese la cantidad de filas de la matriz: "RESET);
    do
    {
        printf(YELLOW);
        scanf("%d", &filas);
        printf(RESET);
        if (filas <= 1)
        {
            printf(RED"Error, ingrese una cantidad de filas valida.");
            printf("Ingrese un numero positivo mayor a 1\n"RESET);
        }

    } while (filas <= 1);

    printf(BLUE"Ingrese la cantidad de columnas de la matriz: "RESET);
    do
    {
        printf(YELLOW);
        scanf("%d", &columnas);
        printf(RESET);
        if (columnas <= 1)
        {
            printf(RED"Error, ingrese una cantidad de columnas valida.");
            printf("Ingrese un numero positivo mayor a 1\n"RESET);
        }
    } while (columnas <= 1);

    int matriz_1[filas][columnas], matriz_2[filas][columnas], matriz_final[filas][columnas];

    //Validar si necesita 1 0 2 matrices.

    if(opcion > 3){
    do{
        printf(GREEN"Primer matriz.\n"RESET);
        RecorrerMatriz(filas, columnas, matriz_1);
        printf(GREEN"Matriz ingresada:\n");
        MostrarMatriz(filas, columnas, matriz_1);
        printf(RESET);
        printf(BLUE"Ingresado correctamente 1_Si 2_No: "RESET);
        do
        {   
            printf(YELLOW);
            scanf("%d", &bien_ingresado);
            printf(RESET);
            if (bien_ingresado !=1 && bien_ingresado !=2)
            {
                printf(RED"No ah ingresado ninguna de las opciones validas, Ingrese 1 o 2:\n"RESET);
            }   
        } while (bien_ingresado !=1 && bien_ingresado !=2);
        if (bien_ingresado == 2)
        {
            printf(BLUE"Reiniciamos la matriz,ya puede ingresarla nuevamente.\n"RESET);
        }    
    } while (bien_ingresado == 2);

    }else {
         do
    {
        printf(GREEN"Primer matriz.\n"RESET);
        RecorrerMatriz(filas, columnas, matriz_1);
        printf(GREEN"Matriz ingresada:\n");
        MostrarMatriz(filas, columnas, matriz_1);
        printf(RESET);
        printf(BLUE"Ingresado correctamente 1_Si 2_No: "RESET);
        do
        {   
            printf(YELLOW);
            scanf("%d", &bien_ingresado);
            printf(RESET);
            if (bien_ingresado !=1 && bien_ingresado !=2)
            {
                printf(RED"No ah ingresado ninguna de las opciones validas, Ingrese 1 o 2:\n"RESET);
            }   
        } while (bien_ingresado !=1 && bien_ingresado !=2);
        if (bien_ingresado == 2)
        {
            printf(BLUE"Reiniciamos la matriz,ya puede ingresarla nuevamente.\n"RESET);
        }    
    } while (bien_ingresado == 2);

    do
    {
        printf(GREEN"Segunda matriz.\n"RESET);
        RecorrerMatriz(filas, columnas, matriz_2);
        printf(GREEN"Matriz ingresada:\n");
        MostrarMatriz(filas, columnas, matriz_2);
        printf(RESET);
        printf(BLUE"Ingresado correctamente 1_Si 2_No: "RESET);
        do
        {
            printf(YELLOW);
            scanf("%d", &bien_ingresado);
            printf(RESET); 
            if (bien_ingresado !=1 && bien_ingresado !=2)
            {
                printf(RED"No ah ingresado ninguna de las opciones validas, Ingrese 1 o 2:\n"RESET);
            }   
        } while (bien_ingresado !=1 && bien_ingresado !=2);
        if (bien_ingresado == 2)
        {
            printf(BLUE"Reiniciamos la matriz,ya puede ingresarla nuevamente.\n"RESET);
        }
    } while (bien_ingresado == 2);

    }
   
    switch (opcion)
    {
    case 1:
        sumaMatriz(filas, columnas, matriz_1, matriz_2, matriz_final);
        printf(GREEN"Matriz resultante : \n");
        MostrarMatriz(filas, columnas, matriz_final);
        printf(RESET);
        break;
    case 2:
        restarMatriz(filas, columnas, matriz_1, matriz_2, matriz_final);
        printf("Matriz resultante : \n");
        MostrarMatriz(filas, columnas, matriz_final);
        break;
    case 3:
        multiplicarMatrices(filas, columnas, matriz_1, matriz_2, matriz_final);
        printf("Matriz resultante");
        MostrarMatriz(filas, columnas, matriz_final);
    case 4:
        transpuestaMatriz(filas, columnas, matriz_1, matriz_final);
        printf("Matriz resultante\n");
        MostrarMatriz(filas, columnas, matriz_final);
        break;
    default:
       
        break;
    }

    // MostrarMatriz(filas,columnas,matriz_1);
    // MostrarMatriz(filas,columnas,matriz_1);

    system("pause");
    return 0;
}