// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
	char str[100], c;
	char vogal[5] = {'A','E','I','O','U'};
	char codigo[5] = {'4','3','1','0','6'};
	int i,j;
	
	printf("Digite um texto: ");
	gets(str);
//	scanf("%[^\n]s",str);
	puts(str);
	for(i=0;i<strlen(str);i++) {
		if(str[i]==' ') str[i] = '_';
		else {
			c = toupper(str[i]);
			for(j=0;j<5;j++) {
				if(c==vogal[j]) {
					str[i] = codigo[j];
					break;
				}
			}
		}
	}
	puts(str);
	

   return 0;
}
