#include <stdio.h>
#include <stdlib.h>
//Funcion para cargar la matriz
void RecorrerMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el numero de la fila %d columna %d de la matriz: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}
// Función para mostrar la matriz
void MostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
 //Funcion para sumar la matriz
void sumaMatriz(int filas,int columnas,int matriz_1[filas][columnas], int matriz_2[filas][columnas],int matriz_final[filas][columnas]){

for (int i = 0; i < filas; i++)
{for (int it = 0; it < columnas; it++)
    {matriz_final[i][it] = matriz_1[i][it] + matriz_2[i][it];}}};
//Funcion para restar la matriz
void restarMatriz(int filas,int columnas,int matriz_1[filas][columnas], int matriz_2[filas][columnas],int matriz_final[filas][columnas]){
for (int i = 0; i < filas; i++){for (int it = 0; it < columnas; it++){matriz_final[i][it] = matriz_1[i][it] - matriz_2[i][it];}}};
//Funcion para multiplicar las matrices.
void multiplicarMatrices(int filas,int columnas,int matriz_1[filas][columnas], int matriz_2[filas][columnas],int matriz_final[filas][columnas])
{// Inicialización de la matriz final en 0
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
//Funcion para sacar la transpuesta.
void transpuestaMatriz(int filas,int columnas, int matriz[filas][columnas],int matriz_final[columnas][filas]){
    for (int i = 0; i < filas; i++)
    {
        for (int it = 0; it < columnas; it++)
        {
         matriz_final[it][i] = matriz[i][it];   
        }
    }  
}

int main() {
    int filas,columnas,opcion,bien_ingresado;

    printf("Bienvenido, soy una calculadora de matrices.");
    //-------------------------------------------------  MENU  --------------------------------------------------------------------//
    do{ printf("Opciones: \n 1_Suma de dos matrices \n 2_Resta de dos matrices. \n 3_Mostrar matriz transpuesta.\n 4_Multiplicacion de matricez.\n Digite su eleccion: ");
        scanf("%d",&opcion);
        if(opcion < 1 || opcion > 3){printf("Error, ingrese una opcion valida.");}
    } while(opcion < 1 || opcion > 3);
    //-------------------------------------------------  Salida de Opciones  --------------------------------------------------------------------//
    
    // Pedir dimensiones de la matriz
    printf("Ingrese la cantidad de filas de la matriz: ");
    scanf("%d", &filas);

    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%d", &columnas);
    
    int matriz_1[filas][columnas],matriz_2[filas][columnas],matriz_final[filas][columnas];
    
    do{
     printf("Primer matriz.\n");
     RecorrerMatriz(filas,columnas,matriz_1);
     MostrarMatriz(filas,columnas,matriz_1);
     printf("Matriz ingresada : \n");
     printf("Ingresado correctamente 1_Si 2_No: ");
     scanf("%d",&bien_ingresado);
     if (bien_ingresado == 2)
     {printf("Reiniciamos la matriz,ya puede ingresarla nuevamente.");}
    } while (bien_ingresado == 2);

    do{
     printf("Segunda matriz.\n");
     RecorrerMatriz(filas,columnas,matriz_2);
     MostrarMatriz(filas,columnas,matriz_2);
     printf("Matriz ingresada : \n");
     printf("Ingresado correctamente 1_Si 2_No: ");
     scanf("%d",&bien_ingresado);
     if (bien_ingresado == 2)
     {printf("Reiniciamos la matriz,ya puede ingresarla nuevamente.");}
    } while (bien_ingresado == 2);
   
    switch (opcion)
    {
    case 1:
        sumaMatriz(filas,columnas,matriz_1,matriz_2,matriz_final);
        printf("Matriz resultante : \n");
        MostrarMatriz(filas,columnas,matriz_final);
        break;
    case 2:
        restarMatriz(filas,columnas,matriz_1,matriz_2,matriz_final);
        printf("Matriz resultante : \n");
        MostrarMatriz(filas,columnas,matriz_final);
        break;
    case 3:
    transpuestaMatriz(filas,columnas,matriz_1,matriz_final);
    MostrarMatriz(filas,columnas,matriz_final);
        break;
    default:
        multiplicarMatrices(filas,columnas,matriz_1,matriz_2,matriz_final);
        printf("Matriz resultante");
        MostrarMatriz(filas,columnas,matriz_final);
        break;
    }

     //MostrarMatriz(filas,columnas,matriz_1);
     //MostrarMatriz(filas,columnas,matriz_1);

    system("pause");
    return 0;
}