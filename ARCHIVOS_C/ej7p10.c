#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    

    r = (PNodo)malloc(sizeof(struct TNodo));

    strcpy(r->info, "va?"); //Esto copia la cadena "va?" en la ubicación de memoria apuntada por r->info.
                                //  Después de esta operación, r->info contendrá la cadena "va?".
    r->next = NULL;
    r->back = NULL;

    t = (PNodo)malloc(sizeof(struct TNodo));
    strcpy(t->info, "te");
    t->next = r;
    t->back = NULL;
    r->back = t;

    r = t;

    t = (PNodo)malloc(sizeof(struct TNodo));
    strcpy(t->info, "Como");
    t->next = r;
    t->back = NULL;
    r->back = t;

    r = t;

    t = (PNodo)malloc(sizeof(struct TNodo));
    strcpy(t->info, "Hola");
    t->next = r;
    t->back = NULL;
    r->back = t;

    r = t;

    
    MostrarLista(r);// Mostramos la lista inicial completa

    s = r;

    // Creamos e insertamos el nuevo nodo Tito

    t = (PNodo)malloc(sizeof(struct TNodo));
    strcpy(t->info, "Tito");
    t->back = s;
    t->next = s->next;
    s->next->back = t;
    s->next = t;

    
    MostrarLista(r); // Mostramos la lista completa con la inserción del nuevo nodo

    // Recorremos la lista para encontrar el nodo a modificar
    s = r;
    while (strcmp(s->info, "te") != 0) {//La función strcmp se utiliza para comparar
    // dos cadenas de caracteres y devuelve un valor igual a cero si las cadenas son iguales.
        s = s->next;
    }
    // Modificamos el nodo reemplazando "te" por "estás?"
    strcpy(s->info, "estas?");

    
    MostrarLista(r); // Mostramos la lista completa modificada

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


    MostrarLista(r);

    return 0;
}
