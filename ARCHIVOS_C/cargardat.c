#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
} TAlumno;

int main() {
    FILE *f;
    TAlumno alumno;

    f = fopen("alumnos.dat", "ab"); // Abre el archivo en modo escritura binaria

    if (f == NULL) {
        printf("No se pudo abrir el archivo 'alumnos.dat'.\n");
        return 1;
    }

    char respuesta;
    do {
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", alumno.nombre);
        printf("Ingrese la edad del alumno: ");
        scanf("%d", &alumno.edad);

        fwrite(&alumno, sizeof(TAlumno), 1, f); // Escribe el registro en el archivo

        printf("¿Desea agregar otro alumno? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');

    fclose(f);

    return 0;
}
