
// alumno SERGIO MUGURUZA -- comision 1

// problema N° 10
// determinar si un numero dado es primo o no


#include <stdio.h>
#include <math.h>

int num, divisor;

int main() {
    
   printf("Ingrese un numero entero positivo: ");
   scanf("%d", &num);
    
   if (num <= 1) {
        printf("El numero no es primo\n");
   } else {
        for (divisor = 2; divisor <= sqrt(num); divisor++) {
            if (num % divisor == 0) {
                printf("El numero no es primo\n");
                break;
            } else {
		printf("El numero es primo\n");
		break;
		   }
         }
        
    }
  return 0;
}