/*
Programa: AED2 - Insertion Sort
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

int main()
{
    int vetor[10] = {4,1,7,9,2,9,5,3,8,6};

    insertionsort(vetor, 10);

    printf("Insertion Sort:\n\n");
    imprime_vetor(vetor, 10);

    return 0;
}
