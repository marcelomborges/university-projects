/*
Programa: Laboratorio 03 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao: Recebe o valor dos elementos de um vetor e imprime uma quantidade de asteriscos correnpondente a seu valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /* Declaracao de variaveis */

    int v[5], i, j;

    /*-------------------------*/

    printf("Recebo 5 valores e imprimo eles junto com a quantidade de asteriscos que ele vale.\n");
    printf("Lembre-se que devem ser numeros inteiros positivos.\n\n");

    for(i = 0; i < 5; i++)
    {
        do
        {
            printf("Digite o elemento %d do vetor: ",i + 1);
            scanf("%d",&v[i]);
        }
        while(v[i] < 0);
    }

    printf("\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("%2d",v[i]);
        for(j = 0; j < v[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
