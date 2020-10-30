/*
Programa: Laboratorio 03 Exercicio 2
Aluno: Marcelo Mendonca Borges
Data: 08/04/2016
Descricao: Calcula o desvio padrao, media e media dos quadrados de uma sequencia
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /* Declaracao de variaveis */

    int n, i;
    float v[100], x=0.0, x2=0.0, s;

    /*-------------------------*/

    do
    {
        printf("Quantos numeros, em sequencia, que voce deseja analisar (0 < n <= 100):\n");
        scanf("%d",&n);
        printf("\n");
    }
    while ((n <= 0) || (n > 100));

    for(i = 0; i < n; i++)
    {
        printf("Digite um numero: ");
        scanf("%f",&v[i]);
        x += v[i];
        x2 += pow(v[i],2);
    }

    x = x / n;
    x2 = x2 / n;
    s = sqrt(x2 - pow(x,2));

    printf("\nO desvio padrao da sequencia eh: %f\n",s);
    printf("A media da sequencia eh: %f\n",x);
    printf("A media dos quadrados da sequencia eh: %f\n",x2);

    return 0;
}
