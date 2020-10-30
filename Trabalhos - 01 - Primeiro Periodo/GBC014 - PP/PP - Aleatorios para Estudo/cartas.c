/*
Programa: Revisao para prova 02
Aluno: Marcelo Mendonca Borges
Data: 29/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Declaracao de Estruturas*/
typedef struct cartas
{
    int valor;
    char naipe[8];

}carta;

int main ()
{
    /*Declaracao de Variaveis*/
    carta **baralho;
    int i, j;
    /*-----------------------*/

    baralho = (carta**) malloc(4 * sizeof(carta*));
    if(baralho == NULL)
    {
        printf("\nALERT: Erro de alocacao de memoria 1...\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < 4; i++)
    {
        baralho[i] = (carta*) malloc(13 * sizeof(carta));
        if(baralho[i] == NULL)
        {
            printf("\nALERT: Erro de alocacao de memoria 1...\n");
            exit(EXIT_FAILURE);
        }
    }


    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            baralho[i][j].valor = j + 1;

            switch(i)
            {
                case 0: strcpy(baralho[i][j].naipe,"Ouros");break;
                case 1: strcpy(baralho[i][j].naipe,"Paus");break;
                case 2: strcpy(baralho[i][j].naipe,"Copas");break;
                case 3: strcpy(baralho[i][j].naipe,"Espadas");break;
                default: strcpy(baralho[i][j].naipe,"Erro");
            }
        }
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            printf("(%d-",baralho[i][j].valor);
            printf("%7s) ",baralho[i][j].naipe);
        }
        printf("\n");
    }

    for(i = 0; i < 4; i++)
    {
        free(baralho[i]);
    }
    free(baralho);

    return 0;
}
