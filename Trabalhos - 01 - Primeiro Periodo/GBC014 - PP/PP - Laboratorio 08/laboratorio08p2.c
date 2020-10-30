/*
Programa: Laboratorio 08 Exercicio 2
Aluno: Marcelo Mendonca Borges
Data: 28/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*
Resposta
P2) a)3 3 3 3 3 3
    b)3 3 1 2 3
*/

int f()
{
    static int i = 3;
    while (i > 1)
    {
        int i = 3;
        printf("%d ", i--);
        if (i > 1) break;
    }
    return i--;
}

int main()
{
    int i = 3;
    printf("%d %d %d\n", f(), f(), f());
}
