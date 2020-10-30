/*
Programa: Laboratorio 02 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 02/04/2016
Descrição: Recebe o número de lados, e o valor destes de um polígono regular e calcula sua área
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    int ql;
    float lt,at,lq,aq,lh,ah;

    /*-----------------------*/
    printf("Bem vindo ao calculador de areas de poligonos regulares.\n");
    printf("Calculo a area de triangulos regulares, quadrados e hexagonos regulares.\n");

    while ((ql != 3) && (ql != 4) && (ql != 6))
    {
        printf("Digite o numero de lados do poligono regular:\n");
        scanf("%d",&ql);

        switch(ql)
        {
        case 3:
            printf("Digite o tamanho dos lados desse triangulo (Um valor para todos os lados):\n");
            scanf("%f",&lt);
            at = pow(lt,2) * (sqrt(3) / 4);
            printf("A area do triangulo regular de lado %.2f eh %.2f\n",lt,at);
            break;
        case 4:
            printf("Digite o tamanho dos lados desse quadrado (Um valor para todos os lados):\n");
            scanf("%f",&lq);
            aq = pow(lq,2);
            printf("A area do quadrado de lado %.2f eh %.2f\n",lq,aq);
            break;
        case 6:
            printf("Digite o tamanho dos lados desse hexagono (Um valor para todos os lados):\n");
            scanf("%f",&lh);
            ah = 6 * (pow(lh,2) * (sqrt(3) / 4));
            printf("A area do hexagono regular de lado %.2f eh %.2f\n",lh,ah);
            break;
        default:
            printf("Poligono desconhecido!\n\n");
        };
    };
    return 0;
}
