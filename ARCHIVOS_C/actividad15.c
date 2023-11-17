
//alumno: SERGIO MUGURUZA - DNI 24333376 - COMISION 1

/* Algoritmo Burbuja EN SEUDOCODIGO

Lexico
  MAX = 100
  TData = < a E Arreglo[1..MAX] de Z, cant E (1..MAX) >
  datos E TData
  i E Z

    Accion InicializarR (resultado d E Tdata)
    Lexico Local
        i E Z
    Inicio
        para ( i <- 1, i <=d.cant, i <- i+1 ) hacer
            d.a[i] <- random(1,100) //accion que retorna un número al azar entre 1 y 100
        fpara
    fAccion
 
    Accion Burbuja (dato-resultado d E Tdata)
    Lexico local
        i,temp E Z
    Inicio
        para ( i <- d.cant, i > 0, i <- i - 1 ) hacer
        para ( j <-1, j < i, j <- j + 1 ) hacer
            si ( d.a[j] > d.a[j+1] ) entonces

                Intercambiar ( d.a[j] , d.a[j+1] ) //si se usa esta funcion no hace falta lo hace abajo

                temp <- d.a[j]
                d.a[j] <- d.a[j+1]
                d.a[j+1] <- temp
            fsi
        fpara
    fAccion

Inicio
  Salida: mje: "ingrese la cantidad de elementos a cargar"
  Entrada: datos.cant

  InicializarR(datos)

    //muestro el arreglo desordenado

    para ( i <- 1, i <=datos.cant, i <- i+1 ) hacer
      Salida: datos.a[i]
    fpara

  Burbuja(datos)

  //muestro el arreglo ordenado

  para ( i <- 1, i <=datos.cant, i <- i+1 ) hacer
      Salida: datos.a[i]
  fpara

Fin */

//algoritmo burbuja PASADO A C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NMax 100

typedef struct arreglo{

    int a[NMax];
    int cant;

}TData;

int i;
TData datos;

void InicializarR(TData *d);
void Burbuja(TData *d);



int main(){
    
    srand(time(NULL)); //INICIALIZA LA SEMILLA DE LA FUNCION RAMNDOM
    printf("Ingrese la cantidad de elementos a cargar: ");
    scanf("%d", &datos.cant);
    InicializarR(&datos);
    printf("Muestra el arreglo desordenado: \n");
    for (i = 0; i < datos.cant; i++)
    {
        printf("%d \n", datos.a[i]);
    }

    Burbuja(&datos);

    printf("Muestra el arreglo ordenado: \n");
    for (i = 0; i < datos.cant; i++)
    {
        printf("%d \n", datos.a[i]);
    }
    return 0;
}

//ACCION QUE INICIALIZA EL REGISTRO CON LA CANTIDAD PEDIDA DE NUMEROS NATURALES

void InicializarR(TData *d){
int i;

    for (i = 0; i < d->cant; i++)
    {
        d->a[i] = rand() % 100 + 1;
    }
}

//ACCION QUE ORDENA EL REGISTRO DE MANERA ASCENDENTE Y UTILIZANDO EL METODO DE BURBUJAS

void Burbuja(TData *d){
int i;
int temp;
int j;

for (i = d->cant - 1; i > 0; i = i - 1)
{
    for (j = 0; j < i; j++)
    {
        if (d->a[j] > d->a[j+1])
        {
            temp = d->a[j];
            d->a[j] = d->a[j+1];
            d->a[j+1] = temp;
        }   
    }
 }
}