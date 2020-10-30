/*
Programa: Laboratorio 03 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao: Recebe os valores e "monta" um polinomio, e depois calcula pontos nesse polinomio
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /* Declaracao de variaveis */

    int n, i, j, k;
    float coef[100], x[100], px[100] = {0};

    /*-------------------------*/

    printf("Recebo os valores do grau e dos coeficientes de um polinomio e o imprimo.\n");
    printf("Depois recebo um valor da quantidade de pontos e seus respectivos valores para calcular nesse polinomio.\n\n");

    printf("Digite o grau do polinomio: ");
    scanf("%d",&n);
    printf("\n");

    printf("Digite os coeficientes:\n");
    for(i = 0; i <= n; i++)
    {
        if(i == 0)
        {
            printf("Digite o termo independente: ");
            scanf("%f",&coef[i]);
        }
        else
        {
            printf("Digite o coeficiente a%d (que multiplicara o x^%d): ",i,i);
            scanf("%f",&coef[i]);
        }
    }

    printf("\nO polinomio eh:\n");
    printf("p(x) = ");
    for(i = 0; i <= n; i++)
    {
        if(i == 0)
        {
            printf("%.2f ",coef[i]);
        }
        else
        {
            if(coef[i] > 0)
            {
                printf("+ %.2f*(x^%d)",fabs(coef[i]),i);
            }
            else
            {
                printf("- %.2f*(x^%d)",fabs(coef[i]),i);
            }
        }
    }

    printf("\n\n");

    do
    {
        printf("Digite a quantidade de pontos (x) que serao analisados: ");
        scanf("%d",&k);
    }
    while(k <= 0);

    for(i = 0; i < k; i++)
    {
        printf("Digite o ponto (x%d) que sera analisado: ",i+1);
        scanf("%f",&x[i]);
    }

    printf("\n");

    for(i = 0; i < k; i++)
    {
        for(j = 0; j <= n; j++)
        {
            px[i] += coef[j] * pow(x[i], j);
        }
        printf("p(%.2f) = %.2f\n",x[i],px[i]);
    }

    return 0;
}
