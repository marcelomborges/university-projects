#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento
{
    int vertice;
    int peso;
    ELEMENTO* proximo;
};

struct lista
{
    int tamanho;
    ELEMENTO* primeiro;
    ELEMENTO* ultimo;
};

void cria_lista (LISTA* lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void insere_elemento_final (LISTA *lista, int vertice, int peso)
{
    ELEMENTO* novo_elemento;

    novo_elemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    if(novo_elemento == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo elemento.\n");
        return;
    }

    novo_elemento->vertice = vertice;
    novo_elemento->peso = peso;
    novo_elemento->proximo == NULL;

    if(lista->tamanho == 0)
    {
        lista->primeiro = novo_elemento;
        lista->ultimo = novo_elemento;
        lista->tamanho++;
    }
    else
    {
        lista->ultimo->proximo = novo_elemento;
        lista->ultimo = novo_elemento;
        lista->tamanho++;
    }
}

int retira_primeiro_elemento(LISTA *lista)
{
    int retorno;
    ELEMENTO *aux;

    aux = lista->primeiro;
    retorno = lista->primeiro->vertice;

    lista->primeiro = lista->primeiro->proximo;

    free(aux);

    lista->tamanho--;

    return retorno;
}
