/*
Programa: Trabalho de PP 02 - Problema 9 (P9)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 04/05/2016
Descricao: Recebe a ordem de uma matriz, a quantidade de pontos que quer marcar, e as coordenadas desses pontos. Depois escreve 9
           no ponto escolhido, e incrementa 1 um nas posicoes em volta desse ponto se esses elementos forem menores do que 9.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
void matriz(int[][100],int);
void imprime_matriz(int[][100],int);

int main ()
{
    /*Declaracao de Variaveis*/
    int i, j, n, marc, m[100][100];
    char d;
    /*-----------------------*/

    printf("Faco marcacoes em pontos especificos da matriz escolhidos.\n");
    printf("Marco com o numero 9 no ponto escolhido, e incremento nas casas em torno do numero escolhido.\n\n");

    do
    {
        printf("Digite a ordem da matriz (ate 99): ");
        scanf("%d",&n);
    }
    while((n <= 0) || (n > 99));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            m[i][j] = 0;
        }
    }

    system("cls");
    printf("Matriz Escolhida:\n\n");
    imprime_matriz(m,n);
    printf("\n");

    printf("Quantos pontos voce deseja marcar na matriz?\n");
    do
    {
        printf("Digite um numero inteiro e positivo: ");
        scanf("%d",&marc);
    }
    while(marc <= 0);
    printf("\n");

    for(i = 0; i < marc; i++)
    {
        printf("(%d) Em relacao a posicao que voce deseja \"marcar\":\n",i + 1);
        matriz_marca(m,n);
        printf("\n");

        system("cls");
        printf("Matriz Marcada:\n\n");
        imprime_matriz(m,n);
        printf("\n");
    }

    return 0;
}

/*AREA DAS DEMAIS FUNCOES----------------------------------------------------------------------------------------------------------*/

void matriz_marca(int m[][100],int n)
{
    int i, j;
    do
    {
        printf("Digite o indice da linha: ");
        scanf("%d",&i);
    }
    while((i < 0)||(i > n-1));
    do
    {
        printf("Digite o indice da coluna: ");
        scanf("%d",&j);
    }
    while((j < 0)||(j > n-1));

    /*Numeros da linha de cima*/
    if(i > 0)
    {
        if(m[i-1][j-1] < 9) m[i-1][j-1] += 1;
        if(m[i-1][j] < 9) m[i-1][j] += 1;
        if(m[i-1][j+1] < 9) m[i-1][j+1] += 1;
    }

    /*Numeros da linha de baixo*/

    if(i < n-1)
    {
        if(m[i+1][j-1] < 9) m[i+1][j-1] += 1;
        if(m[i+1][j] < 9) m[i+1][j] += 1;
        if(m[i+1][j+1] < 9) m[i+1][j+1] += 1;
    }

    /*Numeros da esquerda e da direita*/

    if(j > 0)
    {
        if(m[i][j-1] < 9) m[i][j-1] += 1;
    }
    if(j < n-1)
    {
        if(m[i][j+1] < 9) m[i][j+1] += 1;
    }

    /*A posicao escolhida*/
    m[i][j] = 9;
}

void imprime_matriz(int m[][100],int n)
{
    int i, j;

    /*Estrutura exterior da matriz*/
    printf("MAT| ");
    for(i = 0; i < n; i++)
    {
        printf("%2d ",i);
    }
    printf("\n");
    for(i = 0; i < (n * 3) + 4; i++)
    {
        if(i == 3) printf("|");
        else printf("-");
    }
    printf("\n");


    for(i = 0; i < n; i++)
    {
        printf("%2d |",i);/*Parte da estrutura exterior da matriz*/
        for(j = 0; j < n; j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}
