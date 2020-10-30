/*
Programa: Trabalho de PP Problema 8 (P8)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Recebe um valor de entrada para a altura da "piramide numerica" e a imprime
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int h,i,j,k,l,num1;

    /*-----------------------*/

    printf("Bem vindo! Recebo um valor de altura e imprimo uma \"piramide numerica\" da altura fornecida.\n\n");

    do
    {
        printf("Digite qual a altura desejada da piramide (ate 100): ");
        scanf("%d",&h);
    }
    while((h <= 0) || (h > 100));


    for(i = 1; i <= h; i++)
    {
        for(j = 0; j < h - i; j++)
        {
            printf("   ");
        }

        num1 = 1;

        for(k = 1; k <= i; k++)
        {
            printf(" %d",num1);
            if(num1 < 10)
            {
                printf(" ");
            }
            num1++;
        }

        num1--;

        for(l = i + 1; l < (i * 2); l++)
        {
            num1--;
            printf(" %d",num1);
            if(num1 < 10)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
