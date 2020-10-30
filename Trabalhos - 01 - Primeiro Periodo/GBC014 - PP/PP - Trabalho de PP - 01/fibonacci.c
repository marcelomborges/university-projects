/*
Programa: Trabalho de PP Problema 4 (P4)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 14/04/2016
Descrição: Le a posicao desejada de um numero da sequencia de Fibonacci (Fn) e imprime o numero dessa posicao
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i,fn;
    double n = 0, n1 = 1, n2 = 0;

    /*-----------------------*/

    printf("Bem vindo! Recebo o valor da posicao de um numero na sequencia de Fibonacci e informo qual numero esta nessa posicao.\n");
    printf("Lembre-se: A contagem comeca com o numero 0 na posicao 0.\n\n");

    do
    {
        printf("Digite a posicao do numero desejado da sequencia de Fibonacci:\n");
        scanf("%d",&fn);
    }
    while(fn < 0);

    for(i = 0; i < fn; i++)
    {
        n = n1 + n2;
        n1 = n2;
        n2 = n;
    }

    printf("\nO numero da posicao %d da sequencia de Fibonacci eh: %.0lf\n",fn,n);

    return 0;
}
