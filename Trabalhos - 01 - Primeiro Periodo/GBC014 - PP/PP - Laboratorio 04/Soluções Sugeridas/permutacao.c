// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define SIZEMAX 100

int main(int argc, char *argv[]){
	int A[SIZEMAX][SIZEMAX];    //{0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1}; //{{0,1,0,1},{0,0,1,0},{1,0,0,0},{0,0,0,1}};
	int N, somac, somal;
	int i,j,permutacao;

	printf("Digite a dimensao N: ");
	scanf("%d", &N);

	printf("Digite os elementos da Matriz: \n");
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++) {
			printf("A[%d][%d]: ",i,j);
			scanf("%d",&A[i][j]);
	}}


	permutacao = 1;     // Permutacao eh verdadde
	for(i=0;i<N;i++) {
		somac = somal = 0;
		for(j=0;j<N;j++) {
			somal += A[i][j];
			somac += A[j][i];
		}
		if(somal != 1 || somac != 1) {
			permutacao = 0; //Permutacao eh falso
			break;
		}
	}
	printf("Matriz a:\n");
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++)
			printf("\t%d",A[i][j]);
		printf("\n");
	}
	printf("\nPermutacao: %s\n",permutacao? "Sim" : "Nao");

     return 0;
}
