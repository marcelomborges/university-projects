/*
Programa: AED2 - Merge Sort
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int main()
{
    int vetor[10] = {4,1,7,9,2,9,5,3,8,6}, vetor2[7] = {3,2,6,1,4,6,5};

    mergesort(vetor, 0, 9);
    mergesort(vetor2, 0, 6);

    printf("Merge Sort:\n\n");
    imprime_vetor(vetor, 10);
    imprime_vetor(vetor2, 7);

    return 0;
}
