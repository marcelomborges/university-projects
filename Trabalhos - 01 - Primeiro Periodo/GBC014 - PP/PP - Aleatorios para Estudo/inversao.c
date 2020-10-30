/*
Programa: Simulado 01 Exercicio
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

    char str[100],str2[100],aux;
    int i, j = 0;
    /*-----------------------*/

    printf("Realizo a inversao de uma frase digitada.\n\n");

    printf("Digite a frase que sera invertida:\n");
    gets(str);

    j = strlen(str)-1;

    for(i = 0; i <= j; i++,j--)
    {
            aux = str[i];
            str[i] = str[j];
            str[j] = aux;
    }

    printf("\nA frase invertida eh:\n");
    puts(str);

    printf("\n");

    system("PAUSE");
    return 0;
}
