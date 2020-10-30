// Programa : Nome
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

#define SIZE 5
// inserir prototipos de funçoes

// inserir variaveis globais

int main(int argc, char* argv[]){
    int A[SIZE], B[SIZE], C[SIZE];
    int i;

    printf("Soma Vetorial: C = A + B\n");
    printf("Digite os elementos do vetor A:\n");
    for(i=0;i<SIZE;i++){
        printf("A[%d] : ",i);
        scanf("%d",&A[i]);
    }
    printf("\nDigite os elementos do vetor B:\n");
    for(i=0;i<SIZE;i++){
        printf("B[%d] : ",i);
        scanf("%d",&B[i]);
    }
    for(i=0;i<SIZE;i++){
        C[i]= A[i] + B[i];
    }

    printf("\nVetor C:\n");
    for(i=0;i<SIZE;i++){
        printf("C[%d] : %d\n",i, C[i]);
    }

    return 0;
}
