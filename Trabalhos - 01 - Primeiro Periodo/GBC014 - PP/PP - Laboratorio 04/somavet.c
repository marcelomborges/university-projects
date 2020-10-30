/*
Programa: Laboratorio 04 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 15/04/2016
Descricao: Realiza a soma dos valores de cada indice correspondente de dois vetores
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 5

int main ()
{
    /* Declaracao de variaveis */
    int i;
    float A[SIZE],B[SIZE],C[SIZE];
    /*-------------------------*/

    printf("Realizo a soma dos valores de cada indice correspondente de vetores.\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("Digite o valor do elemento A[%d]=",i);
        scanf("%f",&A[i]);
    }
    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("Digite o valor do elemento B[%d]=",i);
        scanf("%f",&B[i]);
    }

    for(i = 0; i < 5; i++)
    {
        C[i] = A[i] + B[i];
    }
    printf("\n");

    printf("Vetores:\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("A[%02d]= %.02f\n",i,A[i]);
    }
    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("B[%02d]= %.02f\n",i,B[i]);
    }
    printf("\n");

    printf("Soma:\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("Vetor da Soma C[%02d]= %.02f\n",i,C[i]);
    }
    return 0;
}
