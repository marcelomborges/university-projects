/*
Programa: Laboratorio 02 Exercicio 2
Aluno: Marcelo Mendonca Borges
Data: 02/04/2016
Descrição: Recebe uma letra e define se ela eh vogal ou consoante
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    char letra;

    /*-----------------------*/
    printf("Seja bem vindo!\n");
    printf("Escreva uma letra do alfabeto, que direi se ela eh vogal ou consoante:\n");
    printf("Letra: ");
    scanf("%c",&letra);

    if ((letra >= 'a') && (letra <= 'z'))
    {
        if ((letra == 'a') || (letra == 'e') || (letra == 'i') || (letra == 'o') || (letra == 'u'))
        {
            printf("A letra -%c- eh uma vogal.",letra);
        }
        else
        {
                printf("A letra -%c- eh uma consoante.",letra);
        }
    }
    else
    {
            printf("Isso nao eh uma letra do alfabeto.");
    }
}

