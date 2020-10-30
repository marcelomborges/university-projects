#include <stdio.h>
#include <stdlib.h>
#include "listasdeadjacencias.h"

struct no
{
    int vertice;
    int peso;
    NO *proximo;
};

struct grafo
{
    int num_vertices;
    int num_arestas;
    int *grau;
    NO **aresta;
};

GRAFO *cria_grafo(int num_vertices)
{
    int i;
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

    grafo->aresta = (NO**) malloc(num_vertices * sizeof(NO*));
    if(grafo->aresta == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de ponteiros.\n");
        free(grafo->grau);
        free(grafo);
        return NULL;
    }

    for(i = 0; i < num_vertices; i++)
    {
        grafo->aresta[i] = NULL;
    }

    return grafo;
}

int insere_aresta(GRAFO *grafo, int vertice1, int vertice2, int peso)
{
    NO *aux, *novo_no;

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

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }
    if(aux != NULL)
    {
        printf("-> Aresta ja existe.\n");
        return 0;
    }

    novo_no = (NO*) malloc(sizeof(NO));
    if(novo_no == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo no.\n");
        return (-1);
    }

    novo_no->vertice = vertice2;
    novo_no->peso = peso;

    novo_no->proximo = grafo->aresta[vertice1];
    grafo->aresta[vertice1] = novo_no;

    grafo->num_arestas++;
    grafo->grau[vertice1]++;
    grafo->grau[vertice2]++;

    return 1;
}

int verifica_aresta(GRAFO *grafo, int vertice1, int vertice2)
{
    NO* aux;

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
    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }

    if(aux == NULL)
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
    NO *ant, *aux;

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

    ant = NULL;
    aux = grafo->aresta[vertice1];

    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        ant = aux;
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    if(ant == NULL)
    {
        grafo->aresta[vertice1] = aux->proximo;
    }
    else
    {
        ant->proximo = aux->proximo;
    }

    if(aux != NULL)
    {
        free(aux);
    }

    grafo->num_arestas--;
    grafo->grau[vertice1]--;
    grafo->grau[vertice2]--;

    return 1;
}

int consulta_aresta(GRAFO *grafo, int vertice1, int vertice2, int *peso)
{
    NO* aux;

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

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    *peso = aux->peso;
    return 1;
}

void libera_grafo(GRAFO **grafo)
{
    int i;
    NO *aux, *aux2;

    for(i = 0; i < (*grafo)->num_vertices; i++)
    {
        aux = (*grafo)->aresta[i];
        while(aux != NULL)
        {
            aux2 = aux;
            aux = aux->proximo;
            if(aux2 != NULL) free(aux2);
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
    NO *aux;

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
        aux = grafo->aresta[vertice];
        if(aux == NULL)
        {
            printf("-> O vertice %d nao possui adjacentes.", vertice);
        }
        else
        {
            while(aux != NULL)
            {
                printf("(%d -> %d = %d) ", vertice, aux->vertice, aux->peso);
                aux = aux->proximo;
            }
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
