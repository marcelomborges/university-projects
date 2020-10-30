/*
Programa: Trabalho de PP Problema 13 (P13)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Calcula o valor aproximado da constante "pi"
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i = 1,k = 0;
    double pi, pi_4 = 1, termo_geral, termo_sup, termo_inf;

    /*-----------------------*/

    printf("Bem vindo! Calculo a constante pi por meio de uma aproximacao pela Serie de Gregory-Leibniz.\n");
    printf("Lembre-se que essa eh uma APROXIMACAO.\n\n");

    do
    {
        if(k == 0)
        {
            termo_sup = 1;
            termo_inf = (2 * i) + 1;

            termo_geral = -(termo_sup / termo_inf);

            pi_4 = pi_4 + termo_geral;

            k++;
        }
        else if (k == 1)
        {
            termo_sup = 1;
            termo_inf = (2 * i) + 1;

            termo_geral = termo_sup / termo_inf;

            pi_4 = pi_4 + termo_geral;

            k--;
        }
        i++;
    }
    while(fabs(termo_geral) >= 0.000001);

    pi = pi_4 * 4;

    printf("O valor de \"pi\" eh aproximadamente: %lf",pi);

    return 0;
}
