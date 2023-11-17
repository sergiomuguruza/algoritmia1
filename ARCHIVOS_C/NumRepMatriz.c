
// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comisión 1

// Actividad Nro 7 Implementacion en C

// Ejercicio 5 del TP 8:
// Desarrolle una función que dado un arreglo bidimensional de enteros (tamaño n x m)
// y un número entero, retorne verdadero si dicho número está repetido más de 3 veces
// en la matriz, y falso en caso contrario.


#include <stdio.h>

#define filMax 20
#define colMax 20


// Función que verifica si un número está repetido más de 3 veces en una matriz

int chequearNumeroRep(int matriz[filMax][colMax], int n, int m, int numero) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == numero) {
                contador++;
                if (contador > 3) { // si quisera usar la funcion para chequear si esta 3 veces repetido deberia usar >=
				                    // al pedir MAS DE 3 VECES se usa el >
                    return 1; // Verdadero, el número está repetido más de 3 veces
                }
            }
        }
    }
    return 0; // Falso, el número no está repetido más de 3 veces
}

// codigo donde se muestra el uso de la funcion creada
 
int main() {
    int n, m;
	int i, j;
	int numero;
	int matriz[filMax][colMax];
	
    printf("Ingrese el numero de filas (n): ");
    scanf("%d", &n);
	
    printf("Ingrese el numero de columnas (m): ");
    scanf("%d", &m);
   
    printf("Ingrese los nxm elementos de la matriz:\n");
	
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    
    printf("Ingrese el numero a verificar si esta repetido mas de 3 veces: ");
    scanf("%d", &numero);

    if (chequearNumeroRep(matriz, n, m, numero)) {
        printf("El numero %d esta repetido MAS de 3 veces en la matriz.\n", numero); // esto muestra si la funcion retorna 1 (verdadero)
    } else {
        printf("El numero %d no esta repetido MAS de 3 veces en la matriz.\n", numero); // esto muestra si la funcion retorna 0 (falso)
    }

    return 0;
}




