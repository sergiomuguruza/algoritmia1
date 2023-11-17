//alumno: SERGIO MUGURUZA - DNI 24333376 - COMISION 1

#include <stdio.h>

void CargarArchivo(const char *nomExt) {
    char x;
    FILE *f;
    printf("Ingrese un caracter o *: ");
    f = fopen(nomExt, "w");
    if (f == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }
    while ((x = getchar()) != '*') {
        fputc(x, f);

      
    }
    fclose(f);
}

int main() {
    char c, x;
    int iguales = 0, distintos = 0;

    CargarArchivo("secu.txt");

    printf("Ingrese un caracter: ");
    scanf(" %c", &c);

    FILE *f = fopen("secu.txt", "r");

    if (f == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((x = fgetc(f)) != EOF) {
        if (c == x) {
            iguales++;
        } else {
            distintos++;
        }
    }

    fclose(f);

    printf("Cantidad de caracteres iguales a '%c': %d\n", c, iguales);
    printf("Cantidad de caracteres distintos a '%c': %d\n", c, distintos);

    return 0;
}
