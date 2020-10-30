/*
Programa: Laboratorio 05 Exercicio 3
Aluno: Marcelo Mendonca Borges
Data: 29/04/2016
Descricao: Calcula o fatorial de um numero dado utilizando uma funcao que calcula fatorial
*/

#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int fat(int);
/*---------------------*/

int fat(int n)
{
    int i, fat = 1;
    for(i = 1; i <= n; i++)
    {
        fat = fat * i;
    }
    return fat;
}

int main ()
{
    /*Declaracao de Variaveis*/
    int n, fatorial;
    /*-----------------------*/

    printf("Calculo o fatorial de um numero inteiro e positivo.\n");
    printf("Observacao: Numeros muito grandes podem dar erro no calculo.\n\n");

    do
    {
        printf("Digite um numero para calcular o fatorial: ");
        scanf("%d",&n);
    }
    while (n < 0);

    fatorial = fat(n);

    if(n == 0)
    {
        printf("%d! = 1",n);
    }
    else
    {
        printf("%d! = %d",n,fatorial);
    }

    return 0;
}
