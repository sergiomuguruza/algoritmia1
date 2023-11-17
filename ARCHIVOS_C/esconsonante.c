#include <stdio.h>
#include <ctype.h>

int esConsonante(char c) {
    // Convertir el carácter a minúscula
    c = tolower(c);

    // Verificar si el carácter es una letra y no es una vocal
    if (isalpha(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
        return 1;  // Es una consonante
    } else {
        return 0;  // No es una consonante
    }
}

int main() {
    char caracter;

    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);

    if (esConsonante(caracter)) {
        printf("%c es una consonante.\n", caracter);
    } else {
        printf("%c no es una consonante.\n", caracter);
    }

    return 0;
}