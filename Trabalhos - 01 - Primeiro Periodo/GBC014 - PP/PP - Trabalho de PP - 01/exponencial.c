/*
Programa: Trabalho de PP Problema 10 (P10)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Calculo o Número de Euler(e) ,elevado a um expoente dado, pela Serie de Taylor
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int x, n = 1, m = 1;
    double e = 1.0,termo_geral, termo_sup = 0.0, termo_inf = 1.0;

    /*-----------------------*/

    printf("Bem vindo! Calculo o numero de Euler ou numero de Neper elevado a um expoente fornecido.\n\n");

    printf("Digite o expoente: ");
    scanf("%d",&x);

    printf("\n");

    do
    {
        termo_sup = pow(x,n);
        n++;
        termo_inf = termo_inf * m;
        m++;

        termo_geral = termo_sup/termo_inf;

        e += termo_geral;
    }
    while(termo_geral >= 0.0000001);

    printf("O numero de Euler ou Neper elevado ao expoente %d eh: %lf\n",x,e);

    return 0;
}
