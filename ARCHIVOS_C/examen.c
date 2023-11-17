//alumno: SERGIO MUGURUZA - DNI 24333376 - COMISION 1

// TEMA 1

//esta corregido y funciona ok !!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char info[50];
	struct nodo *next;
	}tnodo;
	
tnodo *q=NULL;

int cant;
char mje[50];
char ciudad[50];

void mostrarLista (tnodo *l, const char *x){

    tnodo *aux;
    int cont;
    cont=0;
    aux= l->next;
    while (aux!=NULL) {

        if (strcmp(aux->info, x)==0){
            cont=cont+1;
        };

        aux = aux->next;
    }
        printf("Se conto esta cantidad de veces: %d\n", cont);
}

//crear o inicializar lista con ficticio

void crearLista (tnodo **l){
    
    *l = (tnodo *)malloc(sizeof(tnodo));
    (*l)->next = NULL;
}


//cargar lista

void cargarLista (tnodo *l, int n){
    
    char ciu[50];
    tnodo *s;
    int i;

    printf("Ingrese las ciudades\n");

        for (i=1; i<=n ; i++) {
        
        scanf("%s", &ciu);
        
        s = (tnodo*)malloc(sizeof(tnodo));
        strcpy(s->info,ciu);
        s->next=l->next;
        l->next=s;
        }
}


void liberarLista(tnodo *l) {
    tnodo *aux;
    while (l != NULL) {
        aux = l;
        l = l->next;
        free(aux);
    }
free(l);
}


//cuerpo principal

int main() {
crearLista(&q);

printf("cuantos nodos va a agregar\n");
    scanf("%d", &cant);

    cargarLista(q,cant);

    printf("que ciudad quiere contar\n");
    scanf("%s", &ciudad);

    mostrarLista(q,ciudad);

	// Liberar memoria
    liberarLista(q);
	
	return 0;
}