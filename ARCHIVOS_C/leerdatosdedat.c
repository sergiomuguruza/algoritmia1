#include <stdio.h>

/*typedef struct {
    char nombre[25];
    int DNI;
    int nota;
} Tdatos;*/

typedef struct {
    char nombre[25];
    int DNI;
    char calle[25];
    char ciudad[20];
    char CP[5];
    int edad;
} Testudiante;


int main() {
    FILE *g;
    //Tdatos notas;
    Testudiante alumnos;

    // Abrir archivo para lectura
    g = fopen("alumnos.dat", "rb");

    if (g == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // Leer y mostrar registros del archivo
    printf("Registros en el archivo alumnos.dat:\n");
    while (fread(&alumnos, sizeof(Testudiante), 1, g) == 1) {//ACA ==1 ES PARA VERIFICAR SI FUE EXITOSA LA LECTURA DE 1 REGISTRO
        printf("Nombre: %s\nDNI: %d\nCalle: %s\nCiudad: %s\nCP: %s\nEdad: %d\n\n", alumnos.nombre, alumnos.DNI, alumnos.calle,alumnos.ciudad,alumnos.CP,alumnos.edad);
    }

    // Cerrar archivo
    fclose(g);

    return 0;
}
