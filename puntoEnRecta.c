#include <stdio.h>

typedef struct {
    float x;
    float y;
} Tpunto;

typedef struct {
    float a;
    float b;
} Trecta;

int estaIncluida(Tpunto p, Trecta recta) {
    return (p.y == p.x * recta.a + recta.b);
}

int main() {
    Tpunto p1;
    Trecta rec;
    
    printf("Ingrese las coordenadas del punto (x, y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Ingrese los coeficientes de la recta (a, b): ");
    scanf("%f %f", &rec.a, &rec.b);

    if (estaIncluida(p1, rec)) {
        printf("El punto esta en la recta.");
    } else {
        printf("El punto no esta en la recta.");
    }

    return 0;
}
