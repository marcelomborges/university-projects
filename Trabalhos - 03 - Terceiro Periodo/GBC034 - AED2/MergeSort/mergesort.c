#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void mergesort(int *vetor, int inicio, int fim)
{
    int meio;

    if(inicio < fim)
    {
        meio = floor((inicio+fim)/2);

        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio+1, fim);

        intercala(vetor, inicio, meio, fim);
    }
}

void intercala(int *vetor, int inicio, int meio, int fim)
{
    int parte1, parte2, fim1, fim2, tamanho, *vetor_aux;
    int i, j, k;

    parte1 = inicio;
    parte2 = meio+1;
    fim1 = 0;
    fim2 = 0;
    tamanho = (fim-inicio) + 1;

    vetor_aux = (int*) malloc(tamanho*sizeof(int));
    if(vetor_aux == NULL)
    {
        printf("-> Erro na alocacao do vetor.\n");
        exit(1);
    }

    for(i = 0; i < tamanho; i++)
    {
        if((fim1 == 0)&&(fim2 == 0))
        {
            if(vetor[parte1] < vetor[parte2])
            {
                vetor_aux[i] = vetor[parte1];
                parte1++;
            }
            else
            {
                vetor_aux[i] = vetor[parte2];
                parte2++;
            }

            if(parte1 > meio) fim1 = 1;
            if(parte2 > fim) fim2 = 1;
        }
        else
        {
            if(fim1 != 0)
            {
                vetor_aux[i] = vetor[parte2];
                parte2++;
            }
            else
            {
                vetor_aux[i] = vetor[parte1];
                parte1++;
            }
        }
    }

    for(j = 0, k = inicio; j < tamanho; j++, k++)
    {
        vetor[k] = vetor_aux[j];
    }

    if(vetor_aux != NULL)
    {
        free(vetor_aux);
    }
}

void imprime_vetor(int *vetor, int n)
{
    int i;

    printf("Vetor:\n");
    for(i = 0; i < n; i++)
    {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    printf("\n");
}
