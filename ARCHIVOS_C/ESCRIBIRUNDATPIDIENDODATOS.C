#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    Testud alumno;

    // Abrir archivo para escritura en modo binario, añadiendo al final
    f = fopen("alumnos.dat", "ab");

    if (f == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return 1;
    }

    int cantidadAlumnos;
    printf("Ingrese la cantidad de alumnos que desea cargar: ");
    scanf("%d", &cantidadAlumnos);

    // Solicitar datos al usuario y cargar en el archivo
    for (int i = 0; i < cantidadAlumnos; i++) {
        printf("Ingrese datos del alumno %d:\n", i + 1);
        
        printf("Nombre: ");
        scanf(" %[^\n]", alumno.nombre);

        printf("DNI: ");
        scanf("%d", &alumno.DNI);

        printf("Calle: ");
        scanf(" %[^\n]", alumno.calle);

        printf("Ciudad: ");
        scanf(" %[^\n]", alumno.ciudad);

        printf("CP: ");
        scanf("%s", alumno.CP);

        printf("Edad: ");
        scanf("%d", &alumno.edad);

        // Escribir datos en el archivo
        fwrite(&alumno, sizeof(Testud), 1, f);
    }

    // Cerrar archivo
    fclose(f);

    printf("Datos escritos en el archivo alumnos.dat\n");
// Llama al programa leerdatosdedat.exe (tiene que estar en el mismo directorio)
    system("leerdatosdedat.exe");
    return 0;
}
