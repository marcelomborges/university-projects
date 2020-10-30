/*************************************/
/* program: getmoda.c                   */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2016                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>

int *Alocar_vetor(int n);
void Liberar_vetor (int *v);
void ler_vetor(int *v, int n, char *str);
void print_vetor(int *v, int n, char *str);
int produto_escalar(int *a, int *b, int n);
int get_moda(int *v, int n);


int main(int argc, char* argv[]) {
	int *v1, *v2, moda, prodescalar;

	Alocar_Vetor(v1,10);
	Alocar_Vetor(v2,10);

	print_vetor(v1,10,"v1");
	print_vetor(v2,10,"v2");
	
	moda = get_moda(v1,10);
	printf("Moda de v1: %d\n",moda);
	prodescalar = produto_escalar(v1,v2,n);
	printf("Produto escalr de v1.v2: %d\n",prodescalar);
	
	Liberar_vetor(v1);
	Liberar_vetor(v2);
	return 0;
}


