/*
Programa: Trabalho de PP Problema 1 (P1)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 14/04/2016
Descricao: Le o nome de um ES, o numero de anos trabalhados e informa o salario atual
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

#define SIZE 100

int main ()
{
    /*Declaracao de variaveis*/

    char nome[SIZE];
    int anos, cont_anos = 0, i;
    float salario = 90000.00, inflacao = 0.08, bonus = 0.04, salariob;

    /*-----------------------*/

    printf("Bem vindo! Recebo o nome de um Engenheiro de Software, a quantidade de anos trabalhados e calculo seu salario atual.\n");
    printf("O salario atual sera calculado junto com inflacao e bonus (a cada 4 anos) acumulativos.\n\n");

    printf("Escreva o nome do Engenheiro de software:\n");
    gets(nome);

    printf("\n");

    do
    {
        printf("Digite o numero de anos trabalhados:\n");
        scanf("%d",&anos);
    }
    while(anos < 0);

    for(i = 0; i < anos; i++)
    {
        salario = salario + (salario * inflacao);
        cont_anos++;

        if (cont_anos == 4)
        {
            salariob = salario * (anos/4) * bonus;
            cont_anos = 0;
            salario = salario + salariob;
        }
    }

    if (salario <= 150000)
    {
    printf("\n%s trabalha por %d anos. Salario atual: R$ %.2f\n",nome,anos,salario);
    }
    else
    {
        printf("\n%s trabalha por %d anos. Salario atual: R$ 150000.00\n",nome,anos);
    }
    return 0;
}

