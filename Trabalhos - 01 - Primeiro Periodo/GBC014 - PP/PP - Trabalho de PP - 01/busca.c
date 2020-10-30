/*
Programa: Trabalho de PP Problema 15 (P15)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 18/04/2016
Descricao: Recebe uma string maior e outra menor e compara as duas para ver quantas vezes a menor aparece na maior
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 999

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i, cont_let = 0, cont_rep = 0, j = 0;
    char maior_str[SIZE], menor_str[SIZE];

    /*-----------------------*/

    printf("Bem vindo! Recebo uma frase (string) maior e outra menor, depois verifico quantas vezes a menor se repete dentro da maior.\n\n");


    printf("Digite a maior string:\n");
    gets(maior_str);
    printf("Digite a menor string:\n");
    gets(menor_str);

    printf("\n");

    for(i = 0; i < strlen(maior_str); i++)
    {
        if(maior_str[i] != menor_str[cont_let])
        {
            cont_let = 0;
        }
        if(maior_str[i] == menor_str[cont_let])
        {
            cont_let++;
            if(cont_let == 1)
            {
                j = i;
            }
        }
        if(cont_let == strlen(menor_str))
        {
            cont_rep++;
            cont_let = 0;
            i = j;
        }
    }

    printf("Resultado:\n");
    if(cont_rep == 1)
    {
        printf("A menor string aparece %d vez dentro da maior string.\n", cont_rep);
    }
    else
    {
        printf("A menor string aparece %d vezes dentro da maior string.\n", cont_rep);
    }

    return 0;
}
