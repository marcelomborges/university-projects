#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

void insertionsort(int *vetor, int n)
{
    int i, iteracao, aux, elem;

    for(iteracao = 1; iteracao < n; iteracao++)
    {
        elem = vetor[iteracao];
        i = iteracao-1;

        while((i >= 0)&&(vetor[i] > elem))
        {
            vetor[i+1] = vetor[i];
            i--;
        }

        vetor[i+1] = elem;
    }
}

void imprime_vetor (int *vetor, int n)
{
    int i;

    printf("Vetor:\n");
    for(i = 0; i < n; i++)
    {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    printf("\n");
}
