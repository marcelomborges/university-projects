/*
Programa: Laboratorio 02 Exercicio 8
Aluno: Marcelo Mendonca Borges
Data: 04/04/2016
Descrição: Recebe o valor da altura da impressao e imprime uma "escada" de asteriscos de ambos os lados
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    int n,i,j,cont;

    /*-----------------------*/
    do
    {
        printf("Digite o tamanho desejado da altura da impressao (de 1 ate inf): ");
        scanf("%d",&n);
    }
    while (n < 1);

    printf("\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    for(i=1; i<=n; i++)
    {
        for(j = 1; j<=n-i; j++)
        {
            printf(" ");
        }
        for(cont=1; cont<=i; cont++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
