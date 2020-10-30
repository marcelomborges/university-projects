/*Inclusoes de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bissecao.h"

/*Prototipos de Funcoes*/
double funcao1 (double x1);
double funcao2 (double x2);
double funcao3 (double x3);
double funcao4 (double x4);
double funcao5 (double x5);

/*Definicao de Funcoes*/
double funcao1(double x1)
{
    double retorno1;

    retorno1 = (2*pow(x1,2)) - (5*x1)+2;

    return retorno1;
}

double funcao2(double x2)
{
    double retorno2;

    retorno2 = (log(pow(x2,2))) + (log(x2));

    return retorno2;
}

           double funcao3(double x3)
{
    double retorno3;

    retorno3 = (81*pow(x3,4)) - (108*pow(x3,3)) + (24*x3) + 20;

    return retorno3;
}

double funcao4(double x4)
{
    double retorno4;

    retorno4 = pow(M_E,x4) - (3*x4);

    return retorno4;
}

double funcao5(double x5)
{
    double retorno5;

    retorno5 = (pow(x5,3)) + cos(x5);

    return retorno5;
}

void bissecao(int seleciona_funcao)
{
    int controle = 0;
    double minimo = (-1000), maximo = 1000;
    double raiz1;

    while(1)
    {
        if(funcao1(minimo)*funcao1(maximo) < 0)
        {
            while((controle < 50)&&(funcao1((minimo+maximo)/2) != 0))
            {
                if((funcao1((minimo+maximo)/2)) < 0)
                {
                    minimo = ((minimo+maximo)/2);
                }
                else
                {
                    maximo = ((minimo+maximo)/2);
                }
                controle++;
                printf("AQUI\n");
            }
            controle = 0;
            raiz1 = ((minimo+maximo)/2);
            printf("Raiz da primeira funcao: %lf", raiz1);
            return;
        }
        else
        {
            minimo += 1;
            maximo -= 1;
        }
        printf("Minimo: %lf\n", minimo);
        printf("Maximo: %lf\n", maximo);
    }
}
