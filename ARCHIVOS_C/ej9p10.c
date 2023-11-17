// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 9 del TP 10


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Cadena[50];

typedef struct {
    Cadena nombre;
    Cadena apellido;
	Cadena Telefono;
	Cadena calleDomicilio;
    int edad;
	Cadena sexo;
} Tsocio;

typedef struct Telem {
    Tsocio info;
    struct Telem* next;
} Telem;

typedef struct Telem* Telem;
Telem* aux;
Telem* q;
Tsocio socio;
Cadena nombre;
int posicion;

// Acción Inicializar
void Inicializar(Telem* list) {
    Telem *aux = (Telem)malloc(sizeof(struct Telem));
        
    aux->next = NULL;// Inicializar el elemento ficticio

    list = aux;
}




void InsertarC(struct Telem *list, Tsocio reg) {
    
    Telem* aux = (Telem)malloc(sizeof(struct Telem));
	
    strcpy(aux->info.nombre, reg.nombre);
    strcpy(aux->info.apellido, reg.apellido);
    strcpy(aux->info.telefono, reg.Telefono);
    strcpy(aux->info.CalleDomicilio, reg.calleDomicilio);
    aux->info.edad = reg.edad;
    aux->info.sexo = reg.sexo;
	
	aux->next = list->next;
    list->next = aux;
}

// Acción cargarSocio
void cargarSocio(struct TSocio* socio) {
    char msg[100]; // Cadena para mensajes

    strcpy(msg, "Ingrese los datos de un Socio");
    printf("%s\n", msg);

    strcpy(msg, "Ingrese el nombre del socio");
    printf("%s\n", msg);
    scanf(" %99[^\n]", socio->nombre); // Leer el nombre

    strcpy(msg, "Ingrese el apellido del socio");
    printf("%s\n", msg);
    scanf(" %99[^\n]", socio->apellido); // Leer el apellido

    strcpy(msg, "Ingrese el número de teléfono del socio");
    printf("%s\n", msg);
    scanf(" %19[^\n]", socio->telefono); // Leer el teléfono

    strcpy(msg, "Ingrese la calle del Domicilio del socio");
    printf("%s\n", msg);
    scanf(" %99[^\n]", socio->calleDomicilio); // Leer la calleDomicilio

    strcpy(msg, "Ingrese la edad del socio - valida entre 6 y 80 años");
    printf("%s\n", msg);
    scanf("%d", &socio->edad); // Leer la edad

    strcpy(msg, "Ingrese el sexo (F o M) del socio");
    printf("%s\n", msg);
    scanf(" %c", &socio->sexo); // Leer el sexo
}

// Acción Mostrar
void Mostrar(struct Telem* list) {
    struct Telem* aux = list->next; // Iniciar desde el primer elemento de la lista

    while (aux != NULL) {
        printf("Nombre: %s\n", aux->info.nombre);
        printf("Apellido: %s\n", aux->info.apellido);
        printf("Teléfono: %s\n", aux->info.Telefono);
        printf("Calle de Domicilio: %s\n", aux->info.calleDomicilio);
        printf("Edad: %d\n", aux->info.edad);
        printf("Sexo: %c\n", aux->info.sexo);
        
        aux = aux->next; // Avanzar al siguiente elemento de la lista
    }
}

int main() {



Inicializar(q)
cargarSocio(socio)
InsertarC(socio)
Mostrar(q);

    return 0;
}