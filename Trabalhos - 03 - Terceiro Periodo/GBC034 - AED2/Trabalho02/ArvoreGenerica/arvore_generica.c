/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore_generica.h"
#include "fila_arvore_generica.h"

/*Definicao de Estruturas*/
struct no
{
    int info;
    NO* esquerda;
    NO* direita;
};

/*Definicao de Funcoes*/
ARVORE_GENERICA cria_arvore_generica(int elemento)
{
    NO *novo_no = (NO*) malloc(sizeof(NO));
    if(novo_no == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo no na funcao \"cria_arvore\".\n");
        return NULL;
    }

    novo_no->info = elemento;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;

    return novo_no;
}

int insere_generica(ARVORE_GENERICA arvore_no, ARVORE_GENERICA subarvore)
{
    if(arvore_no == NULL)
    {
        printf("-> Erro: Arvore recebida de parametro na funcao \"cria_arvore\" eh invalida.\n");
        return 0;
    }

    subarvore->direita = arvore_no->esquerda;
    arvore_no->esquerda = subarvore;

    return 1;
}

int busca_generica(ARVORE_GENERICA arvore, int elemento)
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

    retorno = busca_generica(arvore->esquerda, elemento);
    if(retorno == 1)
    {
        return 1;
    }

    retorno = busca_generica(arvore->direita, elemento);
    if(retorno == 1)
    {
        return 1;
    }

    return 0;
}

void libera_arvore_generica(ARVORE_GENERICA *arvore)
{
    if((*arvore) != NULL)
    {
        libera_arvore_generica(&((*arvore)->esquerda));
        libera_arvore_generica(&((*arvore)->direita));
        free(*arvore);
    }

    *arvore = NULL;
}

void exibe_arvore_generica(ARVORE_GENERICA arvore)
{
    if(arvore != NULL)
    {
        printf("<");
        printf("%d", arvore->info);
        exibe_arvore_generica(arvore->esquerda);
        printf(">");
        exibe_arvore_generica(arvore->direita);
    }
}

void imprime_arvore_generica(ARVORE_GENERICA arvore)
{
    printf("Arvore Generica:------------------------------\n");
    exibe_arvore_generica(arvore);
    printf("\n----------------------------------------------\n\n");
}

/*Parte 01 do Trabalho 02 de AED2----------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

void preorder(ARVORE_GENERICA arvore)
{
    if(arvore != NULL)
    {
        printf("%d ", arvore->info);
        preorder(arvore->esquerda);
        preorder(arvore->direita);
    }
}

void imprime_preorder(ARVORE_GENERICA arvore)
{
    printf("Arvore Generica - Preorder--------------------\n");
    preorder(arvore);
    printf("\n----------------------------------------------\n\n");
}

/*-----------------------------------------------------------------------------------------------*/

void postorder(ARVORE_GENERICA arvore)
{
    if(arvore != NULL)
    {
        postorder(arvore->esquerda);
        postorder(arvore->direita);
        printf("%d ", arvore->info);
    }
}

void imprime_postorder(ARVORE_GENERICA arvore)
{
    printf("Arvore Generica - Postorder:------------------\n");
    postorder(arvore);
    printf("\n----------------------------------------------\n\n");
}

/*-----------------------------------------------------------------------------------------------*/

void percorre_nivel(ARVORE_GENERICA arvore)
{
    ARVORE_GENERICA arvore_auxiliar;
    FILA_ARVORE_GENERICA *fila = cria_fila_arvore_generica();

    if(arvore != NULL)
    {
        insere_fila_arvore_generica(arvore, fila);
        while(fila->tamanho > 0)
        {
            arvore_auxiliar = remove_fila_arvore_generica(fila);
            while(arvore_auxiliar != NULL)
            {
                printf("%d ", arvore_auxiliar->info);
                if(arvore_auxiliar->esquerda != NULL)
                {
                    insere_fila_arvore_generica(arvore_auxiliar->esquerda, fila);
                }
                arvore_auxiliar = arvore_auxiliar->direita;
            }
        }
    }
}

void imprime_percorre_nivel(ARVORE_GENERICA arvore)
{
    printf("Arvore Generica - Percorrimento por Nivel-----\n");
    percorre_nivel(arvore);
    printf("\n----------------------------------------------\n\n");
}

/*-----------------------------------------------------------------------------------------------*/

int nro_derivacao(ARVORE_GENERICA arvore)
{
    if(arvore == NULL)
    {
        return 0;
    }

    int nos_derivacao_esquerda = 0;
    int nos_derivacao_direita = 0;
    int nos_derivacao_total = 0;

    nos_derivacao_esquerda = nro_derivacao(arvore->esquerda);
    nos_derivacao_direita = nro_derivacao(arvore->direita);
    nos_derivacao_total = nos_derivacao_esquerda + nos_derivacao_direita;

    if(arvore->esquerda != NULL)
    {
        nos_derivacao_total++;
    }

    return nos_derivacao_total;
}

