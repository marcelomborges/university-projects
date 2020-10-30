/*
Programa: Laboratorio 03 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 08/04/2016
Descricao: Mostra o conteudo de um vetor na ordem direta e na ordem inversa
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    /*Declaracao de Variaveis*/

    int v[10]= {3, 7, 4, 1, 0, 8, 6, 9, 2, 5}, i, j;

    /*-----------------------*/

    printf("Imprimo os elementos de um vetor de tamanho 10 (v[10]) na ordem direta e inversa.\n\n");

    printf("Vetor na ordem direta:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ",v[i]);
    }

    printf("\n\n");

    printf("Vetor na ordem inversa:\n");
    for(j = 9; j >= 0; j--)
    {
        printf("%d ",v[j]);
    }

    printf("\n");

    return 0;
}
