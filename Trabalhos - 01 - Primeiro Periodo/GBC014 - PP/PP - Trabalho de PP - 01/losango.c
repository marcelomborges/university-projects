/*
Programa: Trabalho de PP Problema 9 (P9)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Recebe um valor de entrada para a altura de um losango de asteriscos e o imprime
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int h,i,j,k,l,esp1,esp2,cont = 0;

    /*-----------------------*/

    printf("Bem vindo! Recebo um valor de altura e imprimo um \"losango de asteriscos\" da altura fornecida.\n\n");

    do
    {
        printf("Digite qual a altura desejada para o losango: ");
        scanf("%d",&h);
    }
    while(h <= 0);

    printf("\n");

    /*Parte Superior do Losango*/
    for(i = 1; i <= h; i++)
    {
        for(j = 0; j < h - i; j++)
        {
            printf(" ");
        }
        if(i == 1)
        {
            printf("*");
        }
        else
        {
            printf("*");
            for(esp1 = 1; esp1 < cont; esp1++)
            {
                printf(" ");
            }
            printf("*");
        }
        cont += 2;
        printf("\n");
    }

    cont-=4;

    /*Parte Inferio do Losango*/
    for(k = 1; k < h; k++)
    {
        for(l = 0; l < k; l++)
        {
            printf(" ");
        }
        if(l == (h-1))
        {
            printf("*");
        }
        else
        {
            printf("*");
            for(esp2 = 1; esp2 < cont; esp2++)
            {
                printf(" ");
            }
            printf("*");
        }
        cont-=2;
        printf("\n");
    }

    return 0;
}
