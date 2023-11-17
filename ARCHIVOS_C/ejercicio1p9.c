// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 1 del TP 9


#include <stdio.h>

#define MAX 20

typedef struct {
    char ape[30];
    int dni;
} tpersona;

typedef struct {
    tpersona pers[MAX];
    int cant;
} tdata;

tdata data;
int documento;

void cargar(tdata *com) {
    printf("Ingrese cantidad de registros a cargar: ");
    scanf("%d", &com->cant);

    printf("Ingrese los datos de cada persona:\n");
    for (int i = 0; i < com->cant; i++) {
        printf("Persona %d:\n", i + 1);
        printf("\tApellido: ");
        scanf("%s", com->pers[i].ape);
        printf("\tDNI: ");
        scanf("%d", &com->pers[i].dni);
    }
}

void buscar(tdata base, int doc) {
    for (int i = 0; i < base.cant; i++) {
        if (base.pers[i].dni == doc) {
            printf("Persona encontrada:\n");
            printf("\tApellido: %s\n", base.pers[i].ape);
            printf("\tDNI: %d\n", base.pers[i].dni);
            return;
        }
    }
    printf("No se encontró persona con ese DNI.\n");
}

int main() {
    cargar(&data);
    printf("Ingrese DNI a buscar: ");
    scanf("%d", &documento);
    buscar(data, documento);
    return 0;
}
