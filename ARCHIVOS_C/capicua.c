#include <stdio.h>
#include <string.h>

#define MAX 81

typedef struct { //declaro el tipo Tdata
    char a[MAX];
    int cant;
} TData;

void CargarPalabra (TData *frase);//declaro la accion CargarPalabra
  
int EsCapicua (TData frase); // declaro la funcion EsCapicua
 
 
int main (void) // funcion principal
{
TData palabra;
CargarPalabra (&palabra);
if (EsCapicua (palabra))
 printf ("Dicha frase es palindroma.");
else
  printf ("Dicha frase no es palindroma.");
getchar();//se utiliza para parar el programa hasta que el usuario apriete una tecla.
return 0;
}

void CargarPalabra (TData *frase)
 {
  printf ("introducir una frase: ");
  scanf("%s",frase->a);//la especificación "%s" lee una cadena de caracteres sin espacios en blanco 
  frase->cant=strlen(frase->a);//Esta línea calcula la longitud de la cadena ingresada 
  //por el usuario utilizando la función strlen de la biblioteca string.h. 
  //Luego, el resultado se asigna al miembro cant de la estructura TData
 }
 
int EsCapicua (TData frase)//en esta funcion no es necesario usar un puntero porque 
//no necesitamos modificar los datos pasados como parametros
 {
 //int longitud=strlen(frase);  //funcion que devuelve la cantidad de caracteres 
int longitud=frase.cant; 
int i=0;
 while (i<=longitud/2 && frase.a[i]==frase.a[longitud-1-i])
  {
  i++;
  }
 if (i>longitud/2)
   return 1;
   else
   return 0;
}

