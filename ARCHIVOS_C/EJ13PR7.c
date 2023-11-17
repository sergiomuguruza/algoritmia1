
//Ejercicio N 13 Pract N 7 : Dado un arreglo A ya cargado con t números enteros positivos menores o iguales a 10, y ordenado de
//menor a mayor, desarrolle una acción que permita insertar un elemento, en el lugar que le corresponde para
//mantener el orden creciente.

//Alumno: MUGURUZA. SERGIO GUSTAVO --- DNI: 24333376 --- Comision: 1

#include <stdio.h>

//accion que inserta un elemento al arreglo manteniendo el orden creciente de sus elementos

void insertar_elemento(int arreglo[], int cant, int elemento) {
    int h = cant - 1;

    while (h >= 0 && arreglo[h] > elemento) {
        arreglo[h + 1] = arreglo[h];
        h--;
    }

    arreglo[h + 1] = elemento;
}

int main() {
    int tam;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    int arreglo[tam];

    // Solicitar por consola los valores de los elementos del arreglo
	
    printf("Ingrese los valores de los elementos del arreglo (%d elementos,del 1 al 10, ingresar cada uno y presionar ENTER):\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arreglo[i]);
    }

    // Ordenar el arreglo y mostrarlo
	
    for (int i = 1; i < tam; i++) {
        insertar_elemento(arreglo, i, arreglo[i]);
    }

    printf("Arreglo ingresado ordenado en forma creciente: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Pedir al usuario el elemento a agregar
	
    int elemento;
    printf("Ingrese el elemento a agregar: ");
    scanf("%d", &elemento);

    // Insertar el elemento en el arreglo manteniendo el orden creciente mediante la accion 
	
    insertar_elemento(arreglo, tam, elemento);
	
	// mostrar el nuevo arreglo
	
    printf("Arreglo con el elemento agregado y ordenado: ");
    for (int i = 0; i < tam + 1; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
