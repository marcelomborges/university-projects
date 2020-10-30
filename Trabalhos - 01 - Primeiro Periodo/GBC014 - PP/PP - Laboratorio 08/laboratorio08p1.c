/*
Programa: Laboratorio 08 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 28/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*
Resposta
P1)9 11
*/

int f(int x)
{
    return x + 2;
}

int main(void)
{
    int x = 5;
    printf("%d %d\n", f(x+2), f(f(x+2)));
    return 0;
}
