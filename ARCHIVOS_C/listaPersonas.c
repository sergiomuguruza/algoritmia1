#include <stdio.h>
#include <string.h>

#define Nmax 150

typedef struct {
    int dia, mes, anio;
} Tfecha;

typedef struct {
    int dni;
    char nombre[50];
    char apellido[50];
    Tfecha Fnac;
    int edad;
    char ciudad[50];
    char direccion[100];
    char correo[50];
    char telefono[20];
    int estaViva;
    Tfecha Ffallec;
} Tpersona;

typedef struct {
    Tpersona a[Nmax];
    int cant;
} Tdata;

int vacia(Tdata b) {
    return b.cant == 0;
}

int llena(Tdata l) {
    return l.cant == Nmax;
}

void insertar(Tdata *r, Tpersona nuevo) {
    if (!llena(*r)) {
        int i = r->cant - 1;
        while (i >= 0 && strcmp(r->a[i].apellido, nuevo.apellido) > 0) {
            r->a[i + 1] = r->a[i];
            i--;
        }
        r->a[i + 1] = nuevo;
        r->cant++;
        printf("Persona insertada correctamente a la lista.\n");
    } else {
        printf("La lista esta llena.\n");
    }
}

void suprimir(Tdata *s) {
    if (!vacia(*s)) {
        s->cant--;
    } else {
        printf("La lista esta vacia.\n");
    }
}

void mostrar(Tdata p) {
    int i;
    if (!vacia(p)) {
        printf("Mostrar listado:\n");
        printf("-------------------------------------\n");
        for (i = 0; i < p.cant; i++) {
            printf("DNI: %d\n", p.a[i].dni);
            printf("Nombre: %s\n", p.a[i].nombre);
            printf("Apellido: %s\n", p.a[i].apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n", p.a[i].Fnac.dia, p.a[i].Fnac.mes, p.a[i].Fnac.anio);
            printf("Edad: %d\n", p.a[i].edad);
            printf("Ciudad: %s\n", p.a[i].ciudad);
            printf("Direccion: %s\n", p.a[i].direccion);
            printf("Correo: %s\n", p.a[i].correo);
            printf("Telefono: %s\n", p.a[i].telefono);
            if (p.a[i].estaViva) {
                printf("Estado: Viva\n");
            } else {
                printf("Estado: Fallecida\n");
                printf("Fecha de Fallecimiento: %d/%d/%d\n", p.a[i].Ffallec.dia, p.a[i].Ffallec.mes, p.a[i].Ffallec.anio);
            }
            printf("-------------------------------------\n");
        }
    } else {
        printf("La lista esta vacia.\n");
    }
}

int main() {
    Tdata base;
    base.cant = 0;
    int opcion;

    do {
        printf("MENU:\n");
        printf("1  ALTA DE PERSONA\n");
        printf("2  BAJA DE PERSONA\n");
        printf("3  LISTAR PERSONAS\n");
        printf("4  SALIR\n");
        printf("INGRESE SU OPCION: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Tpersona nuevo;
                printf("Ingrese DNI: ");
                scanf("%d", &nuevo.dni);
                printf("Ingrese Nombre: ");
                scanf("%s", nuevo.nombre);
                printf("Ingrese Apellido: ");
                scanf("%s", nuevo.apellido);
                printf("Ingrese Fecha de Nacimiento (dia mes anio): ");
                scanf("%d %d %d", &nuevo.Fnac.dia, &nuevo.Fnac.mes, &nuevo.Fnac.anio);
                printf("Ingrese Edad: ");
                scanf("%d", &nuevo.edad);
                printf("Ingrese Ciudad: ");
                scanf("%s", nuevo.ciudad);
                printf("Ingrese Direccion: ");
                scanf("%s", nuevo.direccion);
                printf("Ingrese Correo: ");
                scanf("%s", nuevo.correo);
                printf("Ingrese Telefono: ");
                scanf("%s", nuevo.telefono);
                printf("¿Esta viva? (1 para Si, 0 para No): ");
                scanf("%d", &nuevo.estaViva);
                if (!nuevo.estaViva) {
                    printf("Ingrese Fecha de Fallecimiento (dia mes anio): ");
                    scanf("%d %d %d", &nuevo.Ffallec.dia, &nuevo.Ffallec.mes, &nuevo.Ffallec.anio);
                }
                insertar(&base, nuevo);
                break;
            }
            case 2:
                suprimir(&base);
                break;
            case 3:
                mostrar(base);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}
