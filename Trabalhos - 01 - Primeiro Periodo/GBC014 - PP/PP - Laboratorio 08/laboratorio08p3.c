/*
Programa: Laboratorio 08 Exercicio 3
Aluno: Marcelo Mendonca Borges
Data: 28/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*
Resposta
P3)26 12
*/

int confusao(int x, int y)
{
    x = 2*x + y;
    return x;
}
int main(void)
{
    int x = 2, y = 5;
    y = confusao(y, x);
    x = confusao(y, x);
    printf("%d %d\n", x, y);
    return 0;
}
