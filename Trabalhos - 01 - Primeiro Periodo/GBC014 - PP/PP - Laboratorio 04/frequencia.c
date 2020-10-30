/*
Programa: Laboratorio 04 Exercicio 6
Aluno: Marcelo Mendonca Borges
Data: 12/05/2016
Descricao: Calcula a quantidade de vezes que aparecem cada vogal em uma string
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /*Declaracao de Variaveis*/
    int i, j, cont_vog[5] = {0,0,0,0,0};
    char str[100], str_g[100], vogais[5] = {'a','e','i','o','u'};
    /*-----------------------*/
    printf("Leio uma string e contabilizo a quantidade de vezes que aparece cada vogal.\n\n");

    do
    {
        printf("Digite uma frase (ate 100 caracteres):\n");
        gets(str);
    }
    while(strlen(str) > 100);
    printf("\n");

    for(i = 0; i < strlen(str); i++)
    {
        str_g[i] = tolower(str[i]);
    }

    printf("A string que sera avaliada eh:\n");
    puts(str_g);
    printf("\n");

    for(i = 0; i < strlen(str_g); i++)
    {
        if(str_g[i] == 'a')
        {
            cont_vog[0]++;
        }
        if(str_g[i] == 'e')
        {
            cont_vog[1]++;
        }
        if(str_g[i] == 'i')
        {
            cont_vog[2]++;
        }
        if(str_g[i] == 'o')
        {
            cont_vog[3]++;
        }
        if(str_g[i] == 'u')
        {
            cont_vog[4]++;
        }
    }

    printf("Histograma:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%02d ",cont_vog[i]);
        printf("%c ",vogais[i]);
        for(j = 0; j < cont_vog[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
