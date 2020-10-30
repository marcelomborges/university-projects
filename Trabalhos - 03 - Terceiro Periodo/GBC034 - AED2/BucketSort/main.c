/*
Programa: AED2 - Bucket Sort
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include "bucketsort.h"

int main()
{
    int vetor[10] = {5,1,2,3,0,4,4,3,3,0};

    bucketsort(vetor, 10, 5);

    printf("Bucket Sort:\n\n");
    imprime_vetor(vetor, 10);

    return 0;
}
