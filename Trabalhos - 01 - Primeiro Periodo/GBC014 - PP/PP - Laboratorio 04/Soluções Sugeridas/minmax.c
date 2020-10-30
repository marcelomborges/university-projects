// Programa - minmax.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
	int l, c, i, j, linha;
	float min=999999.99999, max=-999999.0;
	float m[100][100];

	printf("Digite o num. de linhas da matriz: ");
	scanf("%d",&l);
	printf("Digite o num. de colunas da matriz: ");
	scanf("%d",&c);
	puts("Matriz m:");
	for(i=0;i<l;i++) {
		for(j=0;j<c;j++){
			printf("m[%d][%d]: ",i,j);
			scanf("%f",&m[i][j]);
		}
	}
//    system("CLS");
	for(i=0;i<l;i++) {
		for(j=0;j<c;j++){
			if(m[i][j]<min){
				min = m[i][j];
				linha = i;
			}
		}
	}
	for(j=0;j<c;j++){
		if(m[linha][j]>max){
			max = m[linha][j];
		}
	}

	puts("Matriz m:");
	for(i=0;i<l;i++) {
		for(j=0;j<c;j++){
			printf("%.2f\t ",m[i][j]);
		}
		printf("\n");
	}

	printf("MinMax: %f\n",max);

    return 0;
}
