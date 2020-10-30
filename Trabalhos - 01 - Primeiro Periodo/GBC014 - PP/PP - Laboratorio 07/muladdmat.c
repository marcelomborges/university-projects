/*
Programa: Laboratorio 07 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 16/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
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
	int **D;  /* matriz a ser alocada */
	int la, lb, ca, cb;   /* numero de linhas e colunas da matriz */

	printf("Calculo a soma e a multiplicacao de matrizes alocadas dinamicamente.\n");
	printf("Observacao: As matrizes dadas (A e B) devem ser quadradas para ser possivel calcular a soma e a multiplicacao.\n\n");

    do
    {
        printf("Informe o Numero de Linhas A : ");
        scanf("%d", &la);
    }
    while(la <= 0);
    do
    {
        printf("Informe o Numero de Colunas A : ");
        scanf("%d", &ca);
    }
    while(ca <= 0);
    do
    {
        printf("Informe o Numero de Linhas B : ");
        scanf("%d", &lb);
    }
    while(lb <= 0);
    do
    {
        printf("Informe o Numero de Colunas B : ");
        scanf("%d", &cb);
    }
    while(cb <= 0);
    printf("\n");

    if((la != lb)||(ca != cb)||(ca != lb))
    {
        printf("\nERRO: Nao eh possivel operar com essas matrizes.\n");
        exit(1);
    }

	/* Chama a funcao para alocar a matriz */
	A = Alocar_matriz (la, ca);
	B = Alocar_matriz (lb, cb);

	/* Chama funcao pra preencher as matrizes  */
	ler_matriz(A, la, ca, "A");
	ler_matriz(B, lb, cb, "B");

	/* Chama a funcao pra fazer muultiplicacao das matrizes */
	C = Alocar_matriz (la, cb);
	mul_matriz(A, B, C, la, lb, ca, cb);

	/* Chama a funcao para fazer a soma das matrizes */
	D = Alocar_matriz(la, ca);
	soma_matriz(A, B, D, la, ca);

	/* Chama a funcao pra mostrar na tela o resultado da multiplicacao */
	print_matriz(A, la, ca, "A");
	print_matriz(B, lb, cb, "B");
	printf("Matriz da multiplicacao de A e B (A*B):\n");
	print_matriz(C, la, ca, "C");
	printf("Matriz da soma de A e B (A+B):\n");
	print_matriz(D, la, ca, "D");

	/* Desaloca a memoria, nao mais nescessaria */
	Liberar_matriz (A, la, ca);
	Liberar_matriz (B, lb, cb);
	Liberar_matriz (C, la, cb);
	Liberar_matriz (D, la, ca);

    return 0;
}

/* aloca memoria para as matrizes  */
int **Alocar_matriz(int m, int n)
{
	int **v;  /* ponteiro para a matriz */
	int i;    /* variavel auxiliar      */

	v = (int**) malloc (m * sizeof(int*));
	if(v == NULL)
    {
        printf("Erro de alocacao na matriz 1.");
        return NULL;
    }
    for(i = 0; i < m; i++)
    {
        v[i] = (int*) malloc(n * sizeof(int));
        if(v[i] == NULL)
        {
            printf("Erro de alocacao na matriz 2.");
            return NULL;
        }
    }

	return (v); /* retorna o ponteiro para a matriz */
}

/* Libera memoria ocupada pelas matrizes */
void Liberar_matriz (int **v, int m, int n)
{
	int  i;  /* variavel auxiliar */

	for(i = 0; i < m; i++)
    {
        if(v[i] != NULL)
        {
            free(v[i]);
        }
    }
    if(v != NULL)
    {
        free(v);
    }
}

void ler_matriz( int **v, int m, int n, char *str)
{
	int i, j;

	printf("Preencha a Matrix: \n");

	for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%s[%d][%d]: ",str,i,j);
            scanf("%d",&v[i][j]);
        }
    }
    printf("\n");
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

	for(i = 0; i < ma; i++)
    {
        for(j = 0; j < nb; j++)
        {
            mr[i][j] = 0;
            for(k = 0; k < na; k++)
            {
                mr[i][j] = mr[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
}

void print_matriz(int **a, int ma, int na, char *str)
{
	int i, j;

	printf("%2s|",str);

    for(j = 0; j < na; j++)
    {
        printf("%3d ",j);
    }
    printf("\n");

    for(i = 0; i < (na * 3) + 4; i++)
    {
        if(i == 2) printf("|");
        else printf("-");
    }
    printf("\n");

    for(i = 0; i < ma; i++)
    {
        printf("%2d|",i);/*Parte da estrutura exterior da matriz*/
        for(j = 0; j < na; j++)
        {
            printf("%3d ",*(*(a+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}

void soma_matriz(int **a, int **b, int **c, int ma, int na)
{
	int i, j;

	for(i = 0; i < ma; i++)
    {
        for(j = 0; j < na; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
