/*
Programa: Laboratorio 02 Exercicio 8
Aluno: Marcelo Mendonca Borges
Data: 04/04/2016
Descrição: Cria "molduras" de asteriscos a partir da entrada de tamanho do usuario
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    int i,j,m,n;

    /*-----------------------*/
    printf("Bem vindo ao criador de \"molduras de asteriscos\".\n");
    printf("Recebo os valores da altura e da largura da moldura e a crio.\n");

    do
    {
        printf("Digite o numero de asteriscos da largura da moldura:\n");
        scanf("%d",&m);
    }
    while (m <= 0);
    do
    {
        printf("Digite o numero de asteriscos da altura da moldura:\n");
        scanf("%d",&n);
    }
    while (n <= 0);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if(i == 1 || i == n || j == 1 || j == m)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
