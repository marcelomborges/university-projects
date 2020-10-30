/*
Programa: Trabalho de PP 02 - Problema 6 (P6)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 03/05/2016
Descricao: Inverte uma string por meio de uma função recursiva.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Prototipos de Funcoes*/
char inversao(char[],int);

int main ()
{
    /*Declaracao de variaveis*/
    char string[100];
    int tamanho;
    /*-----------------------*/

    printf("Realizo a inversao de uma string fornecida por meio de funcao recursiva.\n\n");

    printf("Digite a string que sera invertida:\n");
    gets(string);

    tamanho = strlen(string)-1;

    printf("\nString invertida:\n");
    inversao(string,tamanho);
    printf("\n");

    return 0;
}

char inversao(char string[], int n)
{
    if(n < 0)
    {
        return 'A';
    }
    putchar(string[n]);
    return inversao(string,--n);
}
