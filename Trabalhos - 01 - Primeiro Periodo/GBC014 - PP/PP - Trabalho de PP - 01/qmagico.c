/*
Programa: Trabalho de PP Problema 19 (P19)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 18/04/2016
Descricao: Recebe uma matriz de ordem 4x4
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int mat[4][4], i, j, lin[4], col[4], somp = 0, soms = 0, contador[16];
    int var = 0;

    /*-----------------------*/

    printf("Bem vindo! Recebo os valores de uma matriz e avalio se ela eh magica.\n");
    printf("Agora digite os valores de cada posicao na matriz.\n");

    for(i = 0; i < 4; i++)
    {
        printf("\nLinha:%d\n",i+1);

        for(j = 0; j < 4; j++)
        {
            printf("Escreva os Elementos: mat[%d][%d]:", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n\t\t Matriz\n");

    for(i=0; i < 4; i++)
    {
        for(j=0; j < 4; j++)
        {
            printf("\t%d ",mat[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 4; i++)
    {
        lin[i]=0;
        for(j = 0; j < 4; j++)
        {
            lin[i] +=  mat[i][j];
        }
    }
    for(j = 0; j < 4; j++)
    {
        col[j]=0;
        for(i = 0; i < 4; i++)
        {
            col[j] +=  mat[i][j];
        }
    }
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if( i == j)
                somp += mat[i][j];

            if(j == 3-i)
                soms += mat[i][j];
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(lin[i]==col[j]&& somp == soms )
            {
                var++;
            }
            else
            {
                (var=0);
            }
        }
    }

    if(var > 0)
    {
        printf("\n\tA matriz eh magica!\n");
    }
    else
    {
        printf("\n\tA matriz nao eh magica!\n");
    }
    return 0;
}
