// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
	int x, i;
	
	srand(time(NULL));
	for(i=0;i<10;i++){
		x = rand()%6 + 1;
		printf("Face: %d\n",x);
	}
	


     return 0;
}
