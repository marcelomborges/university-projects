/*
Programa: Trabalho de PP 02 - Problema 7 (P7)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 03/05/2016
Descricao: Utiliza funcao recursiva para contar a quantidade de algarismos de um numero inteiro.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int contador(int);

int main ()
{
    /*Declaracao de Variaveis*/
    int m, n, dig;
    /*-----------------------*/

    printf("Recebo um numero inteiro e informo a quantidade de algarismos que ele possui.\n");
    printf("Lembrete: Se o numero for muito grande (com mais de 10 algarismos) pode dar erro.\n\n");

    printf("Digite um numero inteiro: ");
    scanf("%d",&n);
    printf("\n");

    m = n;

    dig = contador(m);

    printf("O numero de digitos decimais do numero %d eh: %d\n",n,dig);

    return 0;
}

int contador(int n)
{
    static int cont = 0;

    if(n < 1)
    {
        return cont;
    }

    n = n/10;
    cont++;

    return contador(n);
}
