// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 5 del TP 14

//Ej. 5) Dada un arreglo bidimensional, llamado lluvia10 [1..12, 1..31], cuyos valores corresponden a las precipitaciones diarias
//en milímetros ocurridas a lo largo del año 2023 en una determinada ciudad; desarrollar un algoritmo que calcule cuál es la
//máxima precipitación y en qué día y mes ocurrió.


#include <stdio.h>
#include <string.h>

#define MaxF 12 // meses
#define MaxC 31 // días

// definimos el tdada

typedef struct {
    int lluv[MaxF][MaxC];
    int cantF;
    int cantC;
} TData; 



// Acción para cargar datos de las lluvias día a día

void CargarLluvias(TData *k) {
    int i, j;

    k->cantF = MaxF;
    k->cantC = MaxC;

    // Inicializar la matriz con valores -1 para evitar al mostrar que salgan valores basura

    for (i = 0; i < k->cantF; i++) {
        for (j = 0; j < k->cantC; j++) {
            k->lluv[i][j] = -1;
        }
    }

    for (i = 0; i < k->cantF; i++) {
        for (j = 0; j < k->cantC; j++) {
            printf("Introduce la lluvia para el mes %d, dia %d (o ingresa -5 para detener la carga): ", i + 1, j + 1);
            int valor;
            scanf("%d", &valor);
            if (valor == -5) {
                return; // Detiene la carga de datos si se ingresa -5
            } else {
                k->lluv[i][j] = valor; // Almacena el valor en la matriz
            }
        }
    }
}

//accion para buscar la maxima precipitacion

void maximaPrecipitacion(TData k) {
    int max = k.lluv[0][0];
    int m = 1, d = 1;
    char msje[35], msje1[10], msje2[10];

    if (k.cantF != 0 && k.cantC != 0) {
        for (int i = 0; i < k.cantF; i++) {
            for (int j = 0; j < k.cantC; j++) {
                if (k.lluv[i][j] > max) {
                    max = k.lluv[i][j];
                    m = i + 1;
                    d = j + 1;
                }
            }
        }

        strcpy(msje, "Maxima precipitacion: ");
        strcpy(msje1, "Dia: ");
        strcpy(msje2, "Mes: ");

        printf("%s %d\n %s %d\n %s %d\n", msje, max, msje1, d, msje2, m);
    }
}


//accion para mostrar - se hacen algunas modificaciones para que al mostrar , solo muestre hasta
//el ultimo dia cargado.

void Mostrar(TData k) {
    for (int i = 0; i < k.cantF; i++) {
        for (int j = 0; j < k.cantC; j++) {
            if (k.lluv[i][j] == -1) {
                break; // Detenemos la muestra si encontramos un -1
            }
            printf("%d ", k.lluv[i][j]);
        }
        printf("\n");
    }
}




//cuerpo principal del algoritmo

int main() {
    TData lluvias;

    CargarLluvias(&lluvias);
    Mostrar(lluvias);
    maximaPrecipitacion(lluvias);

    return 0;
}
