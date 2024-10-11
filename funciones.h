#ifndef FUNCIONES_H
#define FUNCIONES_H

// Declaraciones de funciones
void pedirNumero(int* numero);
void RecorrerMatriz(int filas, int columnas, int** matriz);
void MostrarMatriz(int filas, int columnas, int** matriz);
void sumaMatriz(int filas, int columnas, int** matriz_1, int** matriz_2, int** matriz_final);
void restarMatriz(int filas, int columnas, int** matriz_1, int** matriz_2, int** matriz_final);
void transpuestaMatriz(int filas, int columnas, int** matriz, int** matriz_final);

#endif
