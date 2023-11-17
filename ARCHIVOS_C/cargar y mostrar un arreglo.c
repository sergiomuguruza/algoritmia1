#include <stdio.h>

#define max 20

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

    printf("el vector ingresado es: ");
       
       for(i =1 ; i<=datos.cant; i++) {
         
         printf(" %d", datos.d[i]);
        
    }
   

    
	return 0;
}
