#include <stdio.h>
#include <stdlib.h>
#include "bucketsort.h"

void bucketsort(int *vetor, int n, int valor_max)
{
    int i, j, *vetor_aux;

    vetor_aux = (int*) malloc((valor_max+1)*sizeof(int));
    if(vetor_aux == NULL)
    {
        printf("-> Erro na alocacao do vetor.\n");
        exit(1);
    }

    for(i = 0; i < (valor_max + 1); i++)
    {
        vetor_aux[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        vetor_aux[vetor[i]]++;
    }

    j = 0;
    for(i = 0; i < (valor_max + 1); i++)
    {
        while(vetor_aux[i] > 0)
        {
            vetor_aux[i]--;
            vetor[j] = i;
            j++;
        }
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
