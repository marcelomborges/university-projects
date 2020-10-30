/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

/*Definicao de Estruturas*/
struct no
{
    int info;
    NO* sae;
    NO* sad;
};

/*Definicao de Funcoes*/
ARVORE_BINARIA cria_arvore_binaria_vazia()
{
    return NULL;
}

ARVORE_BINARIA cria_arvore_binaria(int elemento, ARVORE_BINARIA esquerda, ARVORE_BINARIA direita)
{
    NO *novo_no = (NO*) malloc(sizeof(NO));
    if(novo_no == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo no na funcao \"cria_arvore\".\n");
        return NULL;
    }

    novo_no->info = elemento;
    novo_no->sae = esquerda;
    novo_no->sad = direita;

    return novo_no;
}

int arvore_binaria_vazia(ARVORE_BINARIA arvore)
{
    if(arvore == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void libera_arvore_binaria(ARVORE_BINARIA *arvore)
{
    if((*arvore) != NULL)
    {
        libera_arvore_binaria(&((*arvore)->sae));
        libera_arvore_binaria(&((*arvore)->sad));
        free(*arvore);
    }

    *arvore = NULL;
}

int busca_arvore_binaria(ARVORE_BINARIA arvore, int elemento)
{
    int retorno;

    if(arvore == NULL)
    {
        return 0;
    }

    if(arvore->info == elemento)
    {
        return 1;
    }

    retorno = busca_arvore_binaria(arvore->sae, elemento);
    if(retorno == 1)
    {
        return 1;
    }

    retorno = busca_arvore_binaria(arvore->sad, elemento);
    if(retorno == 1)
    {
        return 1;
    }

    return 0;
}

int remove_folha_arvore_binaria(ARVORE_BINARIA *arvore, int elemento)
{
    int controle;
    if((*arvore) == NULL)
    {
        return 0;
    }
    if((*arvore)->info == elemento)
    {
        if(((*arvore)->sae == NULL)&&((*arvore)->sad == NULL))
        {
            free(*arvore);
            (*arvore) = NULL;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        controle = remove_folha_arvore_binaria(&((*arvore)->sae), elemento);
        if(controle == 1)
        {
            return 1;
        }

        controle = remove_folha_arvore_binaria(&((*arvore)->sad), elemento);
        if(controle == 1)
        {
            return 1;
        }

        return 0;
    }
}

void exibe_arvore_binaria(ARVORE_BINARIA arvore)
{
    if(arvore == NULL)
    {
        printf("<>");
    }
    else
    {
        printf("<");
        printf("%d", arvore->info);
        exibe_arvore_binaria(arvore->sae);
        exibe_arvore_binaria(arvore->sad);
        printf(">");
    }
}

void imprime_arvore_binaria(ARVORE_BINARIA arvore)
{
    printf("Arvore:--------------------\n");
    exibe_arvore_binaria(arvore);
    printf("\n---------------------------\n\n");
}
