
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[50];
    char ape[50];
    int dni;
    int edad;
} Tpers;

typedef struct Telem {
    Tpers info;
    struct Telem *next;
} Telem;

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
    if (!Vacia(*dato)) {
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
    Telem *list;
    Crear(&list);
    int opcion;
    
    do {
        printf("\nMenu:\n");
        printf("1. Insertar Persona\n");
        printf("2. Suprimir Persona\n");
        printf("3. Listar Personas\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                Tpers persona;
                printf("Ingrese el nombre: ");
                scanf("%s", persona.nom);
                printf("Ingrese el apellido: ");
                scanf("%s", persona.ape);
                printf("Ingrese la edad: ");
                scanf("%d", &persona.edad);
                InsertarCab(&list, persona);
                printf("Persona insertada con éxito.\n");
                break;
            }
            case 2: {
                SuprimirCab(&list);
                printf("Persona eliminada con éxito.\n");
                break;
            }
            case 3: {
                printf("Listado de Personas:\n");
                Listar(list);
                break;
            }
            case 4: {
                printf("Saliendo del programa.\n");
                break;
            }
            default: {
                printf("Opción inválida.\n");
                break;
            }
        }
    } while (opcion != 4);
    
    return 0;
}
