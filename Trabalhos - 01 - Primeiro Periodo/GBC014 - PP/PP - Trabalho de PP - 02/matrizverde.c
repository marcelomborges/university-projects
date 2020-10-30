/*
Programa: Trabalho de PP 02 - Problema 2 (P2)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 04/05/2016
Descricao: Calcula a media (com precisao de 3 casas) dos elementos que ficam acima das duas diagonais da matriz utilizando funcoes.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
float diag_superior(float mat[100][100]);

/*Declaracao de Variaveis Globais*/
int tam;

int main()
{
    /*Declaracao de Variaveis*/
    int i, j;
    float mat[100][100];
    /*-----------------------*/

    printf("Calculo a media dos \"elementos superiores\" de uma matriz fornecida.\n");
    printf("Esses elementos sao os que ficam acima da diagonal principal e da diagonal secundaria da matriz.\n\n");

    do
    {
        printf("Digite a ordem da matriz da matriz (numero inteiro e positivo): ");
        scanf("%d", &tam);
    }
    while(tam <= 0);

    printf("\n");


    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("Digite o elemento mat[%d][%d]: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
        printf("\n");
    }

    printf("Matriz:\n\n");

    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("%6.2f\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("A media dos \"elementos superiores\" da matriz eh: %3.3f\n",diag_superior(mat));
}

float diag_superior(float mat[100][100])
{
    int i,j;
    float soma = 0, media = 0, v1 = 1, v2 = tam - 1, cont=0;

    for(i=0; i < tam ; i++ )
    {
        for(j = v1; j < v2 ; j++)
        {
            soma = soma + mat[i][j];
            cont++;
        }
        v1++;
        v2--;
    }

    media = soma / cont;

    return media;
}
