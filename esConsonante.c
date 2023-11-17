// alumno SERGIO MUGURUZA -- comision 1

// problema N° 11 TP5 - Laboratorio N°4
// determinar si un caracter es consonante


#include <stdbool.h>
#include <stdio.h>

char car;
// funcion que chequea si el caracter ingresdo es una vocal , retorna verdadero si lo es y falso si no
bool EsVocal(char n) {
    if (n == 'a'|| n == 'e'|| n == 'i'|| n == 'o'|| n == 'u'|| n == 'A'|| n == 'E'|| n == 'I'|| n == 'O'|| n == 'U') {
        return true;
    } else {
        return false;
    }
}
// funcion que chequea si el caracter ingresdo es una consonante , retorna verdadero si lo es y falso si no
bool EsConsonante(char n) {
    if (('a' <= n && n <= 'z' || 'A' <= n && n <= 'Z') && !EsVocal(n)) { //llama a la funcion es vocal  y la niega
        return true;
    } else {
        return false;
    }
}

int main() {
    printf("Escriba un caracter: "); //entrada del caracter
    scanf(" %c", &car);
    
    if (EsConsonante(car)) {
        printf("El caracter es una consonante.\n");
    } else {
        printf("El caracter no es una consonante.\n");
    }
    
    return 0;
}
