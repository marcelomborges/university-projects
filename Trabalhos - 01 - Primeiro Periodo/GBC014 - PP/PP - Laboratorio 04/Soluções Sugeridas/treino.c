// Programa - treino.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NATLETAS 3
#define NSESSOES  6
// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
	int i, j;
	float treino[NATLETAS][NSESSOES+1];
	float soma, menortempo=999999;

	puts("Digite a cronometragem do treino (s):");
	for(i=0;i<NATLETAS;i++) {
        printf("Atleta %d: \n",i);
        soma = 0.0;
		for(j=0;j<NSESSOES;j++){
			printf("dia %d: ",j);
			scanf("%f",&treino[i][j]);
			soma += treino[i][j];
		}
		treino[i][NSESSOES]= soma/NSESSOES;
	}
	for(i=0;i<NATLETAS;i++) {;
        printf("Atleta %d --> ",i);
        menortempo = 9999999;
		for(j=0;j<NSESSOES;j++){
			if(treino[i][j]<menortempo){
				menortempo = treino[i][j];
			}
		}
        printf("menor tempo: %.2f\t-\tmedia: %.2f\n",menortempo,treino[i][6]);
	}

	puts("\n");

    return 0;
}
