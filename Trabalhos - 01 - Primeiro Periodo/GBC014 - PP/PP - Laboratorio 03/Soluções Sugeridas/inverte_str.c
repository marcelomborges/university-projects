// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declara��o de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declara��o de variaveis globais, macros e prot�tipos


int main(int argc, char *argv[]){
	char str[100], c;
	int i,j;
	
	printf("Digite um texto: ");
	gets(str);
//	scanf("%[^\n]s",str);
	puts(str);
	for(i=0, j=strlen(str)-1;i<j;i++,j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	puts(str);
	

   return 0;
}
