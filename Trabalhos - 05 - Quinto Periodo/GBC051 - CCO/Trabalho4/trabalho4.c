/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho4.h"

/*Implementacao das Funcoes-------------------------*/
double f(double x)
{
    double resultado;

    resultado = x * pow(M_E,x);

    return resultado;
}

double trapezio(int inicio_intervalo, int fim_intervalo, int n)
{
    int i;
    double x, h, resultado_parcial, resultado_final;

    x = (double) inicio_intervalo;
    h = ( ((double)(fim_intervalo - inicio_intervalo)) / n);
    resultado_parcial = 0;
    resultado_final = 0;

    for(i = 0; i <= n; i++)
    {
        if((i == 0)||(i == n))
        {
            resultado_parcial =  resultado_parcial + f(x);
            x = x + h;
        }
        else
        {
            resultado_parcial =  resultado_parcial + (2*f(x));
            x = x + h;
        }
    }

    resultado_final = (h/2) * resultado_parcial;

    return resultado_final;
}

double um_terco_Simpson(int inicio_intervalo, int fim_intervalo, int n)
{
    int i, flag;
    double x, h, resultado_parcial, resultado_final;

    x = (double) inicio_intervalo;
    h = ( ((double)(fim_intervalo - inicio_intervalo)) / (2*n));
    flag = 0;
    resultado_parcial = 0;
    resultado_final = 0;

    for(i = 0; i <= (2*n); i++)
    {
        if((i == 0)||(i == (2*n)))
        {
            resultado_parcial =  resultado_parcial + f(x);
            x = x + h;
        }
        else if(flag == 0)
        {
            resultado_parcial =  resultado_parcial + (4*f(x));
            x = x + h;
            flag = 1;
        }
        else if(flag == 1)
        {
            resultado_parcial =  resultado_parcial + (2*f(x));
            x = x + h;
            flag = 0;
        }
    }

    resultado_final = (h/3) * resultado_parcial;

    return resultado_final;
}

double tres_oitavos_Simpson(int inicio_intervalo, int fim_intervalo, int n)
{
    int i, flag;
    double x, h, resultado_parcial, resultado_final;

    x = (double) inicio_intervalo;
    h = ( ((double)(fim_intervalo - inicio_intervalo)) / (3*n));
    flag = 0;
    resultado_parcial = 0;
    resultado_final = 0;

    for(i = 0; i <= (3*n); i++)
    {
        if((i == 0)||(i == (3*n)))
        {
            resultado_parcial =  resultado_parcial + f(x);
            x = x + h;
        }
        else if((flag == 0)||(flag == 1))
        {
            resultado_parcial =  resultado_parcial + (3*f(x));
            x = x + h;
            flag = (flag + 1) % 3;
        }
        else if(flag == 2)
        {
            resultado_parcial =  resultado_parcial + (2*f(x));
            x = x + h;
            flag = (flag + 1) % 3;
        }
    }

    resultado_final = ((3*h)/8) * resultado_parcial;

    return resultado_final;
}
/*--------------------------------------------------*/
