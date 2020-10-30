/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_bb.h"

/*Definicao de Funcoes*/
ARVORE_BB cria_arvore_bb()
{
    return NULL;
}

int arvore_bb_vazia(ARVORE_BB *arvore)
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

void libera_arvore_bb(ARVORE_BB *arvore)
{
    if((*arvore) != NULL)
    {
        libera_arvore_bb(&((*arvore)->sae));
        libera_arvore_bb(&((*arvore)->sad));
        free(*arvore);
    }

    *arvore = NULL;
}

void exibe_arvore_bb(ARVORE_BB arvore)
{
    if(arvore == NULL)
    {
        printf("<>");
    }
    else
    {
        printf("<");
        printf("%d", arvore->info.idade);
        exibe_arvore_bb(arvore->sae);
        exibe_arvore_bb(arvore->sad);
        printf(">");
    }
}

void exibe_ordenado_arvore_bb(ARVORE_BB arvore)
{
    if(arvore != NULL)
    {
        exibe_ordenado_arvore_bb(arvore->sae);
        printf("%d ", arvore->info.idade);
        exibe_ordenado_arvore_bb(arvore->sad);
    }
}

int insere_ordenado_arvore_bb(ARVORE_BB *arvore, REGISTRO elemento)
{
    if(arvore == NULL)
    {
        printf("-> Erro: Arvore recebida de parametro na funcao \"insere_ordenado_arvore_bb\" eh invalida.\n");
        return 0;
    }

    if(arvore_bb_vazia(arvore))
    {
        NO* novo_no = (NO*) malloc(sizeof(NO));
        if(novo_no == NULL)
        {
            printf("-> Erro: Falha na alocacao do novo no na funcao \"insere_ordenado_arvore_bb\".\n");
            return 0;
        }

        novo_no->info = elemento;
        novo_no->sae = NULL;
        novo_no->sad = NULL;
        (*arvore) = novo_no;
        return 1;
    }

    if(elemento.idade > (*arvore)->info.idade)
    {
        return insere_ordenado_arvore_bb(&((*arvore)->sad), elemento);
    }
    else
    {
        return insere_ordenado_arvore_bb(&((*arvore)->sae), elemento);
    }
}

int remove_ordenado_arvore_bb(ARVORE_BB *arvore, int idade)
{
    REGISTRO temporario;
    ARVORE_BB auxiliar;

    if((arvore == NULL)||(arvore_bb_vazia(arvore)))
    {
        return 0;
    }

    if(idade > (*arvore)->info.idade)
    {
        return remove_ordenado_arvore_bb(&((*arvore)->sad), idade);
    }
    else if(idade < (*arvore)->info.idade)
    {
        return remove_ordenado_arvore_bb(&((*arvore)->sae), idade);
    }
    else
    {
        if(((*arvore)->sae == NULL)&&((*arvore)->sad == NULL))
        {
            free(*arvore);
            *arvore = NULL;
            return 1;
        }
        else if(((*arvore)->sae != NULL)&&((*arvore)->sad == NULL))
        {
            auxiliar = (*arvore);
            *arvore = (*arvore)->sae;
            free(auxiliar);
            return 1;
        }
        else if(((*arvore)->sae == NULL)&&((*arvore)->sad != NULL))
        {
            auxiliar = (*arvore);
            *arvore = (*arvore)->sad;
            free(auxiliar);
            return 1;
        }
        else
        {
            auxiliar = (*arvore)->sae;
            while(auxiliar->sad != NULL)
            {
                auxiliar = auxiliar->sad;
            }

            temporario = (*arvore)->info;
            (*arvore)->info = auxiliar->info;
            auxiliar->info = temporario;

            return remove_ordenado_arvore_bb(&((*arvore)->sae), idade);
        }
    }
}

ARVORE_BB busca_binaria_arvore_bb(ARVORE_BB arvore, int idade)
{
    if(arvore == NULL)
    {
        printf("-> Nao existe o elemento procurado com essa chave.\n");
        return NULL;
    }

    if(arvore->info.idade == idade)
    {
        return arvore;
    }
    else if(idade > arvore->info.idade)
    {
        return busca_binaria_arvore_bb(arvore->sad, idade);
    }
    else
    {
        return busca_binaria_arvore_bb(arvore->sae, idade);
    }
}

