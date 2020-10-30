/*
Programa: Trabalho de PP Problema 18 (P18)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 18/04/2016
Descricao: Recebe os valores da ordem de uma matriz e imprimi os valores crescentes de 1 em 1 ate a ultima posicao da mesma
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i,j,k = 1, lin, col;
    int mat[SIZE][SIZE];

    /*-----------------------*/

    printf("Bem vindo! Recebo os valores da ordem de uma matriz.");
    printf("Depois imprimo os valores crescentes de 1 em 1 na forma de zigzag pela matriz.");

    do
    {
        printf("\n\nEscreva numero de linhas:\n");
        scanf("%d",&lin);
        printf("Escreva o numero de colunas:\n");
        scanf("%d",&col);

        printf("\n");
        printf("Matriz:\n");

        for(i = 0 ; i < lin ; i++)
        {
            if(i%2 == 0)
            {
                for(j = 0; j < col; j++)
                {
                    mat[i][j] += k;
                    k++;
                }
            }
            else if (i%2 != 0)
            {
                for(j = col-1; j >= 0 ; j--)
                {
                    mat[i][j] += k;
                    k++;
                }
            }
        }

        for(i = 0 ; i < lin ; i++)
        {
            for(j = 0; j < col ; j++)
            {
                printf("\t%3d",mat[i][j]);
            }
            printf("\n");
        }

        for(i = 0 ; i < lin ; i++)
        {
            for(j = 0; j < col ; j++)
            {
                mat[i][j] = 0;
            }
        }
        k = 1;
    }
    while((lin != 0) && (col != 0));
    return 0;
}
