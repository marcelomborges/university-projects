// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 10
int main(int argc, char *argv[]){
	int i, v[N] = { 3, 7, 4, 1, 0, 8, 6, 9, 2, 5};
	printf("Ordem direta:\n");
	for(i=0;i<N;++i) printf("%d ",v[i]);
	printf("\n\nOrdem reversa:\n");
	for(i=N-1;i>=0;--i) printf("%d ",v[i]);
   return 0;
}
