/*
Programa: Laboratorio 02 Exercicio 6
Aluno: Marcelo Mendonca Borges
Data: 04/04/2016
Descrição: Recebe 10 valores e conta a quantidade de impares entre os mesmos
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    int n,impares=0,i;

    /*-----------------------*/
    printf("Bem vindo ao contador de numeros impares.\n");
    printf("Digite 10 números inteiros positivo (nao incluindo o 0):\n");
    for(i=0; i<10; i++)
    {
        do
        {
            printf("N%02d: ",i);
            scanf("%d",&n);
        }
        while(n <= 0);
        impares += n&1;
    }
    printf("O quantidade de numeros impares lidos foi de: %d",impares);

    return 0;
}
