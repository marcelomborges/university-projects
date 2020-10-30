/*
Programa: Laboratorio 07 Exercicio 3
Aluno: Marcelo Mendonca Borges
Data: 20/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x = 5;
    int *p_x = NULL; // Ponteiro de x.
    int **pp_x = NULL; // Ponteiro para ponteiro de x.

    p_x = &x; // Carga inicial dos ponteiros
    pp_x = &p_x;

    printf("x= %d -\t&x = %x\n",x,&x);
    printf("x= %d -\tp_x = %p\n",*p_x,p_x);
    printf("x= %d -\t*p_x = %d\n\n",**pp_x,*p_x);

    printf("x = %d\n",x);
    printf("&x = %p\n",&x);
    printf("p_x = %p\n",p_x);
    printf("&p_x = %p\n",&p_x);
    printf("pp_x = %p\n",pp_x);
    printf("&pp_x = %p\n",&pp_x);
    printf("*p_x = %d\n",*p_x);
    printf("**pp_x = %d\n",**pp_x);

    return 0;
}
