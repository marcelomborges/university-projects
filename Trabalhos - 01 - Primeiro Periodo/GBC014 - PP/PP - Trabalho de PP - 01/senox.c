/*
Programa: Trabalho de PP Problema 11 (P11)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Calculo o seno de um angulo dado (de 0 graus ate 360 graus - Ciclo Trigonometrico)
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i, k = 0, n = 3, m = 3;
    double x, senx, angulo, pi = 3.141592, termo_geral, termo_sup = 1.0, termo_inf = 1.0;

    /*-----------------------*/

    printf("Bem vindo! Calculo o SENO de um angulo fornecido pela expansao da Serie de Taylor.\n");
    printf("Lembrete: Aceito somente angulos de 0 ate 360 graus.\n\n");

    do
    {
        printf("Digite o valor do angulo (em graus) de 0 ate 360:\n");
        scanf("%lf",&angulo);
    }
    while((angulo < 0) || (angulo > 360));

    x = (angulo/180) * pi;
    senx = x;

    printf("\n");

    for (i = 1; i < 10; i++)
    {
        if (k == 0)
        {
            termo_sup = pow(x, n);
            n += 2;

            termo_inf = termo_inf * (m-1) * m;
            m += 2;

            termo_geral = -(termo_sup / termo_inf);

            senx = senx + termo_geral;
            k++;
        }
        else if(k == 1)
        {
            termo_sup = pow(x, n);
            n += 2;

            termo_inf = termo_inf * (m-1) * m;
            m += 2;

            termo_geral = termo_sup / termo_inf;

            senx = senx + termo_geral;
            k--;
        }
    }

    printf("O sen de %.03lf graus eh aproximadamente: %.03lf\n",angulo,senx);

    return 0;
}
