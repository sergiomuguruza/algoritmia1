// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 1

// Implementacion en C

// Ejercicio 1 del TP 9:


#include <stdio.h>

#define MAX 20

typedef struct {
    char pers[50]
	int cant[MAX]
	} tdata;

 typedef struct {
    char ape[30]
	int dni[8]
	} tpersona;
	
tdata data
tpersona pers
int doc	



void cargar(tdata *com) {
	printf("ingrese cantidad de registros a cargar");
	scanf ("%d", &com-> cant);
	printf("ingrese los datos de cada persona");
	for (int i=0; i< com.cant; i++) {
		printf("persona %d: \n", i+1);
		printf("\t Apellido:");
		scanf ("%s", &com-> pers[i].ape);
		printf ("\t DNI:");
		scanf ("%s", &com-> pers[i].dni);
	}
}

void buscar (tdata base, doc) {


return 
}

int main() {
    
	cargar (&data);
	printf("ingrese DNI a buscar");
	scanf ("%s", documento);
	buscar();
    
	
	
	
	return 0;
}
		