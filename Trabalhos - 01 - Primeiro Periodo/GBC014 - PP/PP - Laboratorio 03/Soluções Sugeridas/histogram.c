// Programa - histograma.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declara��o de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declara��o de variaveis globais, macros e prot�tipos


int main(int argc, char *argv[]){
     // declara��o de vari�veis locais e comandos
	int i, j, vet[5] = {3, 1, 5, 7, 4};

	for(i=0;i<5;i++) {
		printf("%2d:",vet[i]);
		for(j=0;j<vet[i];j++)
			printf("*");
		printf("\n");
	}

   return 0;
}
