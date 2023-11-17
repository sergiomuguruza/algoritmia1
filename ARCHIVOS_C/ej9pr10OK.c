// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 9 del TP 10


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura TSocio
struct TSocio {
    char nombre[100];
    char apellido[100];
    char telefono[20];
    char calleDomicilio[100];
    int edad;
    char sexo;
};

// Definición de la estructura Telem
struct Telem {
    struct TSocio info;
    struct Telem* next;
};

// Acción Inicializar
void Inicializar(struct Telem** list) {
    struct Telem* aux = (struct Telem*)malloc(sizeof(struct Telem));
    aux->next = NULL;
    *list = aux;
}

// Acción InsertarC
void InsertarC(struct Telem** list, struct TSocio reg) {
    struct Telem* aux = (struct Telem*)malloc(sizeof(struct Telem));
    strcpy(aux->info.nombre, reg.nombre);
    strcpy(aux->info.apellido, reg.apellido);
    strcpy(aux->info.telefono, reg.telefono);
    strcpy(aux->info.calleDomicilio, reg.calleDomicilio);
    aux->info.edad = reg.edad;
    aux->info.sexo = reg.sexo;

    aux->next = (*list)->next;
    (*list)->next = aux;
}

// Función Buscar
int Buscar(struct Telem* list, char nombreBuscado[100]) {
    struct Telem* aux = list->next;
    int pos = 0;

    while (aux != NULL) {
        pos++;
        if (strcmp(aux->info.nombre, nombreBuscado) == 0) {
            return pos;
        }
        aux = aux->next;
    }

    return -1;
}

// Acción Mostrar
void Mostrar(struct Telem* list) {
    struct Telem* aux = list->next;

    while (aux != NULL) {
        printf("--------------------\n");
        printf("Nombre: %s\n", aux->info.nombre);
        printf("Apellido: %s\n", aux->info.apellido);
        printf("Teléfono: %s\n", aux->info.telefono);
        printf("Calle de Domicilio: %s\n", aux->info.calleDomicilio);
        printf("Edad: %d\n", aux->info.edad);
        printf("Sexo: %c\n", aux->info.sexo);
        printf("--------------------\n");
        aux = aux->next;
    }
}

// Acción MuestraRegistro
void MuestraRegistro(struct Telem* list, int pos) {
    if (pos < 1) {
        printf("Posición incorrecta\n");
    } else {
        struct Telem* aux = list->next;
        int cont = 1;

        while (aux != NULL && cont != pos) {
            cont++;
            aux = aux->next;
        }

        if (aux != NULL) {
            printf("--------------------\n");
            printf("Nombre: %s\n", aux->info.nombre);
            printf("Apellido: %s\n", aux->info.apellido);
            printf("Teléfono: %s\n", aux->info.telefono);
            printf("Calle de Domicilio: %s\n", aux->info.calleDomicilio);
            printf("Edad: %d\n", aux->info.edad);
            printf("Sexo: %c\n", aux->info.sexo);
            printf("--------------------\n");
        }
    }
}

// Acción cargarSocio
void cargarSocio(struct TSocio* soc) {
    char msg[100];

    strcpy(msg, "Ingrese los datos de un Socio");
    printf("%s\n", msg);

    strcpy(msg, "Ingrese el nombre del socio");
    printf("%s\n", msg);
    scanf(" %99[^\n]", soc->nombre);

    strcpy(msg, "Ingrese el apellido del socio");
    printf("%s\n", msg);
    scanf(" %99[^\n]", soc->apellido);

    strcpy(msg, "Ingrese el número de telefono del socio");
    printf("%s\n", msg);
    scanf(" %19[^\n]", soc->telefono);

    strcpy(msg, "Ingrese la calle del Domicilio del socio");
    printf("%s\n", msg);
    scanf(" %99[^\n]", soc->calleDomicilio);

    strcpy(msg, "Ingrese la edad del socio");
    printf("%s\n", msg);
    scanf("%d", &soc->edad);

    strcpy(msg, "Ingrese el sexo (F o M) del socio");
    printf("%s\n", msg);
    scanf(" %c", &soc->sexo);
}

// Acción LiberarMemoria
void LiberarMemoria(struct Telem* list) {
    struct Telem* aux;

    while (list->next != NULL) {
        aux = list->next;
        list->next = aux->next;
        free(aux);
    }
}

int main() {
    struct Telem* q;
    Inicializar(&q);

    int opcion;
    char nombreBuscado[100];
    int posicion;
    struct TSocio socio;
    do {
        printf("Ingrese una opcion:\n");
        printf("1. Insertar a la cabeza\n");
        printf("2. Buscar un elemento\n");
        printf("3. Mostrar un registro\n");
        printf("4. Mostrar todos los registros\n");
        printf("5. Vaciar la lista\n");
        printf("6. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                
                cargarSocio(&socio);
                InsertarC(&q, socio);
                break;

            case 2:
                printf("Ingrese el nombre del socio a buscar: ");
                scanf(" %99[^\n]", nombreBuscado);
                posicion = Buscar(q, nombreBuscado);
                printf("La posición es: %d\n", posicion);
                break;

            case 3:
                printf("Ingrese la posición del registro a mostrar: ");
                scanf("%d", &posicion);
                MuestraRegistro(q, posicion);
                break;

            case 4:
                Mostrar(q);
                break;

            case 5:
                LiberarMemoria(q);
                Inicializar(&q);
                break;

            case 6:
                LiberarMemoria(q);
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
