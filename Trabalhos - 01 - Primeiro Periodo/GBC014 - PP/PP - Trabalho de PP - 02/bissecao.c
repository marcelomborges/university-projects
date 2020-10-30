/*
Programa: Trabalho de PP 02 -  Problema 12 (P12)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 06/05/2016
Descricao: Calcula as raizes de uma funcao polinomial utilizando o metodo da bissecao
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Declaracao de Variaveis Globais*/
int grau;
double coef[100];

/*Prototipos de Funcoes*/
double fx(double);
double bissecao(double, double);
void get_raizes(int,int);


int main()
{
    /*Declaracao de Variaveis*/
    int i, mv1, mv2;

    printf("Calculo as raizes de uma funcao, dados os coeficientes e o grau do polinomio.\n\n");

    do
    {
        printf("Digite o grau do polinomio (numero > 0): ");
        scanf("%d",&grau);
    }
    while(grau <= 0);
    printf("\n");

    for(i = 0; i <= grau; i++)
    {
        printf("Digite o coeficiente que acompanha o termo \"x^%d\": ",i);
        scanf("%lf",&coef[i]);
    }
    printf("\n");


    printf("Funcao polinomial:\n");
    printf("f(x) = ");
    for(i = 0; i <= grau; i++)
    {
        if(i == 0)
        {
            printf("%.2lf + ",coef[i]);
        }
        else if(i == grau)
        {
            printf("(%.2lf*(x^%i))",coef[i],i);
        }
        else
        {
            printf("(%.2lf*x^%i) + ",coef[i],i);
        }
    }
    printf("\n");

    do
    {
        printf("\nDigite o intervalo que sera analisado (dois numeros distintos):\n");
        printf("Digite o menor valor: ");
        scanf("%d",&mv1);
        printf("Digite o maior valor: ");
        scanf("%d",&mv2);
    }
    while(mv1 >= mv2);

    printf("\nIntervalo = [%d;%d]\n",mv1,mv2);

    get_raizes(mv1,mv2);

    return 0;
}

double fx(double n)
{
    int i;
    double funcao_x = 0;

    for(i = 0; i <= grau; i++)
    {
        funcao_x += (coef[i] * pow(n,i));
    }
    return funcao_x;
}

double bissecao(double x1, double x2)
{
    double meio;

    meio = (x1 + x2)/2;

    //printf("intervalo atual: (%.2lf,%.2lf)\n", x1, x2);
    if(fx(meio) >= -0.00000001 && fx(meio) <= 0.00000001)
    {
        return meio;
    }
    else if (fx(meio) < 0)
    {
        x1 = meio;
        return bissecao(x1, x2);
    }
    else
    {
        x2 = meio;
        return bissecao(x1,x2);
    }
}

void get_raizes(int a1, int a2)
{
    int i, j;
    double raiz = 0;
    int achou = 0;

    for(i = a1; i <= a2; i++)
    {
        if((fx(i) <= 0) && (fx(i+1) >= 0))
        {
            raiz = bissecao(i,i+1);
            achou = 1;
        }
    }

    if(!achou)
    {
        printf("\nNao tem raiz.\n\n");
    }
    else
    {
        printf("\nRaiz aproximada: %lf\n",raiz);
    }
}
