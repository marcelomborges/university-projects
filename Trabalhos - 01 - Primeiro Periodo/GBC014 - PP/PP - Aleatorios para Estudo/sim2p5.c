/*
Programa: Simulado 02 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao: Recebe os elementos de um vetor de tamanho 10 e os coloca em ordem crescente dentro do proprio vetor
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /*Declaracao de Variaveis*/

    int x[10];
    int i, j, aux;

    /*-----------------------*/
    printf("Recebo 10 valores de elementos de um vetor e coloco-os em ordem crescente.\n\n");


    printf("Vetor x:\n");
    for(i = 0; i < 10; i++)
    {
        printf("x[%d]: ",i);
        scanf("%d",&x[i]);
    }

    for(i = 0; i < 9; i++)
    {
        for(j = i+1; j < 10; j++)
        {
            if(x[i] > x[j])
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }

    printf("\nVetor x ordenado:\n");
    for(i = 0; i < 10; i++)
    {
        printf("x[%d]: %d\n",i,x[i]);
    }
    return 0;
}
