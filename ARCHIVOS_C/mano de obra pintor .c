#include <stdio.h>

float altoPared;
float anchoPared;
float costoM2;
float supPared;
float costoMdeO;


int
main ()
{
  printf ("\n Ingrese alto de la pared \t"); 
  scanf ("%f", &altoPared);
  printf ("\n Ingrese ancho de la pared \t");
  scanf ("%f", &anchoPared);
  printf ("\n Ingrese costo de mano de obra x m2 \t");
  scanf ("%f", &costoM2);
  printf ("\n Ingrese % aumento en los costos, si no hay aumento ingrese 0 \t");
  scanf ("%f", &aumento);
  supPared = anchoPared * altoPared;
  costoMdeO = supPared * costoM2;
  costoMdeO = costoMdeO + costoMdeO * aumento/ 100;
  printf ("el costo de la mano de obra para pintar la pared es: %.2f\n",
	  costoMdeO);

  return 0;
}
