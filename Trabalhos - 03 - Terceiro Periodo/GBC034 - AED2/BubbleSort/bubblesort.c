#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

void bubblesort (int *vetor, int n)
{
    int i, iteracao, aux;

    for(iteracao = 0; iteracao < n-1; iteracao++)
    {
        for(i = 0; i < n-1; i++)
        {
            if(vetor[i] > vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}

void bubblesort_2 (int *vetor, int n)
{
    int i, iteracao, aux, troca;

    for(iteracao = n-1; iteracao > 0; iteracao--)
    {
        troca = 0;

        for(i = 0; i < iteracao; i++)
        {
            if(vetor[i] > vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                troca = 1;
            }
        }

        if(troca == 0)
        {
            break;
        }
    }
}

void bubblesort_3 (int *vetor, int n)
{
    int i, iteracao, aux, troca;

    for(iteracao = 0; iteracao < n-1; iteracao++)
    {
        troca = 0;

        for(i = 0; i < ((n-1)-iteracao); i++)
        {
            if(vetor[i] > vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                troca = 1;
            }
        }

        if(troca == 0)
        {
            break;
        }
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
