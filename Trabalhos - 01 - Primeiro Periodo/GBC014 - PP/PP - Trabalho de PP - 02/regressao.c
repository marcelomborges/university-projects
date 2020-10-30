/*
Programa: Trabalho 02 Problema 3 (P3)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 07/05/2016
Descricao: Recebe pontos (em coordenadas cartesianas) de uma reta e calcula os coeficientes (A e B) da  equacao da reta (Y = AX + B)
           utilizando o metodo de regressao linear.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
void regressao_linear(int, float, float, float, float); /*Nao eh possivel retornar 2 valores de uma funcao*/

int main()
{
    /*Declaracao de Variaveis*/
    int quantp, i, j, verif =0;
    float x[20], y[20], sxx = 0.0, sxy = 0.0, sx = 0.0, sy = 0.0;
    /*-----------------------*/
    printf("Calculo, a partir de pontos fornecidos, os coeficientes da equacao da reta formada por esse pontos.\n");
    printf("Observacao: Sao necessarios pelo menos 2 pontos (distintos) para se formar uma reta.\n\n");

    do
    {
        printf("Digite a quantidade de  pontos de coordenadas (x,y) que voce deseja analisar: ");
        scanf("%d",&quantp);
    }
    while(quantp <= 1);
    printf("\n");

    for(i = 0; i < quantp; i++)
    {
        printf("Digite o x do par numero %d: ",i + 1);
        scanf("%f",&x[i]);
        printf("Digite o y do par numero %d: ",i + 1);
        scanf("%f",&y[i]);
        printf("\n");
    }

    for(i = 0; i < quantp; i++)
    {
        if((x[i] == x[i + 1]) && (y[i] == y[i + 1]))
        {
            verif++;
        }
    }
    if(verif == quantp - 1)
    {
        printf("Todos os pontos sao iguais.\n");
    }
    else
    {
        printf("Pontos escolhidos:\n");
        for(i = 0; i < quantp; i++)
        {
            printf("Ponto %d: (%.2f,%.2f)\n",i+1,x[i],y[i]);
        }

        for(i = 0; i < quantp; i++)
        {
            sx +=  x[i];
            sy +=  y[i];
            sxy += x[i] * y[i];
            sxx += x[i] * x[i];
        }
        printf("\n");

        regressao_linear(quantp,sx,sy,sxy,sxx);
    }

    return 0;
}

void regressao_linear(int n, float sx, float sy, float sxy, float sxx)
{
    float a, b;

    a = ((n * sxy) - (sx * sy)) / ((n * sxx) - (sx * sx));
    b = (sy - ( a * sx)) / n;

    printf("\nA equacao da reta eh:\n");
    printf("Y = (%.2f * X) + %.2f\n", a, b);
}


