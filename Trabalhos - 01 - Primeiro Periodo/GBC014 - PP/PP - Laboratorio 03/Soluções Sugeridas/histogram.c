// Programa - histograma.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	int i, j, vet[5] = {3, 1, 5, 7, 4};

	for(i=0;i<5;i++) {
		printf("%2d:",vet[i]);
		for(j=0;j<vet[i];j++)
			printf("*");
		printf("\n");
	}

   return 0;
}
