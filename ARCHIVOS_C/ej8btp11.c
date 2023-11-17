#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMax 120

// Definición de la estructura TAlumno
typedef struct {
    char nombre[50];
    int edad;
} TAlumno;

// Definición de la estructura TData
typedef struct {
    TAlumno a[NMax];
    int cant;
} TData;

int main() {
    int i;
    FILE *f;
    TAlumno alumno;
    TData curso;

    f = fopen("alumnos.dat", "rb"); // Abre el archivo en modo lectura binaria

    if (f == NULL) {
        printf("No se pudo abrir el archivo 'alumnos.dat'.\n");
        return 1;
    }

    curso.cant = 0;

    while (curso.cant < NMax && fread(&alumno, sizeof(TAlumno), 1, f) == 1) {
        curso.cant++;
        curso.a[curso.cant - 1] = alumno;
    }

    fclose(f);

    for (i = 0; i < curso.cant; i++) {
        printf("Nombre: %s\n", curso.a[i].nombre);
        printf("Edad: %d\n", curso.a[i].edad);
    }

    return 0;
}
