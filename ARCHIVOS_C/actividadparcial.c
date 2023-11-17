//alumno: SERGIO MUGURUZA - DNI 24333376 - COMISION 1


/* Cargar una lista con caracteres (una letra por nodo) y contar cuantas palabras terminan con la letra “a”. Cargar solo minúsculas, para separar palabras usar espacio en blanco.

 // seudocodigo
 
Algoritmo ContarA

Léxico

     TNodo = < info ε Caracter, next ε puntero a TNodo >

     lista ε puntero a TNodo

     pri, seg ε puntero a TNodo

     msg ε Cadena

     cont ε Z

 

     Acción CargarLista(resultado cab ε puntero a TNodo)

     Léxico Local

          i, cant ε Z

          aux, u ε puntero a TNodo

     Inicio

          Salida "Ingrese cantidad de caracteres a cargar"

          Entrada cant

          Obtener (cab)

          (^cab).next  <- nil

          u <- cab

          para (i <- 1 ; i <= cant ; i <- i + 1) hacer

               Obtener(aux)

               Entrada: (^aux).info

               (^aux).next <- nil

               (^u).next <- aux

                u<- aux

          fpara 

     Faccion

 

     Acción Mostrar(dato cab ε puntero a TNodo)

     Léxico Local

          aux ε puntero a TNodo

     Inicio

          aux <- cab

          mientras (^aux).next  <> nil) hacer

             aux <- (^aux).next

             Salida (^aux).info

           fmientras

     Faccion

 

Inicio

     CargarLista(lista)

     Mostrar(lista)

     //InicAdquisicion

     pri <- (^lista).next

     seg <- lista

     //resto del R2 de una sec de pares

      segun 

           pri= nil: msg<- “secuencia vacia”

                       salida: msg

           pri<>nil: cont <- 0

                         mientras pri <> nil hacer

                             //ObtenerSiguientePar

                             seg<- pri

                             pri <- (^pri).next

                             //tratar par

                             si pri <> nil entonces

                                 si (^pri).info= “ “ y (^seg).info = “a” entonces

                                       cont <- cont + 1

                                 fsi

                             sino

                                  si (^seg).info = “a” entonces

                                     cont <- cont +1

                                  fsi

                              fsi

                          fmientras

                          salida: cont         //tratFinal

      fsegun

Fin */


#include <stdio.h>
#include <stdlib.h>

typedef struct TNodo {
    char info;
    struct TNodo* next;
} TNodo;

TNodo *pri;
TNodo *seg;

TNodo* lista = NULL; // Inicializo lista vacía

void Mostrar(TNodo* lista) {
    TNodo *aux = lista;

    printf("Contenido de la lista:\n");
    while (aux != NULL) {
        printf("%c ", aux->info);
        aux = aux->next;
    }
    printf("\n");
}


void cargarlista(TNodo *listado) {
int i, cant;
char value;

TNodo *cab = (TNodo *)malloc(sizeof(TNodo));
TNodo *aux;
TNodo *u;
cab->next = NULL;
u=cab;

  printf("Ingrese cant de letras a cargar:\n");
  scanf("%d",&cant);
   getchar(); // Consumir el salto de línea residual

    for (i = 0; i < cant; i++) {
        aux = (TNodo *)malloc(sizeof(TNodo));
        printf("ingresar caracteres\n");
        scanf("%c",&value);
         getchar(); // Consumir el salto de línea residual
        aux->info = value;
        aux->next = NULL;
        u->next = aux;
        u = aux;
        listado = cab;
    }
    //lista = cab; // Asignar la lista global
}

void ContarA(TNodo* lista) {
    TNodo *pri = lista->next;
    TNodo *seg = lista;
    int cont = 0;

    if (pri == NULL) {
        printf("La secuencia está vacía.\n");
        return;
    }

    while (pri != NULL) {
        seg = pri;
        pri = pri->next;

        if ((pri != NULL && pri->info == ' ' && seg->info == 'a') || (pri == NULL && seg->info == 'a')) {
            cont++;
        }
    }

    printf("Cantidad de palabras terminadas en 'a': %d\n", cont);
}



int main(){
cargarlista(lista);
Mostrar(lista);
ContarA(lista);

return 0;
}