/*
Programa: Laboratorio 01 Exercicio 14
Aluno: Marcelo Mendonca Borges
Data: 28/04/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /*Declaracao de Variaveis*/

    float x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area;

    /*-----------------------*/
    printf("Calculo a distancia entre 3 pontos (em pares) no plano cartesiano a partir de coordenadas fornecidas.\n");
    printf("Depois calculo a area do triangulo formado por esses 3 pontos.\n\n");

    printf("Digite as coordenadas do primeiro ponto (P1):\n");
    printf("x1 = ");
    scanf("%f",&x1);
    printf("y1 = ");
    scanf("%f",&y1);
    printf("\n");

    printf("Digite as coordenadas do primeiro ponto (P2):\n");
    printf("x2 = ");
    scanf("%f",&x2);
    printf("y2 = ");
    scanf("%f",&y2);
    printf("\n");

    printf("Digite as coordenadas do primeiro ponto (P3):\n");
    printf("x3 = ");
    scanf("%f",&x3);
    printf("y3 = ");
    scanf("%f",&y3);
    printf("\n");

    printf("Pontos:\n");
    printf("P1 = (%.2f,%.2f)\n",x1,y1);
    printf("P2 = (%.2f,%.2f)\n",x2,y2);
    printf("P3 = (%.2f,%.2f)\n\n",x3,y3);

    /*Distancia de P1 para P2*/
    a = sqrt(pow(x2 - x1, 2) + (pow(y2 - y1, 2)));

    /*Distancia de P2 para P3*/
    b = sqrt(pow((x3 - x2), 2) + (pow(y3 - y2, 2)));

    /*Distancia de P3 para P1*/
    c = sqrt(pow((x1 - x3), 2) + (pow(y1 - y3, 2)));

    if((a < b + c) && (b < c + a) && (c < a + b))
    {
        s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("A area do triangulo formado pelos pontos P1, P2 e P3 eh: %.2f\n",area);
    }
    else
    {
        printf("Esses pontos nao formam um triangulo.\n");
    }
    return 0;
}
