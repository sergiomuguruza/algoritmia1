#include <stdio.h>

// Función para cargar los valores de la matriz
void cargarMatriz(int matriz[][m], int n, int m) {
    printf("Ingrese los valores de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el valor para la posición (%d, %d): ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para mostrar la matriz con sus elementos cargados
void mostrarMatriz(int matriz[][m], int n, int m) {
    printf("Matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para comparar la suma de los valores del límite y del interior de la matriz
int compararSumas(int matriz[][m], int n, int m) {
    int sumaPeriferia = 0;
    int sumaInterior = 0;
    
    // Suma de las celdas de la periferia
    for (int j = 0; j < m; j++) {
        sumaPeriferia += matriz[0][j]; // Primera fila
        sumaPeriferia += matriz[n-1][j]; // Última fila
    }
    
    for (int i = 1; i < n-1; i++) {
        sumaPeriferia += matriz[i][0]; // Primera columna (excluyendo las esquinas)
		
		//sumaPeriferia += matriz[0][j]; es equivalente a sumaPeriferia = sumaPeriferia + matriz[0][j]
        //El operador += toma el valor actual de sumaPeriferia, le suma el valor de matriz[0][j]
        //y actualiza el resultado en sumaPeriferia
		
        sumaPeriferia += matriz[i][m-1]; // Última columna (excluyendo las esquinas)
    }
    
    // Suma de las celdas del interior
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            sumaInterior += matriz[i][j];
        }
    }
    
    if (sumaPeriferia == sumaInterior) {
        return 1; // La suma de las celdas de la periferia es igual a la suma de las celdas del interior
    } else {
        return 0; // La suma de las celdas de la periferia es diferente a la suma de las celdas del interior
    }
}

int main() {
    int n, m;
    
    printf("Ingrese el número de filas (n): ");
    scanf("%d", &n);
    
    printf("Ingrese el número de columnas (m): ");
    scanf("%d", &m);
    
    if (n < 3 || m < 3) {
        printf("Error: n y m deben ser mayores o iguales a 3.\n");
        return 0;
    }
    
    int matriz[n][m];
    
    cargarMatriz(matriz, n, m);
    mostrarMatriz(matriz, n, m);
    
    int resultado = compararSumas(matriz, n, m);
    
    if (resultado) {
        printf("La suma de las celdas de la periferia es igual a la suma de las celdas del interior.\n");
    } else {
        printf("La suma de las celdas de la periferia es diferente a la suma de las celdas del interior.\n");
    }
    
    return 0;
}
