// Programa : asterisco.c
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

// inserir prototipos de funçoes

// inserir variaveis globais

int main(int argc, char* argv[]){
int n, i, j;

    do{
        printf("Digite a quantida max. de * : ");
        scanf("%d",&n);
    } while(n<0);

    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }


    return 0;
}
