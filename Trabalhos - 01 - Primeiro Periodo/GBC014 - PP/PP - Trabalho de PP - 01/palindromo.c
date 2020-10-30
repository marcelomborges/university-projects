/*
Programa: Trabalho 01 Exercicio 16
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /*Declaracao de Variaveis*/

    char str[100],str1[100],str2[100];
    int i, j = 0, k, l = 0, aux;
    /*-----------------------*/

    printf("Realizo a inversao de uma frase digitada.\n\n");

    printf("Digite a frase que sera invertida:\n");
    gets(str);

    for(i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }

    for(i = 0; i <= strlen(str); i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i]=='\0'))
        {
            str1[j] = str[i];
            j++;
        }
    }

    k = strlen(str1) - 1;

    for(i = k; i >= 0; i--)
    {
        str2[i] = str1[l];
        l++;
    }
    str2[strlen(str1)] = '\0';

    printf("\nA string com letras minusculas (sem outros caracteres) eh:\n");
    puts(str1);
    printf("A string com letras minusculas (sem outros caracteres) e invertida eh:\n");
    puts(str2);

    if(strcmp(str1,str2) == 0)
    {
        printf("\nA string \"%s\" eh palindroma.\n\n",str);
    }
    else
    {
        printf("\nA string \"%s\" nao eh palindroma.\n\n",str);
    }

    system("PAUSE");
    return 0;
}
