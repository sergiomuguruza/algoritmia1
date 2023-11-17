// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 4 del TP 10


#include <stdio.h>
#include <stdlib.h>

typedef char Cadena[50];

typedef struct {
    Cadena nom;
    Cadena ape;
    int edad;
} Tpers;

typedef struct Telem {
    Tpers info;
    struct Telem *next;
} Telem;

Telem *list;

void Crear(Telem **list) {
    *list = NULL;
}

void InsertarCab(Telem **dato, Tpers reg) {
    Telem *aux = (Telem *)malloc(sizeof(Telem));
    aux->info = reg;
    aux->next = *dato;
    *dato = aux;
}

void SuprimirCab(Telem **dato) {
    if (*dato != NULL) {
        Telem *aux = *dato;
        *dato = (*dato)->next;
        free(aux);
    }
}

int Vacia(Telem *dato) {
    return dato == NULL;
}

void Listar(Telem *dato) {
    Telem *aux = dato;
    while (aux != NULL) {
        printf("Nombre: %s\n", aux->info.nom);
        printf("Apellido: %s\n", aux->info.ape);
        printf("Edad: %d\n", aux->info.edad);
        aux = aux->next;
    }
}

int main() {
    int opcion;
    Tpers persona;

    do {
        printf("\nMenu:\n");
        printf("1. Crear lista\n");
        printf("2. Insertar\n");
        printf("3. Suprimir\n");
        printf("4. Verificar lista vacia\n");
        printf("5. Listar\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                Crear(&list);
                printf("Lista creada.\n");
                break;
            case 2:
                printf("Ingrese nombre: ");
                scanf("%s", persona.nom);
                printf("Ingrese apellido: ");
                scanf("%s", persona.ape);
                printf("Ingrese edad: ");
                scanf("%d", &persona.edad);
                InsertarCab(&list, persona);
                printf("Persona insertada.\n");
                break;
            case 3:
                SuprimirCab(&list);
                printf("Primer elemento suprimido.\n");
                break;
            case 4:
                if (Vacia(list)) {
                    printf("La lista esta vacia.\n");
                } else {
                    printf("La lista no esta vacia.\n");
                }
                break;
            case 5:
                Listar(list);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}
