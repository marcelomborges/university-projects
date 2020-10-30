/*
Programa: AED2 - Selection Sort
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.h"

int main()
{
    int vetor[10] = {4,1,7,9,2,9,5,3,8,6}, vetor2[10] = {4,1,7,9,2,9,5,3,8,6};

    selectionsort(vetor, 10);
    selectionsort_2(vetor2,10);

    printf("Selection Sort:\n\n");
    imprime_vetor(vetor, 10);
    imprime_vetor(vetor2, 10);

    return 0;
}
