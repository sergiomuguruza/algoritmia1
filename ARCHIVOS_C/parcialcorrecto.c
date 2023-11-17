#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNodo {
    char info;
    struct TNodo* next;
} TNodo;

void CargarLista(TNodo** cab) {
    char entrada[100]; // Asumiendo que la entrada es menor a 100 caracteres
    TNodo *aux, *u;

    printf("Ingrese la cadena de caracteres en minúsculas y espacios: ");
    gets(entrada);

    *cab = (TNodo*)malloc(sizeof(TNodo));
    (*cab)->next = NULL;
    u = *cab;

    int i = 0;
    while (entrada[i] != '\0') {
        aux = (TNodo*)malloc(sizeof(TNodo));
        aux->info = entrada[i];
        aux->next = NULL;
        u->next = aux;
        u = aux;
        i++;
    }
}

void Mostrar(TNodo* cab) {
    TNodo* aux = cab->next;

    while (aux != NULL) {
        printf("%c", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

int ContarPalabrasConA(TNodo* lista) {
    int cont = 0;
    TNodo *pri = lista->next;
    TNodo *seg = lista;

  while (pri != NULL) {
        if ((pri->info == ' ' || pri->next == NULL) && (seg->info == 'a' || (pri->next == NULL && pri->info == 'a'))) {
            cont++;
        }

        seg = pri;
        pri = pri->next;
    }

    return cont;
}

int main() {
    TNodo* lista = NULL;
    int palabrasConA = 0;

    CargarLista(&lista);
    Mostrar(lista);

    palabrasConA = ContarPalabrasConA(lista);
    
    printf("Cantidad de palabras que terminan con 'a': %d\n", palabrasConA);

    return 0;
}
