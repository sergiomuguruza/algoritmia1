#include <stdio.h>
#include <stdlib.h>

#define NMax 120

typedef struct {
    char texto[NMax];
    int cant;
} TData;

int main() {
    FILE *f;
    char cad[120];
    TData miTexto;

    // Abre el archivo en modo lectura
    f = fopen("test.txt", "r");

    // Inicializa la cantidad de caracteres leídos en 0
    //miTexto.cant = 1;

    // Lee caracteres del archivo hasta alcanzar el límite o el final del archivo
   if(f!=NULL){
    
        fgets(cad,120,f);
       // printf("%s",cad);
       // miTexto.texto[1]=cad; 
        strcpy(miTexto.texto, cad);
        //  printf("%s",miTexto.texto);
    
   }
    // Cierra el archivo
    fclose(f);

    // Imprime los primeros 120 caracteres
    printf("Primeros %d caracteres: %s\n", NMax, miTexto.texto);

    return 0;
}
