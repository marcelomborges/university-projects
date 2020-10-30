/*
Programa: Laboratorio 07 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 20/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *p, i = 4;

    p = &i;

    printf("i = %d \n",i);
    printf("&i = %x \n",&i);
    printf("p = %p \n",p);
    printf("&p = %X \n",&p);

    return 0;
}
