#include <stdio.h>
#include <math.h>

int main() {
    double lado1, lado2;
    
    printf("Ingrese el primer lado del rectángulo: ");
    scanf("%lf", &lado1);
    
    printf("Ingrese el segundo lado del rectángulo: ");
    scanf("%lf", &lado2);
    
    double productoLados = lado1 * lado2;
    double raizProducto = sqrt(productoLados);
    
    // Encontrar la medida entera superior más próxima
    int medidaEnteraSuperior = (int)ceil(raizProducto);
    
    printf("La raíz cuadrada del producto de los dos lados es: %lf\n", raizProducto);
    printf("La medida entera superior más próxima al valor dado es: %d\n", medidaEnteraSuperior);
    
    return 0;
}
