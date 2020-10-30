/*
Programa: Revisao para prova 02
Aluno: Marcelo Mendonca Borges
Data: 29/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Prototipos de Funcoes*/
int fibonacci(int,int,int);

int main ()
{
    /*Declaracao de Variaveis*/
    int quantidade,n1 = 1, n2 = 0;
    /*-----------------------*/

    printf("Digite a quantidade de termos que voce deseja da sequencia de Fibonacci: ");
    scanf("%d",&quantidade);

    fibonacci(n1,n2,quantidade);


    return 0;
}

int fibonacci(int n1, int n2, int quant)
{
    int aux;
    if(quant == 0)
    {
        return 0;
    }

    aux = n1;
    n1 = n2;
    n2 = n1 + aux;
    quant--;

    printf("%d ",n2);

    return fibonacci(n1,n2,quant);
}
