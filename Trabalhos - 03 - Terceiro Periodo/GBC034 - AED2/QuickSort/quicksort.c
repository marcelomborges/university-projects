#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

void quicksort(int *vetor, int primeiro, int ultimo)
{
    int aux, pivo, indice_pivo;
    if(primeiro < ultimo)
    {
        int indice_pivo = (rand()%(ultimo-primeiro)) + primeiro;

        pivo = vetor[indice_pivo];
        vetor[indice_pivo] = vetor[ultimo];
        vetor[ultimo] = pivo;

        int i = primeiro - 1;
        int j = ultimo;

        do
        {
            do{i++;} while(vetor[i] < pivo);
            do{j--;} while((vetor[j] > pivo)&&(j > primeiro));
            if(i < j)
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
        while(i < j);

        vetor[ultimo] = vetor[i];
        vetor[i] = pivo;

        quicksort(vetor, primeiro, i-1);
        quicksort(vetor, i+1, ultimo);
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
