/*
Programa: Laboratorio 05 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 29/04/2016
Descricao: Calcula o número de combinações entre n elementos distintos agrupados em conjuntos de k elementos por meio de funcoes
*/

#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int fat(int);
int binomial(int,int);
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

int binomial(int n, int p)
{
    int comb;

    comb = fat(n) / (fat(p) * fat(n - p));

    return comb;
}

int main ()
{
    /*Declaracao de Variaveis*/
    int n, k, combinacao;
    /*-----------------------*/

    printf("Calculo a combinacao de n elementos agrupados em conjuntos de k elementos.\n");
    printf("Dados os valores de n e k calculo a combinacao por sua formula.\n");
    printf("Observacoes: (n > 0) ; (k <= n) ; (k > 0)\n\n");

    do
    {
        printf("Digite n: ");
        scanf("%d",&n);
    }
    while(n <= 0);
    do
    {
        printf("Digite k: ");
        scanf("%d",&k);
    }
    while((k <= 0) || (k > n));
    printf("\n");

    combinacao = binomial(n,k);

    printf("A combinacao de %d elementos em tomados %d a %d eh: %d\n",n, k, k, combinacao);

    return 0;
}
