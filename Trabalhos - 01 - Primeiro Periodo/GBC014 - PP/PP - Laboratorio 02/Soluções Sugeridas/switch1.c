// Programa - nomearquivo.c
// Autor: Fulano de Tal
// Data: dd/mm/aaaa

//declara��o de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declara��o de variaveis globais, macros e prot�tipos


int main(int argc, char *argv[]){
     // declara��o de vari�veis locais e comandos
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
