// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 1 del TP 10:


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
	struct nodo *next;
	}tnodo;
	
tnodo *p, *r, *q, *t, *s;	

int main() {
    
	q=(tnodo *)malloc(sizeof(tnodo));
	q->info=14;
	q->next=NULL;
	
	s=(tnodo *)malloc(sizeof(tnodo));
	s->info=25;
	s->next=q;
	q=s;
	s=(tnodo *)malloc(sizeof(tnodo));
	s->info=20;
	s->next=q;
	q=s;
	
	s=(tnodo *)malloc(sizeof(tnodo));
	s->info=11;
	s->next=q;
	q=s;
	s=NULL;
	
	r=q;
	
    r=r->next;
	t=r->next;
	
	s=(tnodo *)malloc(sizeof(tnodo));
	s->info=3;
	s->next=r->next;
	r->next=s;
	
	p=t;
	t->info=29;
	
	printf("%d", t->info);
	r=q;
	
	while(r!=NULL){
		printf("%d", r->info);
		r=r->next;
		
	}
		
	
	return 0;
}