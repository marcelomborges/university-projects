#include <stdio.h>
#include <stdlib.h>
#include "matrizdeadjacencias.h"

struct grafo
{
    int num_vertices;
    int num_arestas;
    int *grau;
    int **aresta;
};

GRAFO *cria_grafo(int num_vertices)
{
    int i, j;
    GRAFO *grafo;

    /*Verifica o valor da quantidade de vertices*/
    if(num_vertices <= 0)
    {
        printf("-> Erro: Numero de vertices invalido.\n");
        return NULL;
    }

    /*Alocacao do Grafo*/
    grafo = (GRAFO*) malloc(sizeof(GRAFO));
    if(grafo == NULL)
    {
        printf("-> Erro: Falha na alocacao do grafo.\n");
        return NULL;
    }

    /*Iniciando valores no grafo*/
    grafo->num_vertices = num_vertices;
    grafo->num_arestas = 0;

    /*Alocacao do vetor de graus*/
    grafo->grau = (int*) calloc(num_vertices, sizeof(int));
    if(grafo->grau == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de graus.\n");
        free(grafo);
        return NULL;
    }

    /*Alocacao da matriz de arestas*/
    grafo->aresta = (int**) malloc(num_vertices * sizeof(int*));
    if(grafo->aresta == NULL)
    {
        printf("-> Erro: Falha na alocacao da matriz de arestas.\n");
        free(grafo->grau);
        free(grafo);
        return NULL;
    }

    for(i = 0; i < num_vertices; i++)
    {
        grafo->aresta[i] = (int*) calloc(num_vertices, sizeof(int));
        if(grafo->aresta[i] == NULL)
        {
            printf("-> Erro: Falha na alocacao de um dos vetores da matriz.\n");
            for(j = 0; j < i; j++)
            {
                free(grafo->aresta[j]);
            }
            free(grafo->aresta);
            free(grafo->grau);
            free(grafo);
            return NULL;
        }
    }

    return grafo;
}

int insere_aresta(GRAFO *grafo, int vertice1, int vertice2, int peso)
{
    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }

    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }

    if(grafo->aresta[vertice1][vertice2] != 0)
    {
        printf("-> Aresta ja existe.\n");
        return 0;
    }

    grafo->aresta[vertice1][vertice2] = peso;
    grafo->num_arestas++;
    grafo->grau[vertice1]++;
    grafo->grau[vertice2]++;

    return 1;
}

int verifica_aresta(GRAFO *grafo, int vertice1, int vertice2)
{
    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }

    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }

    if(grafo->aresta[vertice1][vertice2] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int remove_aresta(GRAFO *grafo, int vertice1, int vertice2)
{
    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }

    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }

    if(grafo->aresta[vertice1][vertice2] == 0)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    grafo->aresta[vertice1][vertice2] = 0;
    grafo->num_arestas--;
    grafo->grau[vertice1]--;
    grafo->grau[vertice2]--;

    return 1;
}

int consulta_aresta(GRAFO *grafo, int vertice1, int vertice2, int *peso)
{
    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }

    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }

    if(grafo->aresta[vertice1][vertice2] == 0)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    *peso = grafo->aresta[vertice1][vertice2];

    return 1;
}

void libera_grafo(GRAFO **grafo)
{
    int i;

    /*Verificacao dos Parametros de Entrada*/
    if((*grafo) == NULL)
    {
       return;
    }

    for(i = 0; i < (*grafo)->num_vertices; i++)
    {
        if((*grafo)->aresta[i] != NULL)
        {
            free((*grafo)->aresta[i]);
        }
    }
    if((*grafo)->aresta != NULL)
    {
        free((*grafo)->aresta);
    }

    if((*grafo)->grau != NULL)
    {
        free((*grafo)->grau);
    }

    if((*grafo) != NULL)
    {
        free(*grafo);
    }

    grafo = NULL;
}

void mostra_adjacentes(GRAFO *grafo, int vertice)
{
    int i, cont;

    cont = 0;

    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inexistente.\n");
    }
    else if((vertice < 0)||(vertice > (grafo->num_vertices - 1)))
    {
        printf("-> Erro: Vertice invalido.\n");
    }
    else
    {
        for(i = 0; i < grafo->num_vertices; i++)
        {
            if(grafo->aresta[vertice][i] != 0)
            {
                printf("(%d -> %d = %d) ", vertice, i, grafo->aresta[vertice][i]);
                cont++;
            }
        }
        if(cont == 0)
        {
            printf("-> O vertice %d nao possui adjacentes.", vertice);
        }
    }
}

void mostra_grafo(GRAFO *grafo)
{
    int i;

    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inexistente.\n");
    }
    else if(grafo->num_arestas == 0)
    {
        printf("-> Grafo vazio.\n");
    }
    else
    {
        printf("\nGrafo:--------------------------------------------------\n");
        for(i = 0; i < grafo->num_vertices; i++)
        {
            printf("Vertice %d: ", i);
            mostra_adjacentes(grafo, i);
            printf("\n");
        }
        printf("--------------------------------------------------------\n");
    }
}

int get_vertices(GRAFO *grafo)
{
    return grafo->num_vertices;
}

int get_arestas(GRAFO *grafo)
{
    return grafo->num_arestas;
}
