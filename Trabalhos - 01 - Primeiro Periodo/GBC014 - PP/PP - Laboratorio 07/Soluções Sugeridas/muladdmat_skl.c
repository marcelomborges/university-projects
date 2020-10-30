// programa muladdmat.c
// Autor: Cláudio C Rodrigues
// Data: dd/05/2016

#include <stdio.h>
#include <stdlib.h>

int **Alocar_matriz(int m, int n);
void Liberar_matriz (int **v, int m, int n);
void ler_matriz( int **v, int m, int n, char *str);
void print_matriz(int **v, int m, int n, char *str);
void mul_matriz(int **a, int **b, int **c, int ma, int mb , int na, int nb );
void soma_matriz(int **a, int **b, int **c, int ma, int na);

int main(int argc, char* argv[]){
	int **A;  /* matriz a ser alocada */
	int **B;  /* matriz a ser alocada */
	int **C;  /* matriz a ser alocada */
	int la, lb, ca, cb;   /* numero de linhas e colunas da matriz */


	printf("Informe o Numero de Linhas  A : ");
	scanf("%d", &la);
	printf("Informe o Numero de Colunas A : ");
	scanf("%d", &ca);
	printf("Informe o Numero de Linhas  B : ");
	scanf("%d", &lb);
	printf("Informe o Numero de Colunas B : ");
	scanf("%d", &cb);

	/* Chama a funcao para alocar a matriz */
	A = Alocar_matriz (la, ca);
	B = Alocar_matriz (lb, cb);

	/* Chama funcao pra preencher as matrizes  */
	ler_matriz(A,la, ca,"A");
	ler_matriz(B,lb, cb,"B");

	/* chama a funcao pra fazer muultiplicacao das matrizes */
	C = Alocar_matriz (la, cb);
	mul_matriz(A, B, C, la, lb, ca, cb);

	/* chama a funcao pra mostrar na tela o resultado da multiplicacao */
	print_matriz(A,la, ca,"A");
	print_matriz(B,la, ca,"B");
	print_matriz(C,la, ca,"C");

	/* desaloca a memoria, nao mais nescessaria */
	Liberar_matriz (A, la, ca);
	Liberar_matriz (B, lb, cb);
	Liberar_matriz (C, la, cb);

  
    return 0;
}

/* aloca memoria para as matrizes  */
int **Alocar_matriz(int m, int n)
{
	int **v;  /* ponteiro para a matriz */
	int   i;    /* variavel auxiliar      */

	// insira seu código aqui

	return (v); /* retorna o ponteiro para a matriz */
}

/* Libera memoria ocupada pelas matrizes */
void Liberar_matriz (int **v, int m, int n)
{
	int  i;  /* variavel auxiliar */

	// insira seu código aqui

}


void ler_matriz( int **v, int m, int n, char *str)
{
	int i, j;

	printf("Preencha a Matrix: \n");
	// insira seu código aqui
}

/* Essa funcao faz a multiplicacao entre as matrizes.
 * Retorna um matriz com resultado da multplicao
	 para i = 0 até m - 1, de 1 em 1
	   para j = 0 até n - 1, de 1 em 1
	      M[ i , j ] = 0
	      para k = 0 até p - 1, de 1 em 1
	         M[ i , j ] = M[ i , j ] + A[ i , k ] * B[ k , j ]
*/
void mul_matriz(int **a, int **b, int **mr, int ma, int mb , int na, int nb)
{
	int i, j , k;

	// insira seu código aqui

}

void print_matriz(int **a, int ma, int na, char *str)
{
	int i, j;

	/* Impressao das Matrizes */
	printf("MATRIX %s:\n",str);
	// insira seu código aqui
}

void soma_matriz(int **a, int **b, int **c, int ma, int na){
	int i, j;

	// insira seu código aqui
	
}


