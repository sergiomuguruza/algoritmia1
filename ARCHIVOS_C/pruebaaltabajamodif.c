#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PERSONAS 150

struct Fecha {
    int dia, mes, anio;
};

struct Persona {
    int dni;
    char nombre[50];
    char apellido[50];
    struct Fecha fechaNacimiento;
    int edad;
    char ciudad[50];
    char direccion[100];
    char correo[100];
    char telefono[15];
    bool estaViva;
    struct Fecha fechaFallecimiento;
};

struct RegistroPersonas {
    struct Persona personas[MAX_PERSONAS];
    int cantidad;
};

bool Vacia(struct RegistroPersonas registro) {
    return registro.cantidad == 0;
}

bool Llena(struct RegistroPersonas registro) {
    return registro.cantidad == MAX_PERSONAS;
}

void InsertarPersona(struct RegistroPersonas *registro, struct Persona nuevaPersona) {
    if (!Llena(*registro)) {
        int i = registro->cantidad - 1;
        while (i >= 0 && strcmp(registro->personas[i].apellido, nuevaPersona.apellido) > 0) {
            registro->personas[i + 1] = registro->personas[i];
            i--;
        }
        registro->personas[i + 1] = nuevaPersona;
        registro->cantidad++;
        printf("Persona insertada correctamente.\n");
    } else {
        printf("La lista de personas esta llena.\n");
    }
}

void SuprimirUltimaPersona(struct RegistroPersonas *registro) {
    if (!Vacia(*registro)) {
        registro->cantidad--;
        printf("ultima persona suprimida.\n");
    } else {
        printf("La lista de personas esta vacia.\n");
    }
}

void MostrarPersonas(struct RegistroPersonas registro) {
    if (!Vacia(registro)) {
        printf("\nLista de Personas:\n");
        for (int i = 0; i < registro.cantidad; i++) {
            printf("Persona %d:\n", i + 1);
            printf("DNI: %d\n", registro.personas[i].dni);
            printf("Nombre: %s\n", registro.personas[i].nombre);
            printf("Apellido: %s\n", registro.personas[i].apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n", registro.personas[i].fechaNacimiento.dia,
                   registro.personas[i].fechaNacimiento.mes, registro.personas[i].fechaNacimiento.anio);
            printf("Edad: %d\n", registro.personas[i].edad);
            printf("Ciudad: %s\n", registro.personas[i].ciudad);
            printf("Direccion: %s\n", registro.personas[i].direccion);
            printf("Correo Electronico: %s\n", registro.personas[i].correo);
            printf("Telefono: %s\n", registro.personas[i].telefono);
            if (registro.personas[i].estaViva) {
                printf("Estado: Viva\n");
            } else {
                printf("Estado: Fallecida\n");
                printf("Fecha de Fallecimiento: %d/%d/%d\n", registro.personas[i].fechaFallecimiento.dia,
                       registro.personas[i].fechaFallecimiento.mes, registro.personas[i].fechaFallecimiento.anio);
            }
            printf("--------\n");
        }
    } else {
        printf("La lista de personas esta vacia.\n");
    }
}

int main() {
    struct RegistroPersonas registro = { .cantidad = 0 };
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Alta de Persona\n");
        printf("2. Baja de Persona\n");
        printf("3. Listado de Personas\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                struct Persona nuevaPersona;
                printf("Ingrese el DNI: ");
                scanf("%d", &nuevaPersona.dni);
                printf("Ingrese el Nombre: ");
                scanf("%s", nuevaPersona.nombre);
                printf("Ingrese el Apellido: ");
                scanf("%s", nuevaPersona.apellido);
                printf("Ingrese la Fecha de Nacimiento (dd mm aaaa): ");
                scanf("%d %d %d", &nuevaPersona.fechaNacimiento.dia, &nuevaPersona.fechaNacimiento.mes, &nuevaPersona.fechaNacimiento.anio);
                printf("Ingrese la Edad: ");
                scanf("%d", &nuevaPersona.edad);
                printf("Ingrese la Ciudad: ");
                scanf("%s", nuevaPersona.ciudad);
                printf("Ingrese la Direccion: ");
                scanf("%s", nuevaPersona.direccion);
                printf("Ingrese el Correo Electronico: ");
                scanf("%s", nuevaPersona.correo);
                printf("Ingrese el Telefono: ");
                scanf("%s", nuevaPersona.telefono);
                printf("La persona esta viva (1: Sí / 0: No): ");
                scanf("%d", &nuevaPersona.estaViva);
                if (!nuevaPersona.estaViva) {
                    printf("Ingrese la Fecha de Fallecimiento (dd mm aaaa): ");
                    scanf("%d %d %d", &nuevaPersona.fechaFallecimiento.dia, &nuevaPersona.fechaFallecimiento.mes, &nuevaPersona.fechaFallecimiento.anio);
                }
                InsertarPersona(&registro, nuevaPersona);
                break;
            }
            case 2:
                SuprimirUltimaPersona(&registro);
                break;
            case 3:
                MostrarPersonas(registro);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}
