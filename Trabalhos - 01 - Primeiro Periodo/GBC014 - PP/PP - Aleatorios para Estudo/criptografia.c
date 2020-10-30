/*
Programa: Simulado 01 Exercicio
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao: Criptografa mensagem escritas com letras pelo metodo da Cifra de Cesar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /*Declaracao de Variaveis*/

    char str[100], aux;
    int i;

    /*-----------------------*/

    printf("Criptografo mensagens escritas pelo metodo da Cifra de Cesar.\n");
    printf("Obs: Aceito somente letras (sem acentuacao), tudo que for diferente disso sera representado por um asterisco (*).\n\n");
    printf("Digite a frase que sera criptografada:\n");
    gets(str);

    for(i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'a' && str[i] < 'z')
        {
            str[i] += 3;
        }
        else if(str[i] == 'x')
        {
            str[i] = 'a';
        }
        else if(str[i] == 'y')
        {
            str[i] = 'b';
        }
        else if(str[i] == 'z')
        {
            str[i] = 'c';
        }
        else if(str[i] == ' ')
        {
            str[i] = ' ';
        }
        else
        {
            str[i] = '*';
        }
    }

    printf("\nA mensagem criptografada eh:\n");
    puts(str);
    printf("\n");

    system("PAUSE");
    return 0;
}
