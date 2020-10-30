/*
Programa: Trabalho de PP Problema 5 (P5)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 15/04/2016
Descricao: Classifica os numeros de 1 a 200 em perfeitos, abundantes e reduzidos
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i,j,soma;

    /*-----------------------*/

    printf("Bem vindo! Classifico os numeros de 1 a 200 em perfeitos, abundantes e reduzidos.\n");
    printf("Apos isso imprimo-os em uma tabela.\n\n");

    printf("Tabela (de 1 ate 200):\n\n");

    for(i = 1; i <= 200; i++)
    {
        soma = 0;
        for(j = 1; j < i; j++)
        {
            if((i % j) == 0)
            {
                soma += j;
            }
        }
        if (i == soma)
        {
            printf("O numero %d eh: Perfeito\n",i);
        }
        else if (i < soma)
        {
            printf("O numero %d eh: Reduzido\n",i);
        }
        else
        {
            printf("O numero %d eh: Abundante\n",i);
        }
    }
    return 0;
}
