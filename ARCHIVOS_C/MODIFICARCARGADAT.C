#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int DNI;
    char calle[50];
    char ciudad[50];
    char CP[10];
    int edad;
} Testud;

int main() {
    FILE *f;
    Testud alumno;

    // Abrir archivo para lectura y escritura binaria
    f = fopen("alumnos.dat", "r+b");

    if (f == NULL) {
        printf("Error al abrir el archivo para lectura y escritura.\n");
        return 1;
    }

    char nombreBuscado[50];
    printf("Ingrese el nombre o parte del nombre del estudiante que desea modificar: ");
    scanf(" %[^\n]", nombreBuscado);

    // Consumir el carácter de nueva línea residual
    getchar();

    int encontrado = 0;

    // Buscar el registro con el nombre especificado
    while (fread(&alumno, sizeof(Testud), 1, f) == 1) {
        // Comparar si el nombreBuscado está en el nombre del estudiante
        if (strstr(alumno.nombre, nombreBuscado) != NULL) {
            encontrado = 1;

            // Mostrar el registro original
            printf("Registro original:\n");
            printf("Nombre: %s\nDNI: %d\nCalle: %s\nCiudad: %s\nCP: %s\nEdad: %d\n\n",
                   alumno.nombre, alumno.DNI, alumno.calle, alumno.ciudad, alumno.CP, alumno.edad);

            // Modificar datos (puedes modificar otras propiedades según tus necesidades)
            printf("Ingrese el nuevo nombre completo: ");
            scanf(" %[^\n]", alumno.nombre);

            printf("Ingrese la nueva calle: ");
            scanf(" %[^\n]", alumno.calle);

            printf("Ingrese la nueva ciudad: ");
            scanf(" %[^\n]", alumno.ciudad);

            printf("Ingrese el nuevo código postal: ");
            scanf("%s", alumno.CP);

            printf("Ingrese la nueva edad: ");
            scanf("%d", &alumno.edad);

            // Posicionarse en la posición correcta en el archivo
            fseek(f, sizeof(Testud), SEEK_CUR);

            // Escribir el registro modificado en el archivo
            fwrite(&alumno, sizeof(Testud), 1, f);

            printf("Registro modificado:\n");
            printf("Nombre: %s\nDNI: %d\nCalle: %s\nCiudad: %s\nCP: %s\nEdad: %d\n\n",
                   alumno.nombre, alumno.DNI, alumno.calle, alumno.ciudad, alumno.CP, alumno.edad);

            break; // Salir del bucle una vez que se haya modificado el registro
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún estudiante con el nombre proporcionado.\n");
    }

    // Cerrar archivo
    fclose(f);

    return 0;
}
