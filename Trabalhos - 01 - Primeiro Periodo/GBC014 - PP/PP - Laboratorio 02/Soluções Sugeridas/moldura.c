// Programa : moldura.c
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

// inserir prototipos de funçoes

// inserir variaveis globais

int main(int argc, char* argv[]){
int n, m, i, j;

    printf("Digite as dimensoes da moldura (n,m): \n");
    do{
        printf("n ?");
        scanf("%d",&n);
    } while(n<0);
    do{
        printf("m ?");
        scanf("%d",&m);
    } while(m<0);
    printf("moldura(%d,%d):\n",n,m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i==1 || i==n || j==1 || j==m) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}
