/*
Programa: Laboratorio 07 Exercicio 2
Aluno: Marcelo Mendonca Borges
Data: 20/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, *p, *q;

    i = 9;
    p = &i; // p aponta para i.
    q = p; // q também aponta para i.

    printf("i = %d \n",i); // valor de i
    printf("&i = %X\n", &i);// end de i
    printf("p = %p \n", p); // end apontado
    printf("q = %p \n", q); // end apontado
    printf("p = %d\n", *p); // conteudo do end apontado por p.

    return 0;
}
