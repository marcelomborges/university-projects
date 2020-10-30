/*
Programa: Laboratorio 03 Exercicio 3
Aluno: Marcelo Mendonca Borges
Data: 08/04/2016
Descricao: Le 10 valores inteiros e coloca em um vetor, depois percorre o vetor classificando-os e realocando-os em vetores par e impar
*/

#include <stdio.h>
#include <stdlib.h>

#define n 10
int main ()
{
    /* Declaracao de variaveis */

    int v[n], par[n], imp[n];
    int i, j = 0, k = 0;

    /*-------------------------*/

    printf("Leio 10 valores e classifico-os em pares ou impares (com a utilizacao de vetores).\n\n");

    for(i = 0; i < n; i++)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d",&v[i]);
        if ((v[i] % 2) == 0)
        {
            par[j] = v[i];
            j++;
        }
        else
        {
            imp[k] = v[i];
            k++;
        }
    }

    printf("\nA sequencia original eh:\n");
    for(i = 0; i < 10; ++i)
    {
        printf("%d ",v[i]);
    }
    printf("\n");

    printf("\nOs numero pares da sequencia original sao:\n");
    for(i = 0; i < j; ++i)
    {
        printf("%d ",par[i]);
    }
    printf("\n");

    printf("\nOs numeros impares da sequencia original sao:\n");
    for(i = 0; i < k; ++i)
    {
        printf("%d ",imp[i]);
    }

    printf("\n");

    return 0;
}

