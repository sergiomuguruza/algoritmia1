
// ejercicio 11 - Practico 6

// Alumno: Muguruza, Sergio Gustavo
// Año: 2023 Comision: 1

// ¿Que hace esta acción implementada en lenguaje C?
 
//void Swap (int *x,int *y) {
//*x = (*x)+(*y);
//*y = (*x)-(*y);
//*x = (*x)-(*y);
//} 
// esta accion "swap" lo que hace es tomar los valores pasados como parametros
//a la accion e invertirlos. Por ejemplo si hacemos swap(a,b) dsepues de ajecutada la
// accion, a toma el valor de b y b el valor de a


#include <stdio.h>
int a,b;
void Swap (int *x,int *y) {
*x = (*x)+(*y);
*y = (*x)-(*y);
*x = (*x)-(*y);
}
int main() {
printf("introduce el valor de la variable a ");
scanf("%i",&a);
printf("introduce el valor de la variable b ");
scanf("%i",&b);
Swap (&a, &b);
printf ("el valor de a es %d ", a);
printf ("el valor de b es %d ", b);
printf("\n introduce el valor de la variable a ");
scanf("%i",&a);
printf("introduce el valor de la variable b ");
scanf("%i",&b);
Swap (&a, &a);
printf ("el valor de a es %d ", a);
return 0;
}

//¿Por qué el último prinf muestra ese valor de a?
//al hacer swap(&a,&a) le estoy diciendo que haga el intercambio de dos valores que en realidad es uno, que
//es un puntero que apunta a la misma direccion de memoria.

//Nota: que resultado mostraría cada uno de los printf de a, b, a, en el siguiente programa C:

// Ejemplo 1: 
// ingreso a = 6 e ingreso b = 10
// Swap(&a, &b)
// salida a = 10
// salida b =6 
//--> el swap funciona perfectamente
// Swap(&a, &a)
// salida a = 0
//--> el swap devuelve 0 (no sirve pasar como parametro un solo puntero)

// Ejemplo 2:
// ingreso a = -1 ingreso b = 30
// Swap(&a, &b)
// salida a = 30
// salida b = -1
// Swap(&a, &a)
// salida a = 0


//compile el programa agregando algunos printf para ver el valor de las variables en cada paso
// prueba:

//C:\Users\sergio\Documents\analista en computacion>cambiovar

//introduce el valor de la variable a 5
//introduce el valor de la variable b 10

//(dentro del primer Swap)
// comportamiento de la operacion: *x = (*x) + (*y)
//x = 4229492
//*x = 5
//y = 4229488
//*y = 10
//despues de la operacion:
//x = 4229492
//*x = 15
//y = 4229488
//*y = 10

//comportamiento de la operacion: *y = (*x) - (*y)
//x = 4229492
//*x = 15
//y = 4229488
//*y = 10
//despues de la operacion:
//x = 4229492
//*x = 15
//y = 4229488
//*y = 5

//comportamiento antes de la operacion: *x = (*x) - (*y)
//x = 4229492
//*x = 15
//y = 4229488
//*y = 5
//despues de la operacion:
//x  = 4229492
//*x = 10
//y = 4229488
//*y = 5

//fin de Swap

//el valor de a es 10
//el valor de b es 5

//el swap funciono perfectametente!!!!

//introduce el valor de la variable a 8
//introduce el valor de la variable b 4

//(dentro del segundo Swap)

//comportamiento de la operacion: *x = (*x) + (*y)
//x = 4229492
//*x = 8
//y = 4229492
//*y = 8
//despues de la operacion:
//x = 4229492
//*x = 16
//y = 4229492
//*y = 16

//comportamiento de la operacion: *y = (*x) - (*y)
//x = 4229492
//*x = 16
//y = 4229492
//*y = 16
//despues de la operacion:
//x = 4229492
//*x = 0
//y = 4229492
//*y = 0

//comportamiento antes de la operacion: *x = (*x) - (*y)
//x = 4229492
//*x = 0
//y = 4229492
//*y = 0
//despues de la operacion:
//x  = 4229492
//*x = 0
//y = 4229492
//*y = 0

//fin de Swap 

//el valor de a es 0