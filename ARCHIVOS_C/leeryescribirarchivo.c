
#include <stdio.h> 



// arch_texto_copia_uno_al_otro_con_feof_2023.c

FILE* f;
FILE* g;
char c;

int main(){
    f=fopen("test.txt","r");
    g=fopen("test2.txt","w");
    if(f!=NULL){
	while(!feof(f)){ 
	  c = fgetc(f);
              fputc(c,g);
	  printf("%c",c);
	}
    }
    fclose(f);
    fclose(g);
    return 0;
}


