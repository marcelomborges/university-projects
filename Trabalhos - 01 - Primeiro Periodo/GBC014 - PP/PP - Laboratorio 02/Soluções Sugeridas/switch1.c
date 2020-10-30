// Programa - nomearquivo.c
// Autor: Fulano de Tal
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	int n;
	printf("\nDigite um numero:");
	scanf("%d",&n);
	switch(n){
		case 1:putchar('A');break;
		case 3:putchar('B');
		case 4:putchar('C');
		default:putchar('*');
		case 5:putchar('D');
	}
	putchar('.');puts("");	
	system("pause");

   return 0;
}
