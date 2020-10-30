/*
Programa: Laboratorio 05 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 29/04/2016
Descricao: Calcula o valor de uma expressao utilizando uma funcao de potencia
*/

#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
float pot(float,int);
/*---------------------*/

float pot(float num, int exp)
{
    int i;

    float pot = 1;
    for(i = 0; i < exp; i++)
    {
        pot = pot * num;
    }
    return pot;
}

int main ()
{
    /*Declaracao de Variaveis*/
    float x, y, resp;
    int a, b;
    /*-----------------------*/

    printf("Dados os valores de x, y, a e b, calculo o resultado da expressao \"(x^a) * (y^b) * ((x-y)^(a+b))\".\n");
    printf("Observacao: Os valores dos expoentes (a,b) nao podem ser negativos.\n\n");

    printf("Digite o numero x: ");
    scanf("%f",&x);
    printf("Digite o numero y: ");
    scanf("%f",&y);
    printf("\n");

    do
    {
        printf("Digite o expoente a: ");
        scanf("%d",&a);
    }
    while(a < 0);
    do
    {
        printf("Digite o expoente b: ");
        scanf("%d",&b);
    }
    while(b < 0);
    printf("\n");

    resp = pot(x,a) + pot(y,b) + pot((x-y),(a+b));

    printf("Expressao: (%.2f^%d) + (%.2f^%d) + (%.2f^%d)\n",x, a, y, b, x - y, a + b);
    printf("O resultado da expressao eh: %.2f\n",resp);

    return 0;
}

