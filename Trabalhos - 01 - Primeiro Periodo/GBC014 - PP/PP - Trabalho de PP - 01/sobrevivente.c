/*
Programa: Trabalho de PP Problema 14 (P14)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 18/04/2016
Descricao: Promove uma brincadeira de sobrevivente, que consiste em remover pessoas de um circulo
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 200

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int n, part_ini, i, j, v[SIZE];

    /*-----------------------*/

    printf("Bem vindo! Eu promovo uma brincadeira apos receber o numero de participantes, que devem formar um circulo numerado.\n");
    printf("A brincadeira eh o seguinte:\n");
    printf("-Primeiro seleciono um participante aleatorio, que eh o primeiro excluido\n");
    printf("-Vou excluindo alternadamente pessoas do circulo (pessoa sim - pessoa nao), a partir do primeiro\n");
    printf("-As exclusoes acontecem na ordem crescente dos numeros do circulo\n");
    printf("-O jogo acaba quando sobrar somente uma pessoa no circulo\n");
    printf("-Essa pessoa restante eh o sobrevivente e o vencedor\n\n");

    do
    {
        printf("Digite o numero de participantes:\n");
        scanf("%d",&n);
    }
    while(n <= 0);

    srand(time(NULL));
    part_ini = (rand() % n) + 1;
    printf("\nParticipante inicial: Numero %d\n\n",part_ini);

    for(i = 1; i <= n; i++)
    {
        v[i] = i;
    }

    printf("Mortes:\n");
    for(i = part_ini; n != 1; i++)
    {
        printf("Mata %d\n",v[i]);
        for(j = i; j < n; j++)
        {
            v[j] = v[j + 1];
        }

        n--;

        if(i >= n)
        {
            i -= n;
        }
    }

    printf("\nResultado:\n");
    printf("Sobrevive: %d\n",v[1]);

    return 0;
}
