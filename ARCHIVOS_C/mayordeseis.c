#include <stdio.h>
#include <math.h>

float a, b, c, d, e, f ;
float mayorNum;

float mayor (float x, float y);

int main () {
	
	printf("Ingrese el primer numero de seis: ");
    scanf("%f", &a);
	printf("Ingrese el segundo numero de seis: ");
    scanf("%f", &b);
	printf("Ingrese el tercer numero de seis: ");
    scanf("%f", &c);
	printf("Ingrese el cuarto numero de seis: ");
    scanf("%f", &d);
	printf("Ingrese el quinto numero de seis: ");
    scanf("%f", &e);
	printf("Ingrese el sexto numero de seis: ");
    scanf("%f", &f);
	
	mayorNum = mayor(mayor(mayor(a,b),mayor(c,d)),mayor(e,f));
	
	printf("el mayor de los seis numeros es: %2f \n", mayorNum);
	
	return 0;
}

float mayor(float x, float y) {
	float aux;
	aux =((x+y)+fabs(x-y))/2;
	return aux;
}
