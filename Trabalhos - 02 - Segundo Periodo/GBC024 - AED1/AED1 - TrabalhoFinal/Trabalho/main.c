/*
Programa: Trabalho de AED1
Alunos: Marcelo Mendonca Borges
Data: 26/11/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "trabalho.h"

int main()
{
    /*Declaracao de variaveis*/
    int **labirinto;
    int i, j, n;
    POSICAO *posicao_inicial;
    /*-----------------------*/

    printf("Construo e resolvo um labirinto usando backtracking com pilhas.\n");
    printf("Observacao a dimensao do labirinto deve ser maior do que 4.\n\n");

    do
    {
        printf("Digite a dimensao (n) do labirinto (n * n): ");
        scanf("%d", &n);
        printf("\n");
    }
    while(n < 5);

    /*Alocando a matriz dinamicamente*/
    labirinto = (int**) malloc(n * sizeof(int*));
    if(labirinto == NULL)
    {
        printf("--> Erro na alocacao da matriz.");
        return 1;
    }
    for(i = 0; i < n; i++)
    {
        labirinto[i] = (int*) malloc(n * sizeof(int));
        if(labirinto[i] == NULL)
        {
            printf("--> Erro na alocacao do vetor.");
            return 1;
        }
    }

    /*Iniciando os valores na matriz*/
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            labirinto[i][j] = 9;
        }
    }

    /*Alocando a posicao*/
    posicao_inicial = (POSICAO*) malloc(sizeof(POSICAO));
    if(posicao_inicial == NULL)
    {
        printf("--> Erro na alocacao da posicao.\n");
        return 1;
    }

    /*Criando o labirinto na matriz*/
    *posicao_inicial = desenvolve_labirinto(labirinto, n);
    imprime_labirinto(labirinto, n, n);

    /*Resolvendo o labirinto*/
    resolve_labirinto(labirinto, n, posicao_inicial);

    /*Liberando a matriz alocada dinamicamente*/
    for(i = 0; i < n; i++)
    {
        free(labirinto[i]);
    }
    free(labirinto);

    return 0;
}
