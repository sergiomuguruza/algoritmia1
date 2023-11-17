#include <stdio.h>

#define max 150

typedef char telem;
int i;


typedef struct {
    int d[max];
    int cant;
	} tdata;
tdata datos;

int main() {
    
    i = 1;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &datos.cant);

    while (i <= datos.cant) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &datos.d[i]);
        i++;
    }

    printf("Datos en orden inverso:\n");

    i = datos.cant;
    while (i >= 1) {
        printf("Elemento en la posicion %d = %d\n", i, datos.d[i]);
        i--;
    }
	return 0;
}
