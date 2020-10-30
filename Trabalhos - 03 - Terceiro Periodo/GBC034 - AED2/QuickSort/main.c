/*
Programa: AED2 - Quick Sort
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

int main()
{
    int vetor[10] = {4,1,7,9,2,9,5,3,8,6};

    srand(time(NULL));

    quicksort(vetor, 0, 9);

    printf("Quick Sort:\n\n");
    imprime_vetor(vetor, 10);

    return 0;
}
