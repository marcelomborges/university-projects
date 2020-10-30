/*
Programa: Laboratorio 01 Exercicio 7
Aluno: Marcelo Mendonca Borges
Data: 27/04/2016
*/

#include <stdio.h>
int main (void)
{
    float f = 1000;
    double d = 1000000;
    long double ld = 1000000000;

    printf("Imprimo os valores \"mil\", \"um milhao\" e \"um bilhao\" em formato normal e em notacao cientifica:\n\n");
    printf("%f %e\n",f,f);
    printf("%lf %e\n",d,d);
    printf("%Lf %Le\n",ld,ld);

    return 0;
}
