// Programa - simetrica.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declaração de variaveis globais, macros e protótipos
#define N 4

int main(int argc, char *argv[]){
	int i, j, simetrica;
	int A[N][N] ;

	printf("Matriz A:\n\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("A[%d][%d]= ",i, j);
			scanf("%d",&A[i][j]);
		}
	}

	printf("Matriz A:\n\n");
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++)
			printf("A[%d][%d]=%d\t",i, j,A[i][j]);
		putchar('\n');
	}

	simetrica = 1;
	for(i=0; i<N-1; i++) {
		for(j=i+1; j<N; j++)
			if(A[i][j]!=A[j][i]) {
				simetrica = 0;
				break;
			}
	}
	printf("\nA matriz A %s\n", simetrica? "eh simetrica" : "nao eh simetrica");
	return 0;
}
