/*
Programa: Laboratorio 03 Exercicio 7
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao: Recebe uma string e a codifica (troca sua vogais por numeros especificos)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /* Declaracao de variaveis */

    int i;
    char str[100];

    /*-------------------------*/

    printf("Recebo uma string e troco suas vogais por numeros especificos, \"codificando-a\".\n");
    printf("As trocas serao:\n A = 4\n E = 3\n I = 1\n O = 0\n U = 6\n\n");

    printf("Digite a string que sera codificada:\n");
    gets(str);

    for(i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'a')
        {
            str[i] = '4';
        }
        if(str[i] == 'e')
        {
            str[i] = '3';
        }
        if(str[i] == 'i')
        {
            str[i] = '1';
        }
        if(str[i] == 'o')
        {
            str[i] = '0';
        }
        if(str[i] == 'u')
        {
            str[i] = '6';
        }
    }

    printf("\nA string codificada eh:\n");
    puts(str);

    return 0;
}