/*-----------------------------------------------------------------------------------------------*/

int grau_no(ARVORE_GENERICA arvore)
{
    int total_filhos = 0;
    ARVORE_GENERICA arvore_auxiliar;

    if(arvore == NULL)
    {
        printf("-> Erro: Arvore eh invalida na funcao \"numero_filhos_arvore_generica\".\n");
        return (-1);
    }
    if(arvore->esquerda == NULL)
    {
        return 0;
    }

    arvore_auxiliar = arvore->esquerda;

    while(arvore_auxiliar != NULL)
    {
        total_filhos++;
        arvore_auxiliar = arvore_auxiliar->direita;
    }

    return total_filhos;
}

int grau_arv(ARVORE_GENERICA arvore)
{
    if(arvore == NULL)
    {
        return (-1);
    }

    int maior_grau_esquerda = 0;
    int maior_grau_direita = 0;
    int grau_auxiliar = 0;
    int grau_arvore = 0;

    maior_grau_esquerda = grau_arv(arvore->esquerda);
    maior_grau_direita = grau_arv(arvore->direita);
    grau_auxiliar = grau_no(arvore);

    if(maior_grau_esquerda > maior_grau_direita)
    {
        if(grau_auxiliar > maior_grau_esquerda)
        {
            return grau_auxiliar;
        }
        else
        {
            return maior_grau_esquerda;
        }
    }
    else
    {
        if(grau_auxiliar > maior_grau_direita)
        {
            return grau_auxiliar;
        }
        else
        {
            return maior_grau_direita;
        }
    }
}

/*-----------------------------------------------------------------------------------------------*/

int qtde_nos_generica(ARVORE_GENERICA arvore, int grau)
{
    if(arvore == NULL)
    {
        return 0;
    }

    int nos_grau_esquerda = 0;
    int nos_grau_direita = 0;
    int nos_grau_total = 0;

    nos_grau_esquerda = qtde_nos_generica(arvore->esquerda, grau);
    nos_grau_direita = qtde_nos_generica(arvore->direita, grau);
    nos_grau_total = nos_grau_esquerda + nos_grau_direita;

    if(grau_no(arvore) == grau)
    {
        nos_grau_total++;
    }

    return nos_grau_total;
}

/*-----------------------------------------------------------------------------------------------*/

int altura_arvore_generica(ARVORE_GENERICA arvore)
{
    int altura_arvore;
    int maior_altura = (-1);
    ARVORE_GENERICA arvore_auxiliar;

    if(arvore == NULL)
    {
        return (-1);
    }

    arvore_auxiliar = arvore->esquerda;
    while(arvore_auxiliar != NULL)
    {
        altura_arvore = altura_arvore_generica(arvore_auxiliar);
        if(altura_arvore > maior_altura)
        {
            maior_altura = altura_arvore;
        }
        arvore_auxiliar = arvore_auxiliar->direita;
    }

    maior_altura++;

    return maior_altura;
}

int altura_no(ARVORE_GENERICA arvore, int elemento)
{
    int altura_esquerda = 0;
    int altura_direita = 0;
    int altura_retorno = (-1);

    if(arvore == NULL)
    {
        return (-1);
    }

    if(arvore->info == elemento)
    {
        altura_retorno = altura_arvore_generica(arvore);
        return altura_retorno;
    }

    altura_esquerda = altura_no(arvore->esquerda, elemento);
    if(altura_esquerda != (-1))
    {
        return altura_esquerda;
    }
    altura_direita = altura_no(arvore->direita, elemento);
    if(altura_direita != (-1))
    {
        return altura_direita;
    }

    return altura_retorno;
}

/*-----------------------------------------------------------------------------------------------*/

void imprime_cabecalho()
{
    printf("#-------------------------- Parte 1 - Arvore Generica ------------------------------------#\n");
    printf("|-----------------------------------------------------------------------------------------|\n");
    printf("|Operacoes Disponiveis:-------------------------------------------------------------------|\n");
    printf("|1 - Percorrer em Pre-Ordem                                                               |\n");
    printf("|2 - Percorrer em Pos-Ordem                                                               |\n");
    printf("|3 - Percorrer em Nivel (em Largura)                                                      |\n");
    printf("|4 - Quantidade de Nos de Derivacao                                                       |\n");
    printf("|5 - Grau da Arvore                                                                       |\n");
    printf("|6 - Quantidade de Nos de Determinado Grau                                                |\n");
    printf("|7 - Altura de Determinado No                                                             |\n");
    printf("|8 - Sair                                                                                 |\n");
    printf("#-----------------------------------------------------------------------------------------#\n\n");
}
