#include <stdio.h>

int main() {
    int puntosUsuario, aux, montoDescontar;
    
    // Pedimos al usuario que ingrese sus puntos
    printf("Ingrese sus puntos: ");
    scanf("%d", &puntosUsuario);

    // Calculamos el monto a descontar
    aux = puntosUsuario / 200;
    montoDescontar = aux * 100;
	printf("el auxiliar vale:%d\n", aux);
    // Mostramos el monto a descontar al usuario
    printf("El monto a descontar en su próxima compra es: %d\n", montoDescontar);

    return 0;
}