void imprime_arvore_bb(ARVORE_BB arvore)
{
    printf("Arvore Binaria de Busca:------------------------\n");
    exibe_arvore_bb(arvore);
    printf("\n------------------------------------------------\n\n");
}

void imprime_ordenado_arvore_bb(ARVORE_BB arvore)
{
    printf("Arvore Binaria de Busca Ordenada:---------------\n");
    exibe_ordenado_arvore_bb(arvore);
    printf("\n------------------------------------------------\n\n");
}

/*Parte 2 Trabalho 02 de AED2--------------------------------------------------------------------*/

REGISTRO* maior(ARVORE_BB arvore)
{
    int maior_idade;
    ARVORE_BB arvore_auxiliar, arvore_retorno;

    if(arvore == NULL)
    {
        printf("-> Erro: Arvore eh invalida na funcao \"maior\".\n");
        return NULL;
    }

    arvore_auxiliar = arvore;
    arvore_retorno = arvore;
    maior_idade = arvore_auxiliar->info.idade;

    while(arvore_auxiliar != NULL)
    {
        maior_idade = arvore_auxiliar->info.idade;
        if(arvore_retorno->info.idade < maior_idade)
        {
            arvore_retorno = arvore_auxiliar;
        }
        arvore_auxiliar = arvore_auxiliar->sad;
    }

    return &(arvore_retorno->info);
}

/*-----------------------------------------------------------------------------------------------*/

int de_maior(ARVORE_BB arvore)
{
    int total_maiores_de_idade = 0;
    int maiores_esquerda = 0;
    int maiores_direita = 0;

    if(arvore == NULL)
    {
        return 0;
    }

    maiores_esquerda = de_maior(arvore->sae);
    maiores_direita = de_maior(arvore->sad);
    total_maiores_de_idade = maiores_esquerda + maiores_direita;

    if(arvore->info.idade >= 18)
    {
        total_maiores_de_idade++;
    }

    return total_maiores_de_idade;
}

/*-----------------------------------------------------------------------------------------------*/

int qtde_nos_abb(ARVORE_BB arvore, int ini, int fim)
{
    int total_alunos = 0;
    int alunos_esquerda = 0;
    int alunos_direita = 0;

    if(arvore == NULL)
    {
        return 0;
    }

    alunos_esquerda = qtde_nos_abb(arvore->sae, ini, fim);
    alunos_direita = qtde_nos_abb(arvore->sad, ini, fim);
    total_alunos = alunos_esquerda + alunos_direita;

    if((arvore->info.idade >= ini)&&(arvore->info.idade <= fim))
    {
        total_alunos++;
    }

    return total_alunos;
}

/*-----------------------------------------------------------------------------------------------*/

int um_filho(ARVORE_BB arvore)
{
    int total_um_filho = 0;
    int um_filho_esquerda = 0;
    int um_filho_direita = 0;

    if(arvore == NULL)
    {
        return 0;
    }

    um_filho_esquerda = um_filho(arvore->sae);
    um_filho_direita = um_filho(arvore->sad);
    total_um_filho = um_filho_esquerda + um_filho_direita;

    if((arvore->sae == NULL)&&(arvore->sad != NULL))
    {
        total_um_filho++;
    }
    else if((arvore->sae != NULL)&&(arvore->sad == NULL))
    {
        total_um_filho++;
    }

    return total_um_filho;
}

/*-----------------------------------------------------------------------------------------------*/

int verifica_numero_filhos(ARVORE_BB arvore)
{
    int filhos_esquerda = 0;
    int filhos_direita = 0;
    int raiz_auxiliar = 0;
    int retorno_filhos = 0;

    if(arvore == NULL)
    {
        return 1;/*Esquerda e direita de um no folha precisa resultar em 1*/
    }

    filhos_esquerda = verifica_numero_filhos(arvore->sae);
    filhos_direita = verifica_numero_filhos(arvore->sad);

    if((arvore->sae != NULL)&&(arvore->sad != NULL))
    {
        raiz_auxiliar = 1;
    }
    else if((arvore->sae == NULL)&&(arvore->sad == NULL))
    {
        raiz_auxiliar = 1;
    }

    if((filhos_esquerda == 1)&&(filhos_direita == 1)&&(raiz_auxiliar == 1))
    {
        retorno_filhos = 1;
    }

    return retorno_filhos;
}

