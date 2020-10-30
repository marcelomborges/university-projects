// Programa - pares&impares.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 10

int main(int argc, char *argv[]){
	int v[N], pares[N], impares[N];
	int i, j=0, k=0;

	for(i=0;i<N;++i) {
		printf("v[%2d]: ",i);
		scanf("%d", &v[i]);
		if (v[i]%2==0) pares[j++] = v[i];
		else impares[k++] = v[i];
	}
	printf("Vetor v:\n\t( ");
	for(i=0;i<N;++i) printf("%d ",v[i]);
	printf(" )\n");
	printf("Vetor pares:\n\t( ");
	for(i=0;i<j;++i) printf("%d ",pares[i]);
	printf(" )\n");
	printf("Vetor impares:\n\t( ");
	for(i=0;i<k;++i) printf("%d ",impares[i]);
	printf(" )\n");
   return 0;
}
