/*
Programa: Trabalho 01 - AED2 - Problema do Roteamento Multicast
Aluno: Adriano Araujo Martins De Resende --- Matricula: 11611BCC015
Aluno: Higor Emanuel Souza Silva ----------- Matricula: 11611BCC016
Aluno: Marcelo Mendonca Borges ------------- Matricula: 11611BCC020
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listasdeadjacencias.h"

int main()
{
    /*Declaracao de Variaveis*/
    int i, j, metrica;
    int origem = 0, *receptores;
    int **caminhos, **caminhos2;
    float mensagem = 10;
    GRAFO_LA *grafo;
    /*-----------------------*/

    printf("Listas de Adjacencias:\n\n");

    grafo = leitura_arquivo_la("grafo03.txt");
    if(grafo == NULL)
    {
        return 1;
    }

    receptores = (int*) malloc(numVertices_la(grafo) * sizeof(int));
    {
        if(receptores == NULL)
        {
            printf("-> Erro: Falha na alocacao do vetor de receptores.\n");
        }
    }
    for(i = 0; i < (numVertices_la(grafo)-1); i++)
    {
        receptores[i] = i+1;
    }

    /*Metrica Custo*/
    metrica = custo_total_la(grafo, origem, receptores, (numVertices_la(grafo)-1), 1);
    printf("Valor da Metrica Custo Total para Profundidade: %d\n", metrica);

    metrica = custo_total_la(grafo, origem, receptores, (numVertices_la(grafo)-1), 2);
    printf("Valor da Metrica Custo Total para Dijkstra: %d\n", metrica);

    /*Metrica Delay*/
    metrica = delay_maximo_la(grafo, origem, receptores,(numVertices_la(grafo)-1), 1);
    printf("Valor da Metrica Delay Maximo para Profundidade: %d\n", metrica);

    metrica = delay_maximo_la(grafo, origem, receptores, (numVertices_la(grafo)-1), 2);
    printf("Valor da Metrica Delay Maximo para Dijkstra: %d\n", metrica);




    /*Metrica UME*/
    metrica = utilizacao_maxima_enlace(grafo, origem, receptores, (numVertices_la(grafo)-1), 1, mensagem);
    printf("Valor da Metrica Utilizacao Maxima do Enlace para Profundidade: %d\n", metrica);

    metrica = utilizacao_maxima_enlace(grafo, origem, receptores, (numVertices_la(grafo)-1), 2, mensagem);
    printf("Valor da Metrica Utilizacao Maxima do Enlace para Dijkstra: %d\n", metrica);

    libera_grafo_la(&grafo);

    return 0;
}
