/*
Programa: Grafo - Matriz de Adjacencias
Aluno: Marcelo Mendonca Borges
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrizdeadjacencias.h"

int main()
{
    /*Declaracao de Variaveis*/
    int controle, peso_retorno;
    GRAFO *grafo;
    /*-----------------------*/

    printf("Matriz de Adjacencias:\n\n");

    grafo = cria_grafo(6);
    if(grafo == NULL)
    {
        return 1;
    }

    /*Exercicios - Aula Teorica 06*/
    insere_aresta(grafo, 1, 2, 2);
    insere_aresta(grafo, 1, 4, 6);
    insere_aresta(grafo, 2, 2, 1);
    insere_aresta(grafo, 3, 0, 3);
    insere_aresta(grafo, 3, 2, 8);
    insere_aresta(grafo, 4, 0, 5);
    insere_aresta(grafo, 4, 1, 4);
    insere_aresta(grafo, 4, 3, 7);
    insere_aresta(grafo, 5, 0, 2);

    controle = verifica_aresta(grafo, 5, 0);
    printf("-> Verifica Aresta (5 -> 0) = %d\n\n", controle);

    controle = consulta_aresta(grafo, 5, 0, &peso_retorno);
    printf("-> Consulta Aresta (5 -> 0) = %d\n", controle);
    printf("-> Peso da Aresta (5 -> 0) = %d\n", peso_retorno);

    mostra_grafo(grafo);
    printf("Numero de Vertices = %d\n",get_vertices(grafo));
    printf("Numero de Arestas = %d\n",get_arestas(grafo));

    controle = remove_aresta(grafo, 5, 0);
    printf("\n-> Remove Aresta (5 -> 0) = %d\n", controle);

    mostra_grafo(grafo);
    printf("Numero de Vertices = %d\n",get_vertices(grafo));
    printf("Numero de Arestas = %d\n",get_arestas(grafo));

    libera_grafo(&grafo);

    return 0;
}
