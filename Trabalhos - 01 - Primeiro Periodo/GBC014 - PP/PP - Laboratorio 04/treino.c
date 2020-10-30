/*
Programa: Laboratorio 04 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 12/05/2016
Descricao: Le uma matriz e verifica se ela eh simetrica
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    /*Declaracao de Variaveis*/
    int i, j;
    float tempos[5][7], media = 0, melhor_tempo[5];
    /*-----------------------*/
    printf("Recebo o tempo (em segundos) de 6 voltas do treino de 5 atletas.\n");
    printf("Depois calculo a media do tempo para cada atleta e informo qual a melhor volta de cada.\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("Informe os tempos (em s) do atleta %d:\n",i + 1);
        for(j = 0; j < 6; j++)
        {
            printf("Digite o tempo %d: ",j + 1);
            scanf("%f",&tempos[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 6; j++)
        {
            media += tempos[i][j];
        }
        tempos[i][6] = media / 6;
        media = 0;
    }

    system("CLS");

    printf("\nTREINO  | ");
    for(j = 0; j < 7; j++)
    {
        if(j == 6) printf("%8s","Media");
        else printf("%8s%d","Tempo",j + 1);
    }
    printf("\n");
    for(j = 0; j < (9 * 9) - 7; j++)
    {
        if(j == 8) printf("|");
        else printf("-",j + 1);
    }
    printf("\n");
    for(i = 0; i < 5; i++)
    {
        printf("Atleta %d|",i + 1);
        for(j = 0; j < 7; j++)
        {
            printf("%9.2f",tempos[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(j == 0)
            {
                melhor_tempo[i] = tempos[i][j];
            }
            else if(tempos[i][j] < melhor_tempo[i])
            {
                melhor_tempo[i] = tempos[i][j];
            }
        }
    }
    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("Melhor tempo do atleta %d: %.2f", i+1, melhor_tempo[i]);
        printf("\n");
    }

    return 0;
}
