#include <stdio.h>
#include <stdlib.h>
#define RED     "\x1b[31m" //para errores
#define GREEN   "\x1b[32m" //para datos devueltos por la app
#define YELLOW  "\x1b[33m" //para datos ingresados por el usuario
#define BLUE    "\x1b[34m" //para pedidos de la app
#define RESET   "\x1b[0m"  //volver al defecto
int variable;

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

int main() {
    int filas, columnas, opcion, bien_ingresado;
    int salir=1;
    do
    {
        
        printf(BLUE"Bienvenido, soy una calculadora de matrices.\n"RESET);

        // Menu
        do {
            printf(BLUE"Opciones: \n 1_Suma de dos matrices \n 2_Resta de dos matrices. \n 3_Mostrar matriz transpuesta.\n 4_Multiplicacion de matrices.\n Digite su eleccion: "RESET);
            printf(YELLOW);
            pedirNumero(&opcion);
            printf(RESET);
            if (opcion < 1 || opcion > 3) {
                printf(RED"Error, ingrese una opcion valida.\n"RESET);
            }
        } while (opcion < 1 || opcion > 3);

        // Pedir dimensiones de la matriz
        printf(BLUE"Ingrese la cantidad de filas de la matriz: "RESET);
        do {
            printf(YELLOW);
            pedirNumero(&filas);
            printf(RESET);
            if (filas <= 1) {
                printf(RED"Error, ingrese una cantidad de filas valida.\n"RESET);
            }
        } while (filas <= 1);

        printf(BLUE"Ingrese la cantidad de columnas de la matriz: "RESET);
        do {
            printf(YELLOW);
            pedirNumero(&columnas);
            printf(RESET);
            if (columnas <= 1) {
                printf(RED"Error, ingrese una cantidad de columnas valida.\n"RESET);
            }
        } while (columnas <= 1);

        int matriz_1[filas][columnas], matriz_2[filas][columnas], matriz_final[filas][columnas];

        // Primera matriz
        do {
            printf(GREEN"Primera matriz.\n"RESET);
            RecorrerMatriz(filas, columnas, matriz_1);
            printf(GREEN"Matriz ingresada:\n");
            MostrarMatriz(filas, columnas, matriz_1);
            printf(RESET);
            printf(BLUE"Ingresado correctamente 1_Si 2_No: "RESET);
            do {
                printf(YELLOW);
                pedirNumero(&bien_ingresado);
                printf(RESET);
                if (bien_ingresado != 1 && bien_ingresado != 2) {
                    printf(RED"No ha ingresado una opcion valida, ingrese 1 o 2:\n"RESET);
                }
            } while (bien_ingresado != 1 && bien_ingresado != 2);
            if (bien_ingresado == 2) {
                printf(BLUE"Reiniciamos la matriz, ya puede ingresarla nuevamente.\n"RESET);
            }
        } while (bien_ingresado == 2);

        // Segunda matriz
        do {
            printf(GREEN"Segunda matriz.\n"RESET);
            RecorrerMatriz(filas, columnas, matriz_2);
            printf(GREEN"Matriz ingresada:\n");
            MostrarMatriz(filas, columnas, matriz_2);
            printf(RESET);
            printf(BLUE"Ingresado correctamente 1_Si 2_No: "RESET);
            do {
                printf(YELLOW);
                pedirNumero(&bien_ingresado);
                printf(RESET);
                if (bien_ingresado != 1 && bien_ingresado != 2) {
                    printf(RED"No ha ingresado una opcion valida, ingrese 1 o 2:\n"RESET);
                }
            } while (bien_ingresado != 1 && bien_ingresado != 2);
            if (bien_ingresado == 2) {
                printf(BLUE"Reiniciamos la matriz, ya puede ingresarla nuevamente.\n"RESET);
            }
        } while (bien_ingresado == 2);

        // Operaciones
        switch (opcion) {
        case 1:
            sumaMatriz(filas, columnas, matriz_1, matriz_2, matriz_final);
            printf(GREEN"Matriz resultante:\n");
            MostrarMatriz(filas, columnas, matriz_final);
            printf(RESET);
            printf(BLUE"desea salir del programa? si= 0 no= 'ingrese cualquier numero': "RESET);
            printf(YELLOW);
            pedirNumero(&salir);
            printf(RESET);
            break;
        case 2:
            restarMatriz(filas, columnas, matriz_1, matriz_2, matriz_final);
            printf(GREEN"Matriz resultante:\n");
            MostrarMatriz(filas, columnas, matriz_final);
            printf(RESET);
            printf(BLUE"desea salir del programa? si= 0 no= 'ingrese cualquier numero': "RESET);
            printf(YELLOW);
            pedirNumero(&salir);
            printf(RESET);
            break;
        case 3:
            transpuestaMatriz(filas, columnas, matriz_1, matriz_final);
            MostrarMatriz(filas, columnas, matriz_final);
            break;
            printf(BLUE"desea salir del programa? si= 0 no= 'ingrese cualquier numero': "RESET);
            printf(YELLOW);
            pedirNumero(&salir);
            printf(RESET);
        }
    } while (salir!=0);
    

    system("pause");
    return 0;
}
