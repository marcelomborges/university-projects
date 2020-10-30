/*
Programa: Laboratorio 04 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 12/05/2016
Descricao: Le uma matriz e verifica se ela eh simetrica
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /*Declaracao de Variaveis*/
    int i, j, n, a[100][100], transp = 1;
    /*-----------------------*/
    printf("Leio uma matriz e verifico se lea eh ou nao simetrica.\n");
    printf("Observacao: Uma matriz eh simetrica quando ela eh igual a sua transposta.\n\n");

    do
    {
        printf("Defina a ordem da matriz M(n x n) = ");
        scanf("%d",&n);
    }
    while(n <= 0);

    printf("\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Digite o valor do elemento M[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }

    printf("Matriz:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                transp = 0;
            }
        }
    }

    if(transp)
    {
        printf("\nA matriz eh transposta.\n");
    }
    else
    {
        printf("\n A matriz nao eh transposta.\n");
    }

    return 0;
}
