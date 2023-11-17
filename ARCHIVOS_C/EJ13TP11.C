/* 
Desarrolla un algoritmo que:
a) Almacene en un arreglo unidimensional los nombres de los estudiantes, su DNI y la
nota que le corresponda a un examen. Los datos de cada alumno se obtienen del archivo
"estudiantes.dat" cargado con 100 registros como maximo
y la nota es ingresada por una entrada. Una vez cargado el arreglo se debe informar su
contenido y antes de terminar el algoritmo se deben pasar los datos del arreglo a un
archivo llamado ”notas.dat”

(SEUDOCODIGO)

Algoritmo "ALMACENAR NOTAS"     

Lexico
  NMAX = 100
  Testud=<nombre E cadena, DNI E Z, calle E cadena, ciudad E cadena, CP E cadena, edad E Z >
  Tdatos=< nombre E cadena, DNI E Z, nota E Z >
  TData = < a E Arreglo[1..NMAX] de Tdatos, cant E (1..NMAX) >
  f E archivo de Testud
  g E archivo de Tdatos
  reg E Tdata
  alumno E Testudiante
  i E Z
  msg E cadena

inicio

  abrir ("estudiantes.dat",f,l) // abro archivo para leer datos de los estudiantes
  abrir ("notas.dat",g,a)// abro archvio para ir agregando nota obtenida en el examen de cada estudiante

  mientras NO(eof(f)) hacer
  leer(f, alumno)
   
        reg.a[i].nombre <-- alumno.nombre
        reg.a[i].DNI <-- alumno.DNI
        msg <-- "ingrese nota de: ", alumno.nombre
        salida: msg
        entrada: reg.a[i].nota
    
  fmientras

    //mostrar el registro con los datos cargados
  para (i=1, i<=reg.cant, i=i+1) hacer
    salida: reg.a[i].nombre
            reg.a[i].DNI
            reg.a[i].nota
  fpara  

    //escribo en el archivo notas.dat los datos del registro de notas

 para (i=1, i<=reg.cant, i=i+1) hacer
    escribir(g, reg.a[i].nombre, reg.a[i].DNI, reg.a[i].nota)
 fpara

 cerrar(f)
 cerrar(g)

 fin Algoritmo

  */

 
#include <stdio.h>
#include <string.h>

#define NMAX 100

typedef struct {
    char nombre[25];
    int DNI;
    int nota;
} Tdatos;

typedef struct {
    Tdatos a[NMAX];
    int cant;
} TData;

typedef struct {
    char nombre[25];
    int DNI;
    char calle[25];
    char ciudad[20];
    char CP[5];
    int edad;
} Testud;

int main() {
    FILE *f, *g;
    Testud alumno;
    TData reg;
    int i;
    //char msg[50];

    // Apertura de archivos
    f = fopen("alumnos.dat", "rb");
    g = fopen("notas.dat", "wb");

    // Inicialización del contador de elementos en el arreglo
    reg.cant = 0;

    // Lectura de datos de estudiantes y notas
    while (!feof(f)){
        fread(&alumno, sizeof(Testud), 1, f);
        
        // Almacenar datos en el arreglo
        strcpy(reg.a[reg.cant].nombre, alumno.nombre);
        reg.a[reg.cant].DNI = alumno.DNI;

        // Solicitar nota por entrada
        printf("Ingrese nota de %s: ", alumno.nombre);
        scanf("%d", &reg.a[reg.cant].nota);
        getchar(); // Consumir el salto de línea residual

        // Incrementar el contador de elementos
        reg.cant++;
    }

    // Mostrar datos cargados
    for (i = 0; i < reg.cant; i++) {
        printf("%s\n%d\n%d\n", reg.a[i].nombre, reg.a[i].DNI, reg.a[i].nota);
    }

    // Escribir en el archivo "notas.dat"
    for (i = 0; i < reg.cant; i++) {
        fwrite(&reg.a[i], sizeof(TData),1, g);
    }

    // Cierre de archivos
    fclose(f);
    fclose(g);

    return 0;
}
