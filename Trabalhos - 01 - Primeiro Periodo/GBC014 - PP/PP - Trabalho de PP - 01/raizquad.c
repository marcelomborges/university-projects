/*
Programa: Trabalho de PP Problema 6 (P6)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 15/04/2016
Descricao: Le um numero positivo e retorna sua raiz quadrada
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

    int i;
    double num,raiz=0,atual_x,prox_x;

    /*-----------------------*/
    printf("Bem vindo! Calculo a raiz quadrada de um numero (positivo) fornecido.\n\n");

    do
    {
        printf("Digite o numero ao qual a raiz sera aplicada: ");
        scanf("%lf",&num);
    }
    while(num <= 0);

    atual_x = num/2;

    do
    {
        prox_x = atual_x;
        atual_x = 0.5 * (atual_x + (num/atual_x));
    }
    while(prox_x != atual_x);

    raiz = prox_x;

    printf("A raiz quadrada de %lf eh aproximadamente %lf\n",num,raiz);

    return 0;
}
