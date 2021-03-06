// programa muladdmat.c
// Autor: Cl�udio C Rodrigues
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
	int **C = NULL;  /* matriz a ser alocada */
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
	if(ca==lb) {
		C = Alocar_matriz (la, cb);
		mul_matriz(A, B, C, la, lb, ca, cb);
	}

	/* chama a funcao pra mostrar na tela o resultado da multiplicacao */
	print_matriz(A,la, ca,"A");
	print_matriz(B,lb, cb,"B");
	print_matriz(C,la, cb,"C");

	/* desaloca a memoria, nao mais nescessaria */
	Liberar_matriz (A, la, ca);
	Liberar_matriz (B, lb, cb);
	Liberar_matriz (C, la, cb);

  
    return 0;
}

/* aloca memoria para as matrizes  */
int **Alocar_matriz(int m, int n) {
	int **v;  /* ponteiro para a matriz */
	int   i;    /* variavel auxiliar      */

	if (m < 1 || n < 1) { /* verifica parametros recebidos */
		printf ("** Erro: Parametro invalido **\n");
		return (NULL);
	}

	/* aloca as linhas da matriz */
	v = calloc (m, sizeof(int *));	/* Um vetor de m ponteiros para int */
	if (v == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
		return (NULL);
	}

	/* aloca as colunas da matriz */
	for ( i = 0; i < m; i++ ) {
		v[i] =  calloc (n, sizeof(int));	/* m vetores de n int */
		if (v[i] == NULL) {
			printf ("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}

	return (v); /* retorna o ponteiro para a matriz */
}

/* Libera memoria ocupada pelas matrizes */
void Liberar_matriz (int **v, int m, int n) {
	int  i;  /* variavel auxiliar */

	if (v == NULL)
	   	return;

	if (m < 1 || n < 1) {  /* verifica parametros recebidos */
		printf ("** Erro: Parametro invalido **\n");
		return;
	}

	for (i = 0; i < m; i++)
	   	free (v[i]); /* libera as linhas da matriz */

	free (v);      /* libera a matriz (vetor de ponteiros) */

}


void ler_matriz( int **v, int m, int n, char *str) {
	int i, j;

	printf("Digite os elementos da Matriz %s: \n",str);
	for (i = 0 ; i < m; i++ )
		for (j = 0; j < n; j++) {
			printf("%s[%d][%d]: ",str, i, j);
			scanf("%d", &v[i][j]);
		}
		printf("\n");

}

/* Essa funcao faz a multiplicacao entre as matrizes.
 * Retorna um matriz com resultado da multplicao
	 para i = 0 at� m - 1, de 1 em 1
	   para j = 0 at� n - 1, de 1 em 1
	      M[ i , j ] = 0
	      para k = 0 at� p - 1, de 1 em 1
	         M[ i , j ] = M[ i , j ] + A[ i , k ] * B[ k , j ]
*/
void mul_matriz(int **a, int **b, int **c, int ma, int mb , int na, int nb) {
	int i, j , k;

	for (i = 0 ; i < ma; i++ )
		for (j = 0; j < nb; j++){
			c[i][j] = 0;
			for (k = 0; k < na; k++)
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
		}

}

void print_matriz(int **a, int ma, int na, char *str)
{
	int i, j;

	/* Impressao das Matrizes */
	printf("Matriz %s:\n",str);
	for (i = 0; i < ma; i++) {
		for ( j = 0; j < na; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

void soma_matriz(int **a, int **b, int **c, int ma, int na){
	int i, j;

	for (i = 0 ; i < ma; i++ ) {
		for (j = 0; j < na; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
}


