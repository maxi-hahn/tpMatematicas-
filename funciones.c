#include <stdio.h>
#include "funciones.h"
#define RED     "\x1b[31m" //para errores
#define GREEN   "\x1b[32m" //para datos devueltos por la app
#define YELLOW  "\x1b[33m" //para datos ingresados por el usuario
#define BLUE    "\x1b[34m" //para pedidos de la app
#define RESET   "\x1b[0m"  //volver al defecto
void pedirNumero(int* numero) {
    int resultado;

    // Bucle hasta que se ingrese un numero valido
    do {
        resultado = scanf("%d", numero);
        printf(RESET);

        if (resultado != 1) {
            printf(RED"Entrada no valida. Por favor, ingresa un numero.\n"RESET);

            // Limpiar el buffer de entrada
            while (getchar() != '\n');
        }

    } while (resultado != 1);

    // Limpiar el buffer de entrada (por si queda un '\n')
    while (getchar() != '\n');
}

// Funcion para cargar la matriz
void RecorrerMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf(BLUE"Ingrese el numero de la fila %d columna %d de la matriz: "RESET, i + 1, j + 1);
            printf(YELLOW);
            pedirNumero(&matriz[i][j]);
            printf(RESET);
        }
    }
}

// Funcion para mostrar la matriz
void MostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf(GREEN"%d " RESET, matriz[i][j]);
        }
        printf("\n");
    }
}

// Funcion para sumar la matriz
void sumaMatriz(int filas, int columnas, int matriz_1[filas][columnas], int matriz_2[filas][columnas], int matriz_final[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int it = 0; it < columnas; it++) {
            matriz_final[i][it] = matriz_1[i][it] + matriz_2[i][it];
        }
    }
}

// Funcion para restar la matriz
void restarMatriz(int filas, int columnas, int matriz_1[filas][columnas], int matriz_2[filas][columnas], int matriz_final[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int it = 0; it < columnas; it++) {
            matriz_final[i][it] = matriz_1[i][it] - matriz_2[i][it];
        }
    }
}

// Funcion para sacar la transpuesta
void transpuestaMatriz(int filas, int columnas, int matriz[filas][columnas], int matriz_final[columnas][filas]) {
    for (int i = 0; i < filas; i++) {
        for (int it = 0; it < columnas; it++) {
            matriz_final[it][i] = matriz[i][it];
        }
    }
}
