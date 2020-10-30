/*
Programa: Revisao para prova 02
Aluno: Marcelo Mendonca Borges
Data: 29/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int fatorial(int);

int main ()
{
    /*Declaracao de Variaveis*/
    int num, fat_num;
    /*-----------------------*/

    printf("Calculo o fatorial de um numero utilizando funcao recursiva.\n\n");
    do
    {
        printf("Digite um numero: ");
        scanf("%d",&num);
    }
    while(num < 0);

    fat_num = fatorial(num);

    printf("\n%d! = %d\n",num,fat_num);

    return 0;
}

int fatorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return n;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}
