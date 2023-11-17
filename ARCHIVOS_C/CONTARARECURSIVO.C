/*
lexico
Tdata =< a E arreglo [1..40]de caracteres, cant E (o..40)>
q E Tdata
contA=0

accion contarA (dato: q E Tdata, dato-resultado: contA E Z)
inicio
    segun  
            q.cant = 0 : termina la accion

            q.cant <> 0 : 
                            si q.a[q.cant]=a entonces
                                contA=contA+1
                            fsi

                            q.cant=q.cant+1
                            contarA(q, contA)

    fsegun
faccion

*/

#include <stdio.h>

// Definición de la estructura Tdata
typedef struct {
    char a[40];
    int cant;
} Tdata;

// Prototipo de la función contarA
void contarA(Tdata q, int *contA);

// Implementación de la función contarA
void contarA(Tdata q, int *contA) {
    switch (q.cant) {
        case 0:
            // Termina la función si cant es 0
            break;
        default:
            // Verifica si el carácter en q.a[q.cant] es 'a'
            if (q.a[q.cant - 1] == 'a') {
                (*contA)++;
            }
            // Incrementa q.cant para pasar al siguiente elemento del array
            q.cant++;
            // Llamada recursiva con los nuevos valores de q y contA
            contarA(q, contA);
            break;
    }
}

int main() {
    // Crear una instancia de Tdata con la frase "la casa azul"
    Tdata datos;
    int i = 1;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &datos.cant);
    getchar();

    while (i <= datos.cant) {
        printf("Ingrese el elemento %d: ", i);
        scanf(" %c", &datos.a[i]);  // Cambiado a %c para leer caracteres
        getchar();
        i++;
    }

    printf("El vector ingresado es: ");

    for (i = 1; i <= datos.cant; i++) {
        printf("%c", datos.a[i]);
    }

    // Inicializar el contador
    int contA = 0;

    // Llamada a la función contarA
    contarA(datos, &contA);

    // Mostrar el resultado
    printf("\nCantidad de 'a' en la frase: %d\n", contA);

    return 0;
}
