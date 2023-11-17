#include <stdio.h>

int main() {
    int hh, mi, se, cMin, cHor;
    // entrada de la hora en formato dos dígitos
    printf("Ingrese la hora (formato hh): ");
    scanf("%d", &hh);
    // entrada de los minutos en formato dos dígitos
    printf("Ingrese los minutos (formato mi): ");
    scanf("%d", &mi);
    // entrada de los segundos en formato dos dígitos
    printf("Ingrese los segundos (formato se): ");
    scanf("%d", &se);
    
    cMin = 0; // inicializo variables de control cambio de minuto y cambio de hora
    cHor = 0;
    se = se + 1;
    if (se > 59) {
        se = 0;
        cMin = 1;
    }
    mi = mi + cMin;
    if (mi > 59) {
        mi = 0;
        cHor = 1;
    }
    hh = hh + cHor;
    if (hh > 23) {
        hh = 0;
    }
    
    // hora siguiente en formato hora, minutos, segundos
    printf("La hora siguiente es: %02d:%02d:%02d\n", hh, mi, se);
    return 0;
}
