/*
Programa: Trabalho 2 - Exercicio 11
Alunos: Adriano Araujo Martins de Resende 11611BCC015
        Marcelo Mendonca Borges           11611BCC020
Descricao: Implementacao de Metodo de Newton para Sistemas de Equacoes Nao Lineares
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho2.h"
/*-----------------------*/

int main()
{
    float x, y, z;

    printf("Metodo de Newton, com erro relativo menor que 0.00001, para o seguinte sistema:\n");
    printf(" f(x,y,z) = (15*x) + (y*y) - (4*z) - 13\n");
    printf(" g(x,y,z) = (x*x) + (10*y) - z - 11\n");
    printf(" h(x,y,z) = (y*y) - (25*z) + 22\n\n");

    printf("Digite o valor inicial de x: ");
    scanf("%f",&x);
    printf("Digite o valor inicial de y: ");
    scanf("%f",&y);
    printf("Digite o valor inicial de z: ");
    scanf("%f",&z);
    printf("\n");

    Newton(x,y,z);

    return 0;
}