int completa(ARVORE_BB arvore)
{
    int controle = 0;

    controle = verifica_numero_filhos(arvore);
    if(controle == 0)
    {
        return 0;
    }

    return 1;
}

/*-----------------------------------------------------------------------------------------------*/

int altura_arv(ARVORE_BB arvore)
{
    int altura_total = 0;
    int altura_esquerda = 0;
    int altura_direita = 0;

    if(arvore == NULL)
    {
        return (-1);
    }

    altura_esquerda = altura_arv(arvore->sae);
    altura_direita = altura_arv(arvore->sad);

    if(altura_esquerda > altura_direita)
    {
        altura_total = altura_esquerda + 1;
    }
    else
    {
        altura_total = altura_direita + 1;
    }

    return altura_total;
}

/*-----------------------------------------------------------------------------------------------*/

void juntar_auxiliar(ARVORE_BB *arvore1, ARVORE_BB arvore2)
{
    if((arvore1 == NULL)||(arvore2 == NULL))
    {
        return;
    }
    insere_ordenado_arvore_bb(arvore1, arvore2->info);
    juntar_auxiliar(arvore1, arvore2->sae);
    juntar_auxiliar(arvore1, arvore2->sad);
}

ARVORE_BB juntar(ARVORE_BB arvore1, ARVORE_BB arvore2)
{
    ARVORE_BB arvore_retorno;

    arvore_retorno = cria_arvore_bb();

    if((arvore1 == NULL)&&(arvore2 == NULL))
    {
        printf("-> Erro: Arvore invalidas na funcao \"juntar\".\n");
        return NULL;
    }
    if((arvore1 != NULL)&&(arvore2 == NULL))
    {
        return arvore1;
    }
    if((arvore1 == NULL)&&(arvore2 != NULL))
    {
        return arvore2;
    }

    juntar_auxiliar(&arvore_retorno, arvore1);
    juntar_auxiliar(&arvore_retorno, arvore2);

    return arvore_retorno;
}

/*-----------------------------------------------------------------------------------------------*/

void imprime_cabecalho_1()
{
    printf("#------------------------ Parte 2 - Arvore Binaria de Busca ------------------------------#\n");
    printf("|-----------------------------------------------------------------------------------------|\n");
    printf("|Operacoes Disponiveis:-------------------------------------------------------------------|\n");
    printf("|1 - Aluno Mais Velho                                                                     |\n");
    printf("|2 - Quantidade de Alunos Maiores de Idade                                                |\n");
    printf("|3 - Quantidade de Alunos Dentro de um Determinado Intervalo de Idade                     |\n");
    printf("|4 - Quantidade de Nos que Possuem Somente um Filho                                       |\n");
    printf("|5 - Verificar se a Arvore eh Completa                                                    |\n");
    printf("|6 - Altura Da Arvore                                                                     |\n");
    printf("|7 - Intercalar Duas Arvores                                                              |\n");
    printf("|8 - Sair                                                                                 |\n");
    printf("#-----------------------------------------------------------------------------------------#\n\n");
}

void imprime_cabecalho_2()
{
    printf("#------------------------ Parte 2 - Arvore Binaria de Busca ------------------------------#\n");
    printf("|-----------------------------------------------------------------------------------------|\n");
    printf("|Operacoes Disponiveis:-------------------------------------------------------------------|\n");
    printf("|1 - Inserir Elemento                                                                     |\n");
    printf("|2 - Remover Elemento                                                                     |\n");
    printf("|3 - Aluno Mais Velho                                                                     |\n");
    printf("|4 - Quantidade de Alunos Maiores de Idade                                                |\n");
    printf("|5 - Quantidade de Alunos Dentro de um Determinado Intervalo de Idade                     |\n");
    printf("|6 - Quantidade de Nos que Possuem Somente um Filho                                       |\n");
    printf("|7 - Verificar se a Arvore eh Completa                                                    |\n");
    printf("|8 - Altura Da Arvore                                                                     |\n");
    printf("|9 - Sair                                                                                 |\n");
    printf("#-----------------------------------------------------------------------------------------#\n\n");
}
