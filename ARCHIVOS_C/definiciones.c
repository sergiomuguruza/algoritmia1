
definir una lista 

typedef struct nodo{
    int info;
	struct nodo *next;
	}tnodo;
	
tnodo *p, *r, *q, *t, *s;	

int main() {
    
	q=(tnodo *)malloc(sizeof(tnodo));
	q->info=14;
	q->next=NULL;
	
	while(r!=NULL){
		printf("%d", r->info);
		r=r->next;
		
	}
		
	return 0;
}





lista doble encaden

struct TNodo {
    char info[50];
    struct TNodo* next;
    struct TNodo* back;
};

typedef struct TNodo* PNodo;

// Función para mostrar la lista
void MostrarLista(PNodo l) {
    PNodo aux = l;
    while (aux != NULL) {
        printf("%s ", aux->info);
        aux = aux->next;
    }
    printf("\n"); //Dejamos un espacio
}

PNodo r, s, t, p;
PNodo aux;

// Buscamos el elemento que queremos eliminar
    s = r;
    while (strcmp(s->info, "va?") != 0){
        s = s->next;
    }
    // Eliminamos el nodo

    if (s->back != NULL) {
    s->back->next = s->next;
    }
    if (s->next != NULL) {
    s->next->back = s->back;
    }
    free(s);
	
	
	
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

// Acción Inicializar con ficticio

void Inicializar(struct Telem** list) {
    struct Telem* aux = (struct Telem*)malloc(sizeof(struct Telem));
    aux->next = NULL;	
    *list = aux;
	
	
	
	#include <stdio.h>

// Definición de la estructura Tpers
typedef struct {
    char nom[100];   // Nombre, supongamos que tiene un máximo de 100 caracteres
    char ape[100];   // Apellido, supongamos que tiene un máximo de 100 caracteres
    int dni;         // Número de DNI (Documento Nacional de Identidad)
    int edad;        // Edad de la persona
} Tpers;

// Definición de la estructura Telem
typedef struct NodoTelem {
    Tpers info;                // Información de la persona
    struct NodoTelem* next;    // Puntero al siguiente elemento en la lista
} Telem;


//a) Acción Crear (resultado list ε puntero a Telem)


#include <stdio.h>
#include <stdlib.h>

void Crear(Telem **list) {
    *list = NULL;
}



//b) Acción InsertarCab (dato list ε puntero a Telem, reg ε Tpers)

#include <stdio.h>
#include <stdlib.h>

void InsertarCab(Telem **list, Tpers reg) {
    Telem *aux = (Telem *)malloc(sizeof(Telem));
    
    aux->info = reg;
    aux->next = *list;
    *list = aux;
}


//c) Acción SuprimirCab (dato list ε puntero a Telem)


#include <stdio.h>
#include <stdlib.h>

void SuprimirCab(Telem **list) {
    if (*list != NULL) {
        Telem *aux = *list;
        *list = (*list)->next;
        free(aux);
    }
}



//d) Función Vacia (dato list ε puntero a Telem) --> Lógico


#include <stdbool.h>

bool Vacia(Telem *list) {
    return (list == NULL);
	
	
	
}

//e) Acción Listar (dato list ε puntero a Telem)

#include <stdio.h>

void Listar(Telem *list) {
    Telem *aux = list;
    while (aux != NULL) {
        printf("Nombre: %s\n", aux->info.nom);
        printf("Apellido: %s\n", aux->info.ape);
        printf("Edad: %d\n", aux->info.edad);
        aux = aux->next;
    }
}


// Nodo para lista simplemente encadenada
typedef struct NodoS {
    int dato;               // Datos almacenados en el nodo
    struct NodoS* siguiente; // Puntero al siguiente nodo
} NodoSimple;

// Nodo para lista doblemente encadenada
typedef struct NodoD {
    int dato;               // Datos almacenados en el nodo
    struct NodoD* siguiente; // Puntero al siguiente nodo
    struct NodoD* anterior;  // Puntero al nodo anterior
} NodoDoble;
