#include <stdio.h>
#include <stdlib.h>

// arch_binario_fread_con_feof_imprime_el_ultimo_repetido_2023.c
// compilarlo, ejecutarlo y analizar que sucede con el ultimo registro

typedef struct {
  char nombre[30]; 
  int edad;
} TAlumno;
TAlumno alumno; // para manipular el contenido del archivo
FILE *f; // FILE es la estructura que define un descriptor de archivo. Se puede usar para cualquier tipo de archivo

int main() {
  f=fopen("alumnos.dat","r"); 
  if(f!=NULL){
    while (!feof(f)){    
      fread(&alumno,sizeof(alumno),1,f); 
      printf(" NOMBRE = %s ",alumno.nombre);
      printf(" EDAD = %d ",alumno.edad);
      printf("\n");  
    } 
  }
  fclose(f);
  return 0;
}