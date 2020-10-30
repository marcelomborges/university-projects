/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore_generica.h"
#include "fila_arvore_generica.h"

/*Definicao de Funcoes*/
FILA_ARVORE_GENERICA* cria_fila_arvore_generica()
{
    FILA_ARVORE_GENERICA *fila = (FILA_ARVORE_GENERICA*) malloc(sizeof(FILA_ARVORE_GENERICA));
    if(fila == NULL)
    {
        printf("-> Erro: Falha na alocacao da fila na funcao \"cria_fila_arvore_generica\".\n");
    }

    fila->tamanho = 0;
    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

int insere_fila_arvore_generica(ARVORE_GENERICA arvore, FILA_ARVORE_GENERICA* fila)
{
    if(arvore == NULL)
    {
        printf("-> Erro: Arvore eh invalida na funcao \"insere_fila_arvore_generica\".\n");
        return 0;
    }
    if(fila == NULL)
    {
        printf("-> Erro: Fila eh invalida na funcao \"insere_fila_arvore_generica\".\n");
        return 0;
    }

    ELEMENTO_FILA_ARVORE_GENERICA *elemento = (ELEMENTO_FILA_ARVORE_GENERICA*) malloc(sizeof(ELEMENTO_FILA_ARVORE_GENERICA));
    if(elemento == NULL)
    {
        printf("-> Erro: Falha na alocacao do elemento da fila na funcao \"insere_fila_arvore_generica\".\n");
        return 0;
    }

    elemento->arvore_fila = arvore;
    elemento->proxima_arvore = NULL;

    if(fila->tamanho == 0)
    {
        fila->primeiro = elemento;
        fila->ultimo = elemento;
        fila->tamanho++;
    }
    else
    {
        fila->ultimo->proxima_arvore = elemento;
        fila->ultimo = elemento;
        fila->tamanho++;
    }

    return 1;
}

ARVORE_GENERICA* remove_fila_arvore_generica(FILA_ARVORE_GENERICA* fila)
{
    if(fila == NULL)
    {
        printf("-> Erro: Fila eh invalida na funcao \"remove_fila_arvore_generica\".\n");
        return NULL;
    }

    ARVORE_GENERICA arvore_auxiliar;
    ELEMENTO_FILA_ARVORE_GENERICA *elemento_auxiliar;

    arvore_auxiliar = fila->primeiro->arvore_fila;
    elemento_auxiliar = fila->primeiro;

    fila->primeiro = fila->primeiro->proxima_arvore;

    if(elemento_auxiliar != NULL)
    {
        free(elemento_auxiliar);
    }

    fila->tamanho--;

    return arvore_auxiliar;
}
