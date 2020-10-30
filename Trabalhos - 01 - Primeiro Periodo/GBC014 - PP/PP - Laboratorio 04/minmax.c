/*
Programa: Laboratorio 04 Exercicio 2
Aluno: Marcelo Mendonca Borges
Data: 15/04/2016
Descricao: Le uma matriz, identifico e informo qual o valor do minmax dessa matriz
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /* Declaracao de variaveis */
    int i, j, k, linha_menor, coluna_minmax;
    float m[4][5], menor = 9999.9, maior = 0.0, minmax;
    /*-------------------------*/

    printf("Leio uma matriz (4x5), identifico e informo qual o valor do minmax dessa matriz.\n\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("Digite o valor do elemento M[%d][%d] = ",i,j);
            scanf("%f",&m[i][j]);
        }
        printf("\n");
    }

    printf("Matriz:\n\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%7.2f",m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if((m[i][j] < menor)||(m[i][j] == menor))
            {
                menor = m[i][j];
                linha_menor = i;
                for(k = 0; k < 5; k++)
                {
                    if((m[linha_menor][k] > maior)||(m[linha_menor][k] == maior))
                    {
                        maior = m[linha_menor][k];
                        coluna_minmax = k;
                        minmax = maior;
                    }
                }
            }
        }
    }

    printf("\nO MINMAX dessa matriz eh %.02f e sua posicao eh M[%d][%d].\n",minmax,linha_menor,coluna_minmax);

    return 0;
}
