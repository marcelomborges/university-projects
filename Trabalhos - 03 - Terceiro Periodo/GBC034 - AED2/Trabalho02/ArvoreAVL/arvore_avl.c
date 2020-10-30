/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore_avl.h"

/*Definicao de Funcoes*/
ARVORE_AVL cria_arvore_avl()
{
    return NULL;
}

int arvore_avl_vazia(ARVORE_AVL *arvore)
{
    if(*arvore == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ARVORE_AVL busca_binaria_arvore_avl(ARVORE_AVL arvore, int trafego)
{
    if(arvore == NULL)
    {
        printf("-> Nao existe o elemento procurado com essa chave.\n");
        return NULL;
    }

    if(arvore->info.trafego == trafego)
    {
        return arvore;
    }
    else if(trafego > arvore->info.trafego)
    {
        return busca_binaria_arvore_avl(arvore->sad, trafego);
    }
    else
    {
        return busca_binaria_arvore_avl(arvore->sae, trafego);
    }
}

void exibe_arvore_avl(ARVORE_AVL arvore)
{
    if(arvore == NULL)
    {
        printf("<>");
    }
    else
    {
        printf("<");
        printf("%d", arvore->info.trafego);
        exibe_arvore_avl(arvore->sae);
        exibe_arvore_avl(arvore->sad);
        printf(">");
    }
}

void exibe_ordenado_arvore_avl(ARVORE_AVL arvore)
{
    if(arvore != NULL)
    {
        exibe_ordenado_arvore_avl(arvore->sae);
        printf("%d ", arvore->info.trafego);
        exibe_ordenado_arvore_avl(arvore->sad);
    }
}


void libera_arvore_avl(ARVORE_AVL *arvore)
{
    if((*arvore) != NULL)
    {
        libera_arvore_avl(&((*arvore)->sae));
        libera_arvore_avl(&((*arvore)->sad));
        free(*arvore);
    }

    *arvore = NULL;
}

int rotacao_direita(ARVORE_AVL *arvore)
{
    ARVORE_AVL auxiliar;

    if(((*arvore) != NULL)&&((*arvore)->sae != NULL))
    {
        auxiliar = (*arvore)->sae;
        (*arvore)->sae = auxiliar->sad;
        auxiliar->sad = (*arvore);
        (*arvore)->fb = 0;
        auxiliar->fb = 0;
        (*arvore) = auxiliar;
        return 1;
    }

    return 0;
}

int rotacao_esquerda(ARVORE_AVL *arvore)
{
    ARVORE_AVL auxiliar;

    if(((*arvore) != NULL)&&((*arvore)->sad != NULL))
    {
        auxiliar = (*arvore)->sad;
        (*arvore)->sad = auxiliar->sae;
        auxiliar->sae = (*arvore);
        (*arvore)->fb = 0;
        auxiliar->fb = 0;
        (*arvore) = auxiliar;
        return 1;
    }

    return 0;
}

int rotacao_direita_esquerda(ARVORE_AVL *pai)
{
    ARVORE_AVL filho_esquerda;
    ARVORE_AVL neto_direita;

    if(((*pai) != NULL)&&((*pai)->sae != NULL))
    {

        filho_esquerda = (*pai)->sae;

        neto_direita = filho_esquerda->sad;

        filho_esquerda->sad = neto_direita->sae;

        neto_direita->sae = filho_esquerda;

        (*pai)->sae = neto_direita->sad;
        neto_direita->sad = (*pai);

        if(neto_direita->fb == -1)
        {
            (*pai)->fb = 0;
            filho_esquerda->fb = 1;
        }
        else if(neto_direita->fb == 1)
        {
            (*pai)->fb = -1;
            filho_esquerda->fb = 0;
        }
        else
        {
            (*pai)->fb = 0;
            filho_esquerda->fb = 0;
        }
        neto_direita->fb = 0;
        (*pai) = neto_direita;
        return 1;
    }

    return 0;
}

int rotacao_esquerda_direita(ARVORE_AVL *pai)
{
    ARVORE_AVL filho_direita;
    ARVORE_AVL neto_esquerda;

    if(((*pai) != NULL)&&((*pai)->sad != NULL))
    {

        filho_direita = (*pai)->sad;

        neto_esquerda = filho_direita->sae;

        filho_direita->sae = neto_esquerda->sad;

        neto_esquerda->sad = filho_direita;

        (*pai)->sad = neto_esquerda->sae;
        neto_esquerda->sae = (*pai);

        if(neto_esquerda->fb == -1)
        {
            (*pai)->fb = 1;
            filho_direita->fb = 0;
        }
        else if(neto_esquerda->fb == 1)
        {
            (*pai)->fb = 0;
            filho_direita->fb = -1;
        }
        else
        {
            (*pai)->fb = 0;
            filho_direita->fb = 0;
        }
        neto_esquerda->fb = 0;
        (*pai) = neto_esquerda;
        return 1;
    }
    return 0;
}

int balancear_esquerda(ARVORE_AVL *arvore)
{
    if(((*arvore)->sae->fb) > 0)
    {
        return rotacao_direita(arvore);
    }
    else
    {
        return rotacao_direita_esquerda(arvore);
    }

}

int balancear_direita(ARVORE_AVL *arvore)
{
    if(((*arvore)->sad->fb) < 0)
    {
        return rotacao_esquerda(arvore);
    }
    else
    {
        return rotacao_esquerda_direita(arvore);
    }
}

int insere_AVL(ARVORE_AVL *arvore, REGISTRO elemento, int *verificador)
{
    if(arvore == NULL)
    {
        return 0;
    }

    NO* novo_no = (NO*) malloc(sizeof(NO));
    if(novo_no == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo no na funcao \"insere_AVL\".\n");
        return 0;
    }

    novo_no->info = elemento;
    novo_no->sae = NULL;
    novo_no->sad = NULL;
    novo_no->fb = 0;

    if((*arvore) == NULL)
    {
        (*arvore) = novo_no;
        (*verificador) = 1;
    }
    else if(elemento.trafego <= (*arvore)->info.trafego)
    {
        insere_AVL(&((*arvore)->sae), elemento, verificador);
        if((*verificador) == 1)
        {
            if((*arvore)->fb == 1)
            {
                balancear_esquerda(arvore);
                (*verificador) = 0;
            }
            else if((*arvore)->fb == 0)
            {
                (*arvore)->fb = 1;
            }
            else
            {
                (*arvore)->fb = 0;
                (*verificador) = 0;
            }
        }
    }
    else
    {
        insere_AVL(&((*arvore)->sad), elemento, verificador);
        if((*verificador) == 1)
        {
            if((*arvore)->fb == (-1))
            {
                balancear_direita(arvore);
                (*verificador) = 0;
            }
            else if((*arvore)->fb == 0)
            {
                (*arvore)->fb = (-1);
            }
            else
            {
                (*arvore)->fb = 0;
                (*verificador) = 0;
            }
        }
    }

    return 1;
}

/*Parte 3 - Trabalho 02 de AED2------------------------------------------------------------------*/

REGISTRO* menor_trafego(ARVORE_AVL arvore)
{
    int menor = (-1);
    ARVORE_AVL arvore_auxiliar, arvore_retorno;

    if(arvore == NULL)
    {
        printf("-> Erro: Arvore eh invalida na funcao \"menor_trafego\".\n");
        return NULL;
    }

    arvore_auxiliar = arvore;
    arvore_retorno = arvore;
    menor = arvore_auxiliar->info.trafego;

    while(arvore_auxiliar != NULL)
    {
        menor = arvore_auxiliar->info.trafego;
        if(arvore_retorno->info.trafego > menor)
        {
            arvore_retorno = arvore_auxiliar;
        }
        arvore_auxiliar = arvore_auxiliar->sae;
    }

    return &(arvore_retorno->info);
}

/*-----------------------------------------------------------------------------------------------*/

int qtde_ocioso(ARVORE_AVL arvore)
{
    int ocioso_esquerda = 0;
    int ocioso_direita = 0;
    int ocioso_total = 0;
    int trafego, capacidade;

    if(arvore == NULL)
    {
        return 0;
    }

    trafego = arvore->info.trafego;
    capacidade = arvore->info.capacidade;

    ocioso_esquerda = qtde_ocioso(arvore->sae);
    ocioso_direita = qtde_ocioso(arvore->sad);
    ocioso_total = ocioso_esquerda + ocioso_direita;

    if(trafego < (capacidade/2))
    {
        ocioso_total++;
    }

    return ocioso_total;
}

/*-----------------------------------------------------------------------------------------------*/

int nro_folha(ARVORE_AVL arvore)
{
    int folhas_esquerda = 0;
    int folhas_direita = 0;
    int total_folhas = 0;

    if(arvore == NULL)
    {
        return 0;
    }

    folhas_esquerda = nro_folha(arvore->sae);
    folhas_direita = nro_folha(arvore->sad);
    total_folhas = folhas_esquerda + folhas_direita;

    if((arvore->sae == NULL)&&(arvore->sad == NULL))
    {
        total_folhas++;
    }

    return total_folhas;
}

/*-----------------------------------------------------------------------------------------------*/
int altura_arvore_avl(ARVORE_AVL arvore)
{
    int altura_esquerda = 0;
    int altura_direita = 0;

    if(arvore == NULL)
    {
        return (-1);
    }

    altura_esquerda = altura_arvore_avl(arvore->sae);
    altura_direita = altura_arvore_avl(arvore->sad);

    if(altura_esquerda > altura_direita)
    {
        return (altura_esquerda + 1);
    }
    else
    {
        return (altura_direita + 1);
    }
}

int quantidade_nos_arvore_avl(ARVORE_AVL arvore)
{
    int nos_esquerda = 0;
    int nos_direita = 0;
    int total_nos = 0;

    if(arvore == NULL)
    {
        return 0;
    }

    nos_esquerda = quantidade_nos_arvore_avl(arvore->sae);
    nos_direita = quantidade_nos_arvore_avl(arvore->sad);
    total_nos = nos_esquerda + nos_direita + 1;

    return total_nos;
}

int cheia(ARVORE_AVL arvore)
{
    int altura;
    int numero_nos;
    int maximo_nos;

    if(arvore == NULL)
    {
        return 0;
    }

    altura = altura_arvore_avl(arvore);
    numero_nos = quantidade_nos_arvore_avl(arvore);

    maximo_nos = pow(2,(altura+1)) - 1;

    if(numero_nos == maximo_nos)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/*-----------------------------------------------------------------------------------------------*/

int nivel_no(ARVORE_AVL arvore, REGISTRO elemento)
{
    int nivel_retorno = 0;
    if(arvore == NULL)
    {
        return (-1);
    }

    if(elemento.trafego == arvore->info.trafego)
    {
        return 0;
    }
    else if(elemento.trafego < arvore->info.trafego)
    {
        nivel_retorno = nivel_no(arvore->sae, elemento);
    }
    else
    {
        nivel_retorno = nivel_no(arvore->sad, elemento);
    }

    if(nivel_retorno == (-1))
    {
        return (-1);
    }
    else
    {
        nivel_retorno++;
        return nivel_retorno;
    }
}

/*-----------------------------------------------------------------------------------------------*/

int iguais(ARVORE_AVL arvore1, ARVORE_AVL arvore2)
{
    int iguais_esquerda = 0;
    int iguais_direita = 0;
    int raizes_iguais = 0;
    int iguais_retorno = 0;

    if((arvore1 == NULL)&&(arvore2 == NULL))
    {
        return 1;
    }
    if((arvore1 != NULL)&&(arvore2 == NULL))
    {
        return 0;
    }
    if((arvore1 == NULL)&&(arvore2 != NULL))
    {
        return 0;
    }

    iguais_esquerda = iguais(arvore1->sae, arvore2->sae);
    iguais_direita = iguais(arvore1->sad, arvore2->sad);

    if(arvore1->info.trafego == arvore2->info.trafego)
    {
        raizes_iguais = 1;
    }

    if((iguais_esquerda == 1)&&(iguais_direita == 1)&&(raizes_iguais == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*-----------------------------------------------------------------------------------------------*/

void imprime_cabecalho_1()
{
    printf("#------------------------------- Parte 3 - Arvore AVL ------------------------------------#\n");
    printf("|-----------------------------------------------------------------------------------------|\n");
    printf("|Operacoes Disponiveis:-------------------------------------------------------------------|\n");
    printf("|1 - Ponto de Rede com Menor Trafego                                                      |\n");
    printf("|2 - Quantidade de Pontos de Rede Utilizando Menos da Metade da Capacidade                |\n");
    printf("|3 - Quantidade de Nos Folha                                                              |\n");
    printf("|4 - Verifica se a Arvore eh Cheia                                                        |\n");
    printf("|5 - Calcula a Profundidade de Determinado No                                             |\n");
    printf("|6 - Verifica se duas Arvores sao Iguais                                                  |\n");
    printf("|7 - Sair                                                                                 |\n");
    printf("#-----------------------------------------------------------------------------------------#\n\n");
}

void imprime_cabecalho_2()
{
    printf("#------------------------------- Parte 3 - Arvore AVL ------------------------------------#\n");
    printf("|-----------------------------------------------------------------------------------------|\n");
    printf("|Operacoes Disponiveis:-------------------------------------------------------------------|\n");
    printf("|1 - Inserir Elemento                                                                     |\n");
    printf("|2 - Remover Elemento                                                                     |\n");
    printf("|3 - Ponto de Rede com Menor Trafego                                                      |\n");
    printf("|4 - Quantidade de Pontos de Rede Utilizando Menos da Metade da Capacidade                |\n");
    printf("|5 - Quantidade de Nos Folha                                                              |\n");
    printf("|6 - Verifica se a Arvore eh Cheia                                                        |\n");
    printf("|7 - Calcula a Profundidade de Determinado No                                             |\n");
    printf("|8 - Sair                                                                                 |\n");
    printf("#-----------------------------------------------------------------------------------------#\n\n");
}
