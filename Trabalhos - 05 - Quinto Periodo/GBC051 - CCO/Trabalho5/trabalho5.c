/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho5.h"

/*Implementacao das Funcoes-------------------------*/
double f (double t, double x)
{
    double resultado;

    resultado = ((-3)*t*cos(5*t)) - (2*pow(t,3)) + (pow(t,4));

    return resultado;
}

double f_1_linha (double t, double x)
{
    double resultado;

    resultado = ((-3)*cos(5*t)) + (15*t*sin(5*t)) - (6*pow(t,2)) + (4*pow(t,3));

    return resultado;
}

double f_2_linhas (double t, double x)
{
    double resultado;

    resultado = (30*sin(5*t)) + (75*t*cos(5*t)) - (12*t) + (12*pow(t,2));

    return resultado;
}

double x_n_mais_1 (double t_n, double x_n, double h)
{
    double resultado;

    resultado = x_n + (h*f(t_n,x_n)) + ((pow(h,2)/2)*f_1_linha(t_n,x_n)) + ((pow(h,3)/6)*f_2_linhas(t_n,x_n));

    return resultado;
}

void Taylor (double h)
{
    int i;
    double t_n, x_n;

    t_n = (double) 0.0;
    x_n = (double) (-2.0);

    printf("Metodo de Taylor de Ordem 3 para h = %lf:\n\n", h);

    printf("|-----------|-----------|\n");
    printf("|    t_n    |    x_n    |\n");
    printf("|-----------|-----------|\n");

    for(i = 0; t_n <= 2.0000000000; i++)
    {
        printf("| %2.8lf|%2.8lf|\n",t_n,x_n);
        x_n = x_n_mais_1(t_n, x_n, h);
        t_n = t_n + h;
    }

    printf("|-----------|-----------|\n\n");
}
/*--------------------------------------------------*/
