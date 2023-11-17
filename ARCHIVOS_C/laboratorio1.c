// alumno SERGIO MUGURUZA -- comision 1

// laboratorio N 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int edad; // variable para almacenar la edad a analizar

char madurez[35]; // variable tipo cadena para informar resultado

int main() {
	
	printf("Ingrese la edad: ");
    	scanf("%d",&edad);
	
	if (0<=edad && edad<=11)  {
		strcpy(madurez, "el ciudadano es niña/o");
	}	
	else {
			if (12<=edad && edad<=17)  {
				strcpy(madurez, "el ciudadano es adolescente");
			}	
			else { 
				if (18<=edad && edad<=49)  {
					strcpy(madurez, "el ciudadano es adulto");
				}
				else {
					if 	(edad>=50) {
						strcpy(madurez, "el ciudadano es adulto mayor");	
					}	
					else {
						   printf("la edad ingresada no es correcta");
                           exit(1); // funcion exit de la libreria stdlib , la agregue para poder terminar el prog en este punto
                    }						
				}
			}	
	}
		
	printf("La edad pertenece a: %s\n", madurez);

return 0;

}