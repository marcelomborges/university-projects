// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char* argv[]){
     // declaração de variáveis locais e comandos
	int opn1, opn2;
	char opr;
	
	printf("Calcula: ");
	scanf("%d %c %d",&opn1,&opr,&opn2);
	
	switch(opr){
		case '+': printf("%d %c %d = %d\n",opn1,opr,opn2,opn1+opn2);break;
		case '-': printf("%d %c %d = %d\n",opn1,opr,opn2,opn1-opn2);break;
		case 'x': printf("%d %c %d = %d\n",opn1,opr,opn2,opn1*opn2);break;
		case '/': printf("%d %c %d = %d\n",opn1,opr,opn2,opn1/opn2);break;
		case '^': printf("%d %c %d = %f\n",opn1,opr,opn2,pow(opn1,opn2));break;
		default:printf("Opcao inválida...");
	}

   return 0;
}
