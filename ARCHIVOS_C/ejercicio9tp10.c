// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 9 del TP 10


sin terminar - ojo !!!




#include <stdio.h>
#include <stdlib.h>

typedef char Cadena[50];
typedef enum edad[6-80];
typedef enum sexo[f,m];

typedef struct {
    Cadena nombre;
    Cadena apellido;
	Cadena Telefono;
	Cadena calleDomicilio;
    Tedad edad;
	Tsexo sexo;
} Tsocio;

typedef struct Telem {
    Tsocio info;
    struct Telem *next;
} Telem;

Telem *q;
Tsocio socio;
Cadena nombre;
int posicion;

// Acción Inicializar
void Inicializar(Telem *list) {
    
    Telem *aux = (Telem)malloc(sizeof(struct Telem));
        
    aux->next = NULL;// Inicializar el elemento ficticio

    list = aux;
}




void InsertarC(Telem *list, Tsocio reg) {
    Telem *aux = (Telem)malloc(sizeof(struct Telem));
	
    strcpy(aux->info.nombre, reg.nombre);
    strcpy(aux->info.apellido, reg.apellido);
    strcpy(aux->info.telefono, reg.telefono);
    strcpy(aux->info.CalleDomicilio, reg.CalleDomicilio);
    aux->info.edad = reg.edad;
    aux->info.sexo = reg.sexo;
	
	aux->next = list->next;
    list->next = aux;
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