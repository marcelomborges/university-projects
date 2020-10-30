/*
Programa: Simulado 02 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /*Declaracao de Variaveis*/

    int r[10], s[10], x[20];
    int i, j, k = 0, presente = 0;

    /*-----------------------*/

    printf("Vetor r:\n");
    for(i = 0; i < 10; i++)
    {
        printf("r[%d]: ",i);
        scanf("%d", &r[i]);
    }

    printf("\nVetor s:\n");
    for(j = 0; j < 10; j++)
    {
        printf("s[%d]: ",j);
        scanf("%d", &s[j]);
    }

    for(i = 0; i < 10; i++)
    {
        presente = 0;
        for(j = 0; j < k; j++)
        {
            if(r[i] == x[i])
            {
                presente = 1;
                break;
            }
            if (!presente)
            {
                x[k] = s[i];
                ++k;
            }
        }
    }

    printf("\nVetor x:\n");
    for(i = 0; i < k; i++)
    {
        printf("x[%d]: %d\n",i,x[i]);
    }
    return 0;
}
