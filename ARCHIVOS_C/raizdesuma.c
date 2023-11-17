#include <stdio.h>
#include <math.h>

int main() {
    double lado1, lado2;
    
    printf("Ingrese el primer lado del rectángulo: ");
    scanf("%lf", &lado1);
    
    printf("Ingrese el segundo lado del rectángulo: ");
    scanf("%lf", &lado2);
    
    double sumaLados = lado1 + lado2;
    double raizCuadrada = sqrt(sumaLados);
    
    // Redondear el resultado a la medida entera más próxima
    int medidaEntera = (int)round(raizCuadrada);
    
    printf("La raíz cuadrada de la suma de los dos lados es: %lf\n", raizCuadrada);
    printf("La medida entera más próxima al valor dado es: %d\n", medidaEntera);
    
    return 0;
}
