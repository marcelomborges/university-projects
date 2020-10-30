/*
Programa: Trabalho de PP Problema 2 (P2)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 14/04/2016
Descrição: Le a quantidade de voltas e o tempo das voltas. Depois informa o tempo da melhor volta, o numero dela e a media dos tempos das voltas
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int i, n, melhor_volta = 999999;
    float tempo, media, menor_tempo = 999999, soma = 0;

    /*-----------------------*/

    printf("Bem vindo! Recebo um valor para a quantidade de voltas e o tempo de cada volta.\n13");
    printf("Depois calculo qual a volta de menor tempo, qual das voltas foi ela e , tambem, o tempo medio das voltas.\n\n");

    do
    {
    printf("Digite numero de voltas: ");
    scanf("%d", &n);
    }
    while (n <= 0);

    printf("\n");

    for(i = 1; i <= n; i++)
    {
        printf("Digite o tempo da volta: ");
        scanf("%f",&tempo);

        if(tempo < menor_tempo)
        {
            menor_tempo = tempo;
            melhor_volta = i;
        }
        soma += tempo;
    }

    printf("\n");
    media = (float)soma/n;

    printf("O tempo da volta de menor tempo: %.4f\n",menor_tempo);
    printf("A volta em que o melhor tempo ocorreu: %d\n",melhor_volta);
    printf("O tempo medio das voltas: %.4f\n",media);

    return 0;
}
