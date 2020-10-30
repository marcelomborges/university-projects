/*
Programa: Laboratorio 01 Exercicio 8
Aluno: Marcelo Mendonca Borges
Data: 27/04/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /*Declaracao de Variaveis*/

    int n, unidades, dezenas, centenas, angstron;

    /*-----------------------*/
    printf("Recebo um numero (de 100 ate 999) e avalio se ele eh um numero de Angstron.\n\n");

    do
    {
        printf("Digite o numero que sera avaliado (100 <= n <= 999): ");
        scanf("%d",&n);
    }
    while((n < 100) || (n > 999));

    unidades = (n % 10);
    dezenas = ((n % 100) - unidades) / 10;
    centenas = ((n % 1000) - unidades - dezenas) / 100;

    angstron = pow(unidades,3) + pow(dezenas,3) + pow(centenas,3);

    printf("\nNumero: %d\n",n);
    printf("Unidades: %d\n",unidades);
    printf("Dezenas: %d\n",dezenas);
    printf("Centenas: %d\n",centenas);
    printf("Angstron: %d\n",angstron);

    if(angstron == n)
    {
        printf("\nO numero %d eh um numero Angstron.\n",n);
    }
    else
    {
        printf("\nO numero %d nao eh um numero Angstron.\n",n);
    }

    return 0;
}
