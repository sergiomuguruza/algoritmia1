#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[25];
    int DNI;
    char calle[25];
    char ciudad[20];
    char CP[5];
    int edad;
} Testud;

int main() {
    FILE *f;
    Testud alumnos[3];

    // Abrir archivo para escritura
    f = fopen("alumnos.dat", "wb");

    if (f == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return 1;
    }

    // Agregar 3 datos de alumnos al archivo
    strcpy(alumnos[0].nombre, "Juan");
    alumnos[0].DNI = 12345678;
    strcpy(alumnos[0].calle, "Calle 1");
    strcpy(alumnos[0].ciudad, "Ciudad A");
    strcpy(alumnos[0].CP, "12345");
    alumnos[0].edad = 20;

    strcpy(alumnos[1].nombre, "Maria");
    alumnos[1].DNI = 87654321;
    strcpy(alumnos[1].calle, "Calle 2");
    strcpy(alumnos[1].ciudad, "Ciudad B");
    strcpy(alumnos[1].CP, "54321");
    alumnos[1].edad = 22;

    strcpy(alumnos[2].nombre, "Pedro");
    alumnos[2].DNI = 56789012;
    strcpy(alumnos[2].calle, "Calle 3");
    strcpy(alumnos[2].ciudad, "Ciudad C");
    strcpy(alumnos[2].CP, "67890");
    alumnos[2].edad = 25;

    // Escribir datos en el archivo
    fwrite(alumnos, sizeof(Testud), 3, f);

    // Cerrar archivo
    fclose(f);

    printf("Datos escritos en el archivo alumnos.dat\n");

    return 0;
}
