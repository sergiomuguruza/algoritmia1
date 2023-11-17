
//funcion restaSuc (dato A,B pertenece a Z+) --> Z+
//lexico local
//i pertenece N, C pertenece N
//inicio
//i <-- 1
//C <-- A-B
// repetir
// C <-- C-B
// i <--i+1
// hasta que C<B
// <-- i
// finFuncion
 
 
// lexico
// A,B pertenece Z+
 
//funcion restaSuc (dato A,B pertenece a Z+) --> Z+
//lexico local
//i pertenece N, C pertenece N
//inicio
//i <-- 1
//C <-- A-B
// repetir
// C <-- C-B
// i <--i+1
// hasta que C<B
// <-- i
//finFuncion
 
// Inicio
// entrada: A, B
// resp <-- restaSuc (A,B)
// salida: resp
// fin
 
#include <stdio.h>

int restaSuc(int A, int B) {
    int i = 1, C = A - B;
    while (C >= B) {
        C =C-B;
        i++;
    }
    return i;
}

int main() {
    int A, B;
    printf("Ingrese el valor de A: ");
    scanf("%d", &A);
    printf("Ingrese el valor de B: ");
    scanf("%d", &B);

    int resp = restaSuc(A, B);
    printf("El resultado es: %d\n", resp);

    return 0;
}