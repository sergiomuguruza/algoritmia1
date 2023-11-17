//alumno: SERGIO MUGURUZA - DNI 24333376 - COMISION 1

#include <stdio.h>

void CargarArchivo(FILE *g) {
    int cantidadElementos, i;
    char elem;

    printf("Ingrese cuantos elementos desea cargar en el archivo: ");
    scanf("%d", &cantidadElementos);

    g = fopen("secu.txt", "w");

    for (i = 1; i <= cantidadElementos; i++) {
        printf("Ingrese un elemento: ");
        scanf(" %c", &elem);
        fprintf(g, "%c", elem);
    }

    fclose(g);
}

int main() {
    FILE *f;
    char elementoActual, elementoDado;
    int iguales = 0, distintos = 0;

    CargarArchivo(f);

    f = fopen("secu.txt", "r"); // Modo lectura

    printf("Ingrese el Caracter a buscar cuantos iguales y distintos hay: ");
    scanf(" %c", &elementoDado);

    while ((fscanf(f, " %c", &elementoActual)) != EOF) {
        if (elementoActual == elementoDado) {
            iguales++;
        } else {
            distintos++;
        }
    }


    fclose(f);

    printf("Cantidad de elementos iguales: %d\n", iguales);
    printf("Cantidad de elementos distintos: %d\n", distintos);

    return 0;
}

