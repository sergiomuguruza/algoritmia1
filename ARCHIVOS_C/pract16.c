// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Actividad 16 - Implementacion en C

// (Ejercicio 10-a del TP 13)

#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char arreglo[MAX][50];
    int cant;
} TData;

// Acción para cargar el arreglo.

void CargarArreglo(TData *c) {
    int i = 1;
    int cant;

    printf("Ingrese la cantidad de elementos que desea cargar: ");
    scanf("%d", &cant);

    c->cant = cant;

    for (i = 1; i <= cant; i++) {
        printf("Cadena %d: ", i);
        scanf("%s", c->arreglo[i]);
    }
}

// Acción para mostrar el arreglo.

void MostrarArreglo(TData c) {
    int i;

    for (i = 1; i <= c.cant; i++) {
        printf("%d: %s\n", i, c.arreglo[i]);
    }
}

// Acción para ordenamiento por método Burbuja.

void Burbuja(TData *c) {
    int i, j;
    char temp[50];

    for (i = 1; i <= c->cant - 1; i++) {
        for (j = 1; j <= c->cant - i; j++) {
            if (strcmp(c->arreglo[j], c->arreglo[j + 1]) > 0) {
                strcpy(temp, c->arreglo[j]);
                strcpy(c->arreglo[j], c->arreglo[j + 1]);
                strcpy(c->arreglo[j + 1], temp);
            }
        }
    }
}

// Acción para ordenamiento por método Selección.

void Seleccion(TData *c) {
    int i, j;
    char min[50], temp[50];

    for (i = 1; i <= c->cant - 1; i++) {
        strcpy(min, c->arreglo[i]);
        for (j = i + 1; j <= c->cant; j++) {
            if (strcmp(c->arreglo[j], min) < 0) {
                strcpy(min, c->arreglo[j]);
            }
        }
        if (strcmp(min, c->arreglo[i]) != 0) {
            strcpy(temp, c->arreglo[i]);
            strcpy(c->arreglo[i], min);
            strcpy(c->arreglo[j], temp);
        }
    }
}

// Acción para ordenamiento por método Inserción.

void Insercion(TData *c) {
    int i, j;
    char temp[50];

    for (i = 2; i <= c->cant; i++) {
        strcpy(temp, c->arreglo[i]);
        j = i - 1;

        while (j > 0 && strcmp(c->arreglo[j], temp) > 0) {
            strcpy(c->arreglo[j + 1], c->arreglo[j]);
            j--;
        }

        strcpy(c->arreglo[j + 1], temp);
    }
}

// aCción para el método de ordenamiento QuickSort.

void QuickSort(TData *c, int izq, int der) {
    if (izq < der) {
        int i = izq;
        int j = der;
        char temp[50];
        char pivote[50];

        strcpy(pivote, c->arreglo[(izq + der) / 2]);

        do {
            while (strcmp(c->arreglo[i], pivote) < 0 && i < der)
                i++;

            while (strcmp(c->arreglo[j], pivote) > 0 && j > izq)
                j--;

            if (i <= j) {
                strcpy(temp, c->arreglo[i]);
                strcpy(c->arreglo[i], c->arreglo[j]);
                strcpy(c->arreglo[j], temp);
                i++;
                j--;
            }
        } while (i <= j);

        QuickSort(c, izq, j);
        QuickSort(c, i, der);
    }
}

int main() {
    TData cad;
    int op;

    CargarArreglo(&cad);
    MostrarArreglo(cad);

    printf("Ingrese el tipo de ordenamiento a usar (1=Burbuja, 2=Selección, 3=Inserción, 4=Quicksort): ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            Burbuja(&cad);
            printf("Datos ordenados por el método Burbuja:\n");
            MostrarArreglo(cad);
            break;
        case 2:
            Seleccion(&cad);
            printf("Datos ordenados por el método Selección:\n");
            MostrarArreglo(cad);
            break;
        case 3:
            Insercion(&cad);
            printf("Datos ordenados por el método Inserción:\n");
            MostrarArreglo(cad);
            break;
        case 4:
            QuickSort(&cad, 1, cad.cant);
            printf("Datos ordenados por el método Quicksort:\n");
            MostrarArreglo(cad);
            break;
        default:
            printf("Opción no válida. ingrese un número del 1 al 4.\n");
            break;
    }

    return 0;
}
