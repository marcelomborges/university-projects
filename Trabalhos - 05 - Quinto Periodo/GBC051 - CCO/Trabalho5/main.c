/*
Programa: Trabalho 5 - Exercicio 3
Alunos: Adriano Araujo Martins de Resende 11611BCC015
        Marcelo Mendonca Borges           11611BCC020
Descricao: Implementação de Metodos Numericos para Resolucao de Sistema de Equacoes Diferenciais
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho5.h"
/*-----------------------*/

int main()
{
    printf("Resolucao do seguinte PVI utilizando Metodo de Taylor de Ordem 3:\n");
    printf("x' = (-3)*t*cos(5t) - 2*(t^3) + 4*(t^4)\n");
    printf("x(0) = -2\n");
    printf("0 <= t <= 2\n\n");

    Taylor(0.1);
    Taylor(0.2);
    Taylor(0.4);

    return 0;
}
