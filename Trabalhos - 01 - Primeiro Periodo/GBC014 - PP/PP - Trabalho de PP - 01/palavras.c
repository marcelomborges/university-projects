/*
Programa: Trabalho de PP Problema 17 (P17)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Recebe uma string e informa a quantidade de palavras na string
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------*/
int main ()
{
    /*Declaracao de variaveis*/

    char frase[100];
    int i, cont = 0, total_palavras=0;

    /*-----------------------*/

    printf("Bem vindo! Recebo uma frase e informo a quantidade de palavras nela.\n\n");

    printf("Digite uma frase qualquer:\n");
    fgets(frase,100,stdin);

    for(i = 0; frase[i]!='\0' ; i++)
    {
        if(!cont && frase[i]!=' ')
        {
            cont = 1;
            total_palavras++;
        }
        else if(cont && frase[i]==' ')
        {
            cont = 0;
        }
    }

    printf("\nO numero de palavras eh: %d\n",total_palavras);

    return 0;
}
