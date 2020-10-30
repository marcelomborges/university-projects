/*
Programa: AED2 - Bubble Sort
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

int main()
{
    int vetor[10] = {4,1,7,9,2,9,5,3,8,6}, vetor2[10] = {4,1,7,9,2,9,5,3,8,6}, vetor3[10] = {4,1,7,9,2,9,5,3,8,6};

    bubblesort(vetor, 10);
    bubblesort_2(vetor2, 10);
    bubblesort_3(vetor3, 10);

    printf("Bubble Sort:\n\n");
    imprime_vetor(vetor, 10);
    imprime_vetor(vetor2, 10);
    imprime_vetor(vetor3, 10);

    return 0;
}
