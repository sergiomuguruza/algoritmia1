#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 10
#define Telem 1000

typedef struct {
    int a[max];
    int cant;
} Tdata;

void sortear(Tdata* resultado) {
    int i;
    for (i = 0; i < resultado->cant; i++) {
        resultado->a[i] = rand() % Telem;
    }
}

void informar(Tdata dato) {
    int i;
    for (i = 0; i < dato.cant; i++) {
        printf("%d\n", dato.a[i]);
    }
}

int main() {
    srand(time(NULL));
    Tdata numeros;
    numeros.cant = max;
    
    sortear(&numeros);
    informar(numeros);
    
    return 0;
}
