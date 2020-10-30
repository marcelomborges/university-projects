// Programa : Nome
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

// inserir prototipos de funçoes

// inserir variaveis globais

int main(int argc, char* argv[]){
int x, y, prod=0, i;
do{
  printf("Digite x: ");
  scanf("%d", &x);
} while(x<0);

do{
  printf("Digite y: ");
  scanf("%d", &y);
} while(y<0);

printf("prod = ");
for(i=0; i<y; i++){
    prod = prod + x;
    if(i!=0) printf(" +");
    printf("%3d", x);
}

 printf("\nprod: %d\n", prod);

    return 0;
}
