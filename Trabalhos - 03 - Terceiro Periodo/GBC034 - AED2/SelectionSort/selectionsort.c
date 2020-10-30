#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.h"

void selectionsort(int *vetor, int n)
{
    int i, iteracao, aux, menor, indice_menor;

    for(iteracao = 0; iteracao < n-1; iteracao++)
    {
        menor = vetor[iteracao];
        indice_menor = iteracao;
        for(i = iteracao+1; i < n; i++)
        {
            if(vetor[i] < menor)
            {
                indice_menor = i;
                menor = vetor[i];
            }
        }

        if(indice_menor != iteracao)
        {
            aux = vetor[iteracao];
            vetor[iteracao] = menor;
            vetor[indice_menor] = aux;
        }
    }
}

void selectionsort_2(int *vetor, int n)
{
    int i, iteracao, aux, menor;

    for(iteracao = 0; iteracao < n-1; iteracao++)
    {
        menor = iteracao;
        for(i = iteracao+1; i < n; i++)
        {
            if(vetor[i] < vetor[menor])
            {
                menor = i;
            }
        }

        if(menor != iteracao)
        {
            aux = vetor[iteracao];
            vetor[iteracao] = vetor[menor];
            vetor[menor] = aux;
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
