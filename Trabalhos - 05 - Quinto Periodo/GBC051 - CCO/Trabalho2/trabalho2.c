/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho2.h"

/*Implementacao das Funcoes-------------------------*/

/*Funcoes Originais*/
float f(float x, float y, float z)
{
    float retorno;
    retorno = (15*x) + (y*y) - (4*z) - 13;
    return retorno;
}

float g(float x, float y, float z)
{
    float retorno;
    retorno = (x*x) + (10*y) - z - 11;
    return retorno;
}

float h(float x, float y, float z)
{
    float retorno;
    retorno = (y*y) - (25*z) + 22;
    return retorno;
}

/*Derivadas em relacao a x*/
float fx(float x, float y, float z)
{
    return 15.0;
}

float gx(float x, float y, float z)
{
    float retorno;
    retorno = (2*x);
    return retorno;
}

float hx(float x, float y, float z)
{
    return 0.0;
}

/*Derivadas em relacao a y*/
float fy(float x, float y, float z)
{
    float retorno;
    retorno = (2*y);
    return retorno;
}

float gy(float x, float y, float z)
{
    return 10.0;
}

float hy(float x, float y, float z)
{
    float retorno;
    retorno = (2*y);
    return retorno;
}

/*Derivadas em relacao a z*/
float fz(float x, float y, float z)
{
    return (-4.0);
}

float gz(float x, float y, float z)
{
    return (-1.0);
}
float hz(float x, float y, float z)
{
    return (-25.0);
}

/*Funcoes do Metodo*/
float J(float x, float y, float z)
{
    float jacobiano;
    jacobiano = ( ( (fx(x,y,z)*gy(x,y,z)*hz(x,y,z)) + (fy(x,y,z)*gz(x,y,z)*hx(x,y,z)) + (fz(x,y,z)*gx(x,y,z)*hy(x,y,z)) )
              -   ( (fz(x,y,z)*gy(x,y,z)*hx(x,y,z)) + (fx(x,y,z)*gz(x,y,z)*hy(x,y,z)) + (fy(x,y,z)*gx(x,y,z)*hz(x,y,z)) ) );

    return jacobiano;
}

float formula_x(float x, float y, float z)
{
    float retorno;
    retorno = ( ( ( ((-f(x,y,z))*gy(x,y,z)*hz(x,y,z)) + (fy(x,y,z)*gz(x,y,z)*(-h(x,y,z))) + (fz(x,y,z)*(-g(x,y,z))*hy(x,y,z)) )
                - ( (fz(x,y,z)*gy(x,y,z)*(-h(x,y,z))) + ((-f(x,y,z))*gz(x,y,z)*hy(x,y,z)) + (fy(x,y,z)*(-g(x,y,z))*hz(x,y,z)) ) ) / J(x,y,z) );
    return retorno;
}

float formula_y(float x, float y, float z)
{
    float retorno;
    retorno = ( ( ( (fx(x,y,z)*(-g(x,y,z))*hz(x,y,z)) + ((-f(x,y,z))*gz(x,y,z)*hx(x,y,z)) + (fz(x,y,z)*gx(x,y,z)*(-h(x,y,z))) )
                - ( (fz(x,y,z)*(-g(x,y,z))*hx(x,y,z)) + (fx(x,y,z)*gz(x,y,z)*(-h(x,y,z))) + ((-f(x,y,z))*gx(x,y,z)*hz(x,y,z)) ) ) / J(x,y,z) );
    return retorno;
}

float formula_z(float x, float y, float z)
{
    float retorno;
    retorno = ( ( ( (fx(x,y,z)*gy(x,y,z)*(-h(x,y,z))) + (fy(x,y,z)*(-g(x,y,z))*hx(x,y,z)) + ((-f(x,y,z))*gx(x,y,z)*hy(x,y,z)) )
                - ( ((-f(x,y,z))*gy(x,y,z)*hx(x,y,z)) + (fx(x,y,z)*(-g(x,y,z))*hy(x,y,z)) + (fy(x,y,z)*gx(x,y,z)*(-h(x,y,z))) ) ) / J(x,y,z) );
    return retorno;
}

float novo_x(float x, float y, float z)
{
    float retorno;
    retorno = (x - ((-1)*formula_x(x,y,z)));
    return retorno;
}
float novo_y(float x, float y, float z)
{
    float retorno;
    retorno = (y - ((-1)*formula_y(x,y,z)));
    return retorno;
}

float novo_z(float x, float y, float z)
{
    float retorno;
    retorno = (z - ((-1)*formula_z(x,y,z)));
    return retorno;
}

void Newton(float x, float y, float z)
{
    int i;
    float old_x, old_y, old_z, new_x, new_y, new_z;
    float erro_relativo_x = 1.0, erro_relativo_y = 1.0, erro_relativo_z = 1.0;

    old_x = x;
    old_y = y;
    old_z = z;

    printf("|-------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|\n");
    printf("|   k   |   x(k)    |   y(k)    |   z(k)    |  x(k+1)   |  y(k+1)   |  z(k+1)   | err_rel_x | err_rel_y | err_rel_z |\n");
    printf("|-------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|\n");

    for(i = 0; i < 1000; i++)
    {
        new_x = novo_x(old_x,old_y,old_z);
        new_y = novo_y(old_x,old_y,old_z);
        new_z = novo_z(old_x,old_y,old_z);

        erro_relativo_x = ((fabs(new_x-old_x)) / fabs(new_x));
        erro_relativo_y = ((fabs(new_y-old_y)) / fabs(new_y));
        erro_relativo_z = ((fabs(new_z-old_z)) / fabs(new_z));

        printf("| %5d | %3.7f | %3.7f | %3.7f | %3.7f | %3.7f | %3.7f | %3.7f | %3.7f | %3.7f |\n",i,old_x,old_y,old_z,new_x,new_y,new_z,erro_relativo_x,erro_relativo_y,erro_relativo_z);

        if((erro_relativo_x < 0.00001)&&(erro_relativo_y < 0.00001)&&(erro_relativo_z < 0.00001))
        {
            break;
        }

        old_x = new_x;
        old_y = new_y;
        old_z = new_z;
    }

    printf("|-------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|\n");

    if(i < 1000)
    {
        printf("\nResultados:\n");
        printf("x = %f\n", new_x);
        printf("y = %f\n", new_y);
        printf("x = %f\n", new_z);
    }
    else if(i == 1000)
    {
        printf("-> Erro: Metodo nao convergiu para os valores iniciais.\n");
    }
    else
    {
        printf("-> Erro: Falha no programa.\n");
    }

}

/*--------------------------------------------------*/
